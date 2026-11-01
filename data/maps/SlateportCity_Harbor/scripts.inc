SlateportCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
	.byte 0

SlateportCity_Harbor_OnTransition:
	setescapewarp MAP_SLATEPORT_CITY, 28, 13
	setvar VAR_TEMP_1, 0
	call_if_eq VAR_SLATEPORT_HARBOR_STATE, 1, SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
	end

SlateportCity_Harbor_EventScript_ShowSSTidal::
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	return

SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene::
	savebgm MUS_ENCOUNTER_AQUA
	setobjectxyperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN, 12, 13
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_LEFT
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	return

SlateportCity_Harbor_EventScript_AquaEscapeTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger3::
	lockall
	setvar VAR_0x8008, 3
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_PlayerWalkUp
	waitmovement 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeScene::
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SLATEPORT_HARBOR_SUBMARINE, SlateportCity_Harbor_Movement_SubmarineExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_HARBOR_GRUNT
	removeobject LOCALID_SLATEPORT_HARBOR_ARCHIE
	removeobject LOCALID_SLATEPORT_HARBOR_SUBMARINE
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	setflag FLAG_MET_TEAM_AQUA_HARBOR
	setflag FLAG_HIDE_LILYCOVE_MOTEL_SCOTT
	call_if_eq VAR_0x8008, 0, SlateportCity_Harbor_EventScript_SternApproachPlayer0
	call_if_eq VAR_0x8008, 1, SlateportCity_Harbor_EventScript_SternApproachPlayer1
	call_if_eq VAR_0x8008, 2, SlateportCity_Harbor_EventScript_SternApproachPlayer
	call_if_eq VAR_0x8008, 3, SlateportCity_Harbor_EventScript_SternApproachPlayer
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
	copyobjectxytoperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_RIGHT
	releaseall
	end

SlateportCity_Harbor_EventScript_SternApproachPlayer0::
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer1::
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer::
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_Movement_AquaBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

/* Unused, Archie instead shares above identical movement script with Grunt*/
SlateportCity_Harbor_Movement_ArchieBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_SubmarineExit:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer1:
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer:
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Harbor_Movement_PlayerWalkUp:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_FerryAttendant::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskForTicket::
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_ChooseDestination::
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier::
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

/* Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket*/
SlateportCity_Harbor_EventScript_NoTicket::
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_Lilycove::
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_BattleFrontier::
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_ChooseNewDestination::
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_BoardFerry::
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	call_if_eq VAR_FACING, DIR_NORTH, SlateportCity_Harbor_EventScript_BoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_Harbor_EventScript_BoardFerryEast
	delay 30
	hideobjectat LOCALID_PLAYER, 0
	setvar VAR_0x8004, LOCALID_SLATEPORT_HARBOR_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_CancelDestinationSelect::
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_BoardFerryEast::
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_BoardFerryNorth::
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
	waitmovement 0
	return

SlateportCity_Harbor_Movement_BoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

SlateportCity_Harbor_Movement_BoardFerryNorth:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	goto_if_eq VAR_0x8004, 2, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather  /* Defeated both*/
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather::
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CountDefeatedLegendary::
	addvar VAR_0x8004, 1
	return

SlateportCity_Harbor_EventScript_FatMan::
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
	end

SlateportCity_Harbor_EventScript_CaptStern::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_NeedDive
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive
	goto_if_eq VAR_SLATEPORT_HARBOR_STATE, 2, SlateportCity_Harbor_EventScript_WhyStealSubmarine
	msgbox SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Harbor_EventScript_WhyStealSubmarine::
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive::
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
	msgbox SlateportCity_Harbor_Text_TeamAquaLeftNeedDive, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_NeedDive::
	msgbox SlateportCity_Harbor_Text_NeedDiveToCatchSub, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment::
	goto_if_eq VAR_TEMP_1, 1, SlateportCity_Harbor_EventScript_TradedScanner
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Harbor_EventScript_AskToTradeScanner
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_FerryFinished
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_FerryFinished::
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskToTradeScanner::
	message SlateportCity_Harbor_Text_WouldYouTradeScanner
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_ChooseScannerTrade::
	multichoice 0, 0, MULTI_STERN_DEEPSEA, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_DeepSeaTooth
	case 1, SlateportCity_Harbor_EventScript_DeepSeaScale
	case 2, SlateportCity_Harbor_EventScript_DeclineTrade
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_DeclineTrade
	end

SlateportCity_Harbor_EventScript_DeepSeaTooth::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_TOOTH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeepSeaScale::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_SCALE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeclineTrade::
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_ChooseDifferentTrade::
	message SlateportCity_Harbor_Text_WhichOneDoYouWant
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_TradedScanner::
	setvar VAR_TEMP_1, 1
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_Text_FerryServiceUnavailable:
	.string "Como?\n"
	.string "Esta procurando um navio?\p"
	.string "Sinto muito, o servico de balsa nao esta\n"
	.string "disponivel no momento...$"

SlateportCity_Harbor_Text_MayISeeYourTicket:
	.string "Ola, veio pegar a balsa?\n"
	.string "Posso ver sua PASSAGEM?$"

SlateportCity_Harbor_Text_YouMustHaveTicket:
	.string "{PLAYER} nao tem a PASSAGEM...\p"
	.string "Sinto muito.\p"
	.string "Voce precisa de uma PASSAGEM para embarcar\n"
	.string "na balsa.$"

SlateportCity_Harbor_Text_FlashedTicketWhereTo:
	.string "{PLAYER} mostrou a PASSAGEM.\p"
	.string "Perfeito! E so disso que precisa!\p"
	.string "E para onde gostaria de ir?$"

SlateportCity_Harbor_Text_SailAnotherTime:
	.string "Volte a navegar conosco em outra ocasiao!$"

SlateportCity_Harbor_Text_LilycoveItIs:
	.string "Entao vamos para CIDADE DE LILYCOVE!$"

SlateportCity_Harbor_Text_BattleFrontierItIs:
	.string "Entao vamos para a FRONTEIRA DE BATALHA!$"

SlateportCity_Harbor_Text_PleaseBoardFerry:
	.string "Embarque na balsa e aguarde a\n"
	.string "partida.$"

SlateportCity_Harbor_Text_WhereWouldYouLikeToGo:
	.string "Entao, para onde gostaria de ir?$"

SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday:
	.string "Uma viagem ao fundo do mar...\n"
	.string "Como sera que e?\p"
	.string "Eu adoraria mergulhar em aguas profundas\n"
	.string "assim algum dia.$"

SlateportCity_Harbor_Text_AbnormalWeather:
	.string "Para um navio navegar com seguranca, precisamos\n"
	.string "conhecer as condicoes do tempo!\p"
	.string "Falando em tempo, ouvi uma noticia\n"
	.string "de um rapaz do INSTITUTO DO TEMPO.\p"
	.string "Ele disse que um clima estranho tem sido\n"
	.string "registrado em varios lugares!\p"
	.string "Voce deveria visitar o INSTITUTO DO TEMPO\n"
	.string "e perguntar por la!$"

SlateportCity_Harbor_Text_SubTooSmallForMe:
	.string "Eu queria acompanhar o CAP. STERN\n"
	.string "na exploracao do fundo do mar.\p"
	.string "Mas o submarino e pequeno demais para mim.\p"
	.string "Se eu tentasse entrar, nao sobraria\n"
	.string "espaco para o CAPITAO...$"

SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum:
	.string "CAP. STERN: Aqueles bandidos...\p"
	.string "Sao os mesmos que tentaram roubar\n"
	.string "os PRODUTOS DEVON no MUSEU.$"

SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove:
	.string "ARCHIE: Ora?\n"
	.string "Voce de novo...\p"
	.string "Voce foi persistente em nos seguir ate aqui,\n"
	.string "isso eu tenho que reconhecer.\p"
	.string "Mas agora...\n"
	.string "Ninguem pode nos deter! Ninguem!\p"
	.string "Ou vai nos seguir ate nosso\n"
	.string "ESCONDERIJO na CIDADE DE LILYCOVE?\p"
	.string "Fwahahahaha...$"

SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine:
	.string "CAP. STERN: Por que...\p"
	.string "Por que a EQUIPE AQUA roubaria meu\n"
	.string "SUBMARINO EXPLORADOR 1?\p"
	.string "Eles nao podem estar atras do\n"
	.string "POKEMON adormecido no fundo do mar...\p"
	.string "Mas, mesmo que eu fosse atras deles,\n"
	.string "nao teria a menor chance contra eles...$"

SlateportCity_Harbor_Text_TeamAquaLeftNeedDive:
	.string "CAP. STERN: Ah, {PLAYER}{KUN}...\p"
	.string "Entao... A EQUIPE AQUA partiu antes que voce\n"
	.string "conseguisse impedi-los...\p"
	.string "Nao, nao se culpe.\n"
	.string "Voce nao tem culpa pelo que aconteceu.\p"
	.string "Tentar alcancar um submarino...\n"
	.string "E impossivel para a maioria das pessoas.\p"
	.string "Voce precisaria de um POKEMON que soubesse\n"
	.string "usar MERGULHO...\p"
	.string "Talvez, se voce fosse ate\n"
	.string "CIDADE DE MOSSDEEP...\p"
	.string "Ha muitos mergulhadores por la, entao\n"
	.string "talvez alguem possa ensinar voce...$"

SlateportCity_Harbor_Text_NeedDiveToCatchSub:
	.string "CAP. STERN: Tentar alcancar um\n"
	.string "submarino... E impossivel.\p"
	.string "Voce precisaria de um POKEMON que soubesse\n"
	.string "how to DIVE…\p"
	.string "Talvez, se voce fosse ate\n"
	.string "CIDADE DE MOSSDEEP...\p"
	.string "Ha muitos mergulhadores por la, entao\n"
	.string "talvez alguem possa ensinar voce...$"

SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry:
	.string "CAP. STERN: Ah, sim.\n"
	.string "SR. BRINEY veio ao nosso ESTALEIRO.\p"
	.string "Nao vai demorar para terminarmos\n"
	.string "a construcao da balsa!$"

SlateportCity_Harbor_Text_FinishedMakingFerry:
	.string "CAP. STERN: {PLAYER}{KUN}!\p"
	.string "Finalmente terminamos a construcao da balsa\n"
	.string "S.S. TIDAL!\p"
	.string "Nao teriamos conseguido sem\n"
	.string "a ajuda do seu amigo SR. BRINEY.\p"
	.string "Faca um pequeno passeio nela!$"

SlateportCity_Harbor_Text_WouldYouTradeScanner:
	.string "CAP. STERN: Ora?\n"
	.string "{PLAYER}{KUN}, esse item que voce tem...\p"
	.string "Isso e um SCANNER! Ele seria muito util\n"
	.string "em nossas exploracoes.\p"
	.string "{PLAYER}{KUN}, voce trocaria seu\n"
	.string "SCANNER por alguma coisa?\p"
	.string "Por exemplo, uma PRESA DO MAR ou\n"
	.string "uma ESCAMA DO MAR que eu tenho?$"

SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow:
	.string "CAP. STERN: Tem certeza?\n"
	.string "Esse item nao serve para voce, {PLAYER}{KUN}...\p"
	.string "Tudo bem, entao. Se quiser trocar seu\n"
	.string "SCANNER, e so me avisar.$"

SlateportCity_Harbor_Text_TradeForDeepSeaTooth:
	.string "CAP. STERN: Entao voce vai troca-lo pela\n"
	.string "minha PRESA DO MAR?$"

SlateportCity_Harbor_Text_TradeForDeepSeaScale:
	.string "CAP. STERN: Entao voce vai troca-lo pela\n"
	.string "minha ESCAMA DO MAR?$"

SlateportCity_Harbor_Text_WhichOneDoYouWant:
	.string "CAP. STERN: Qual deles voce quer?$"

SlateportCity_Harbor_Text_HandedScannerToStern:
	.string "{PLAYER} entregou o SCANNER ao\n"
	.string "CAP. STERN.$"

SlateportCity_Harbor_Text_ThisWillHelpResearch:
	.string "CAP. STERN: Obrigado, {PLAYER}{KUN}!\n"
	.string "Isso vai ajudar muito em nossa pesquisa!$"
