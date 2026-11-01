FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "Ninguém acredita em mim, mas vi este\n"
	.string "POKéMON gigantesco no céu.\p"
	.string "Ele parecia se contorcer enquanto voava em direçao à\n"
	.string "ROTA 131.\p"
	.string "A propósito… Snif…\n"
	.string "Hum… Você está com cheiro de queimado.\p"
	.string "Você esteve em um vulcao ou algo assim?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "Quero ir ao GINÁSIO POKéMON,\n"
	.string "mas algo está bloqueando o caminho.\p"
	.string "Depois de todo o esforço que fiz\n"
	.string "treinando na ROTA 120…$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "Estou com meu POKéMON favorito\n"
	.string "comigo. Desta vez, vou derrotar WINONA.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "O solo absorve a água da chuva, e\n"
	.string "as árvores crescem bebendo essa água…\p"
	.string "Nossa CIDADE DE FORTREE existe porque\n"
	.string "há água e solo por aqui.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "A CIDADE é formada por casas construídas\n"
	.string "sobre as árvores.\p"
	.string "Talvez por causa desse estilo de vida,\n"
	.string "todos sejam saudáveis e cheios de energia.\p"
	.string "Até eu mesmo me sinto como se tivesse\n"
	.string "rejuvenescido trinta anos.$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "Morar no alto das árvores é bom.\p"
	.string "Mas às vezes POKéMON INSETOS entram\n"
	.string "pelas janelas.\l"
	.string "Isso pode assustar bastante.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "Existem POKéMON que evoluem quando\n"
	.string "sao trocados! Foi o que ouvi.$"

FortreeCity_Text_SomethingUnseeable:
	.string "Algo invisível está bloqueando o caminho.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Algo invisível está bloqueando o caminho.\p"
	.string "Quer usar o DEVON SCOPE?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} usou o DEVON SCOPE.\p"
	.string "Um POKéMON invisível ficou completamente\n"
	.string "visível!\p"
	.string "O POKéMON assustado fugiu!$"

FortreeCity_Text_CitySign:
	.string "CIDADE DE FORTREE\n"
	.string "“A cidade nas copas das árvores que brinca com\l"
	.string "a natureza.”$"

FortreeCity_Text_GymSign:
	.string "GINÁSIO POKéMON DA CIDADE DE FORTREE\n"
	.string "LÍDER: WINONA\p"
	.string "“A treinadora de pássaros que alça voo\n"
	.string "pelo mundo.”$"

