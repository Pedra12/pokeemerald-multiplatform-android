cmake_minimum_required(VERSION 3.22)
project(pokeemerald_android C ASM)

set(ROOT "${CMAKE_CURRENT_LIST_DIR}/../../../../..")
get_filename_component(ROOT "${ROOT}" ABSOLUTE)

set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_SHARED ON CACHE BOOL "" FORCE)
set(SDL_TEST OFF CACHE BOOL "" FORCE)
add_subdirectory("${ROOT}/android/SDL2" "${CMAKE_BINARY_DIR}/SDL2")

# Compile the portable game C sources with the Android NDK compiler.
file(GLOB_RECURSE GAME_C CONFIGURE_DEPENDS
    "${ROOT}/src/*.c"
    "${ROOT}/gflib/*.c")
list(FILTER GAME_C EXCLUDE REGEX "\\.inc\\.c$")

set(GENERATED_C)
foreach(SOURCE IN LISTS GAME_C)
    file(RELATIVE_PATH RELATIVE_SOURCE "${ROOT}" "${SOURCE}")
    set(OUTPUT "${CMAKE_BINARY_DIR}/generated/${RELATIVE_SOURCE}")
    get_filename_component(OUTPUT_DIR "${OUTPUT}" DIRECTORY)
    add_custom_command(
        OUTPUT "${OUTPUT}"
        COMMAND "${CMAKE_COMMAND}" -E make_directory "${OUTPUT_DIR}"
        COMMAND /bin/sh -c "cd '${ROOT}' && '${CMAKE_C_COMPILER}' --target=${CMAKE_C_COMPILER_TARGET} --sysroot='${CMAKE_SYSROOT}' -E -std=gnu99 -iquote'${ROOT}/include' -iquote'${ROOT}/gflib' -I'${ROOT}/android/SDL2/include' -DNONMATCHING -DPORTABLE -DPLATFORM_SDL2 -DRENDERER_EASY_DRAW -DMODERN=1 -DUBFIX '${SOURCE}' -o '${OUTPUT}.i' && '${ROOT}/tools/preproc/preproc' '${OUTPUT}.i' '${ROOT}/charmap.txt' > '${OUTPUT}'"
        DEPENDS "${SOURCE}" "${ROOT}/tools/preproc/preproc" "${ROOT}/charmap.txt"
        VERBATIM)
    list(APPEND GENERATED_C "${OUTPUT}")
endforeach()

# Reuse the upstream Makefile for maps, MIDI conversion, song assembly and fixups.
find_program(GNU_MAKE make REQUIRED)

file(GLOB GAME_ASM CONFIGURE_DEPENDS
    "${ROOT}/asm/*.s"
    "${ROOT}/data/*.s"
    "${ROOT}/sound/songs/*.s")
file(GLOB MIDI_FILES CONFIGURE_DEPENDS "${ROOT}/sound/songs/midi/*.mid")

set(MAKE_ASM_TARGETS)
set(MAKE_ASM_OBJECTS)
foreach(SOURCE IN LISTS GAME_ASM)
    file(RELATIVE_PATH RELATIVE_SOURCE "${ROOT}" "${SOURCE}")
    string(REGEX REPLACE "\\.s$" ".o" OBJECT_RELATIVE "${RELATIVE_SOURCE}")
    list(APPEND MAKE_ASM_TARGETS "build/modern/${OBJECT_RELATIVE}")
    list(APPEND MAKE_ASM_OBJECTS "${ROOT}/build/modern/${OBJECT_RELATIVE}")
endforeach()
foreach(SOURCE IN LISTS MIDI_FILES)
    file(RELATIVE_PATH RELATIVE_SOURCE "${ROOT}" "${SOURCE}")
    string(REGEX REPLACE "\\.mid$" ".o" OBJECT_RELATIVE "${RELATIVE_SOURCE}")
    list(APPEND MAKE_ASM_TARGETS "build/modern/${OBJECT_RELATIVE}")
    list(APPEND MAKE_ASM_OBJECTS "${ROOT}/build/modern/${OBJECT_RELATIVE}")
endforeach()

if(NOT MAKE_ASM_TARGETS)
    message(FATAL_ERROR "No game assembly or MIDI sources were found.")
endif()

execute_process(
    COMMAND "${GNU_MAKE}" -j2 MODERN=1 NODEP=1 SETUP_PREREQS=0 ${MAKE_ASM_TARGETS}
    WORKING_DIRECTORY "${ROOT}"
    RESULT_VARIABLE MAKE_ASM_RESULT
    COMMAND_ECHO STDOUT)
if(NOT MAKE_ASM_RESULT EQUAL 0)
    message(FATAL_ERROR "The upstream Makefile failed to build game assembly/MIDI objects (exit ${MAKE_ASM_RESULT}).")
endif()

foreach(OBJECT IN LISTS MAKE_ASM_OBJECTS)
    if(NOT EXISTS "${OBJECT}")
        message(FATAL_ERROR "Expected game object was not generated: ${OBJECT}")
    endif()
endforeach()
# Match the upstream Android port: merge game assembly objects and move
# read-only data into a writable section so Android can apply ARM relocations.
find_program(ARM_NONE_EABI_LD arm-none-eabi-ld
    HINTS "$ENV{ARM_NONE_EABI_TOOLCHAIN}/bin"
    REQUIRED)
find_program(ARM_NONE_EABI_OBJCOPY arm-none-eabi-objcopy
    HINTS "$ENV{ARM_NONE_EABI_TOOLCHAIN}/bin"
    REQUIRED)

# Localize each special-script index explicitly after the relocatable merge.
# Explicit symbol names avoid relying on objcopy wildcard matching.
file(STRINGS "${ROOT}/data/specials.inc" SPECIAL_LINES
    REGEX "^[ \t]*def_special[ \t]+")
set(SPECIAL_LOCALIZE_ARGS)
foreach(LINE IN LISTS SPECIAL_LINES)
    string(REGEX MATCH "def_special[ \t]+([A-Za-z0-9_]+)" _ "${LINE}")
    if(CMAKE_MATCH_1)
        list(APPEND SPECIAL_LOCALIZE_ARGS "--localize-symbol=SPECIAL_${CMAKE_MATCH_1}")
    endif()
endforeach()
find_program(ARM_NONE_EABI_NM arm-none-eabi-nm
    HINTS "$ENV{ARM_NONE_EABI_TOOLCHAIN}/bin"
    REQUIRED)

set(GAME_DATA_OBJECT "${CMAKE_BINARY_DIR}/generated/game_data.o")
add_custom_command(
    OUTPUT "${GAME_DATA_OBJECT}"
    COMMAND "${CMAKE_COMMAND}" -E make_directory "${CMAKE_BINARY_DIR}/generated"
    COMMAND "${ARM_NONE_EABI_LD}" -r -o "${GAME_DATA_OBJECT}.tmp" ${MAKE_ASM_OBJECTS}
    COMMAND "${ARM_NONE_EABI_OBJCOPY}" ${SPECIAL_LOCALIZE_ARGS} --rename-section .rodata=.data,alloc,load,data,contents "${GAME_DATA_OBJECT}.tmp" "${GAME_DATA_OBJECT}"
    COMMAND /bin/sh -c "'${ARM_NONE_EABI_NM}' -g '${GAME_DATA_OBJECT}' | grep SPECIAL_ || true"
    DEPENDS ${MAKE_ASM_OBJECTS}
    VERBATIM)
set_source_files_properties("${GAME_DATA_OBJECT}"
    PROPERTIES GENERATED TRUE EXTERNAL_OBJECT TRUE)

add_library(main SHARED ${GENERATED_C} "${GAME_DATA_OBJECT}")
target_include_directories(main PRIVATE
    "${ROOT}"
    "${ROOT}/sound"
    "${ROOT}/android/SDL2/include")
target_compile_definitions(main PRIVATE
    NONMATCHING PORTABLE PLATFORM_SDL2 RENDERER_EASY_DRAW MODERN=1 UBFIX)
target_compile_options(main PRIVATE
    -O3
    -fno-builtin
    -Wno-implicit-function-declaration
    "SHELL:-iquote '${ROOT}/include'"
    "SHELL:-iquote '${ROOT}/gflib'")
target_link_libraries(main PRIVATE SDL2::SDL2 m)
