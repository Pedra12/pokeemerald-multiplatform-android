LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 8, 4
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 4, 5
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 9, 8
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

/* Many of the below scripts have no gender check because they assume youre in the correct house*/
/* The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro*/
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.short 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_PLAYERS_HOUSE_1F_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "MaE: Viu, {PLAYER}?\n"
	.string "Nao é legal aqui também?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "Os POKéMON fazem todo o trabalho\n"
	.string "de mover a gente e limpar tudo depois.\l"
	.string "Isso é tao conveniente!\p"
	.string "{PLAYER}, seu quarto é lá em cima.\n"
	.string "Vai lá dar uma olhada, querido!\p"
	.string "O seu PAI comprou um relógio novo\n"
	.string "pra marcar a nossa mudança pra cá.\l"
	.string "Nao se esqueça de arrumar a hora dele!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "MaE: Ué, {PLAYER}?\p"
	.string "Nao tá interessado em ver seu\n"
	.string "próprio quarto?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "MaE: {PLAYER}.\p"
	.string "Vai lá arrumar o relógio, querido.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "MaE: Ah! {PLAYER}, {PLAYER}!\n"
	.string "Rápido! Vem cá!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "MaE: Olha! É o GINáSIO DE PETALBURG!\n"
	.string "Talvez seu PAI esteja lá!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "MaE: Ah… acabou.\p"
	.string "Acho que seu PAI estava passando, mas perdemos.\n"
	.string "Que pena.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "Ah, sim.\n"
	.string "Um dos amigos do seu PAI vive na vila.\p"
	.string "PROF. BIRCH é o nome dele.\p"
	.string "Ele mora ali do lado, entao você\n"
	.string "deveria ir e se apresentar pra ele.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "MaE: Te vejo mais tarde, querido!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "MaE: Você se apresentou pro\n"
	.string "PROF. BIRCH?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "MaE: Como você está, {PLAYER}?\n"
	.string "Você parece um pouco cansado.\p"
	.string "Eu acho que você devia descansar.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "MaE: Tome cuidado, querido!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "MaE: Eh? O seu PAI te deu essa INSíGNIA?\p"
	.string "Entao aqui está algo da sua MaE!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Nao se force tanto, querido.\n"
	.string "Você pode sempre voltar pra casa.\p"
	.string "Agora vai lá, querido!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MaE: O que e isso, querido? Um POKéNAV?\n"
	.string "Alguem da DEVON deu isso a voce?\p"
	.string "Entao, querido, que tal registrar\n"
	.string "sua mae?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "MaE registrada\n"
	.string "no POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "REPÓRTER: …Trazemos esta reportagem\n"
	.string "diretamente da frente do GINASIO DE PETALBURG.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "Esta passando um filme na TV.\p"
	.string "Dois homens estao dancando em um enorme\n"
	.string "teclado de piano.\p"
	.string "Melhor ir andando!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "E o manual de instrucoes dos\n"
	.string "TENIS DE CORRIDA.\p"
	.string "“Aperte o botao B para correr enquanto\n"
	.string "estiver usando seus TENIS DE CORRIDA.\p"
	.string "“Amarre seus TENIS DE CORRIDA e\n"
	.string "saia correndo por ai!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "PAI: Hm?\p"
	.string "Ei, e o {PLAYER}!\p"
	.string "Faz tempo que nao vejo voce,\n"
	.string "mas voce parece… mais forte.\p"
	.string "Essa e a impressao que tenho.\n"
	.string "Mas seu velho ainda nao desistiu!\p"
	.string "Ah, sim, tenho algo para voce.\n"
	.string "Isto chegou para voce, enviado por alguem\l"
	.string "chamado SR. BRINEY.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "PAI: Hm, uma PASSAGEM de balsa?\p"
	.string "Se me lembro bem, ha portos de balsa em\n"
	.string "SLATEPORT e LILYCOVE.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "E melhor eu voltar ao GINASIO DE PETALBURG.\p"
	.string "MaE, obrigado por cuidar da casa\n"
	.string "enquanto estou fora.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "MaE: Esse seu PAI…\p"
	.string "Ele volta para casa pela primeira vez em\n"
	.string "um bom tempo, mas so fala de POKéMON.\p"
	.string "Ele devia descansar e ficar mais um pouco.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MaE: Isso e uma noticia urgente?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "Interrompemos a programacao para\n"
	.string "uma noticia urgente!\p"
	.string "Em varias regioes de HOENN, foram\n"
	.string "relatados avistamentos de um POKéMON\l"
	.string "voador de cor BZZT…\p"
	.string "A identidade desse POKéMON ainda\n"
	.string "e desconhecida.\p"
	.string "Voltamos agora a\n"
	.string "programacao normal.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MaE: {PLAYER}, voce ouviu isso?\p"
	.string "Que cor o apresentador disse\n"
	.string "que era aquele POKéMON?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MaE: Mas que coisa interessante!\n"
	.string "Ainda existem POKéMON desconhecidos.$"
