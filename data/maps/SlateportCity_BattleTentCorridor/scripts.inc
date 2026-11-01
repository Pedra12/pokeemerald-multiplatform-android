SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
	.byte 0

	/* This is Slateport Tent's version of the Battle Factory Pre-Battle Room*/

SlateportCity_BattleTentCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
	.short 0

SlateportCity_BattleTentCorridor_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, 2, 2
	turnobject LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, DIR_SOUTH
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.short 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
	goto_if_eq VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge

SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskSwapMon::
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	slateporttent_swapmons
	waitstate
	goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	slateporttent_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentCorridor_Movement_PlayerExit:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantExit:
	walk_up
	set_invisible
	step_end

/* Leftover text from when this was a Contest Hall in R/S*/
/* Unused*/
SlateportCity_ContestHall_Text_AdviceForContests:
	.string "Quer uma dica valiosa\n"
	.string "para os CONCURSOS?\p"
	.string "Usar um certo golpe depois de outro\n"
	.string "tipo de golpe às vezes chama\l"
	.string "mais atençao para você.\p"
	.string "Se souber o que está fazendo,\n"
	.string "pode conseguir muitos pontos de apresentaçao.\p"
	.string "Claro, seus adversários podem tentar\n"
	.string "atrapalhar a apresentaçao do seu POKéMON.$"

/* Unused*/
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
	.string "Meu pai é JUIZ DE CONCURSO.\p"
	.string "O que será que devo ser quando\n"
	.string "crescer: JUIZ ou LÍDER DE GINÁSIO?$"

/* Unused*/
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
	.string "Cara, estou muito irritado,\n"
	.string "sabe? Eu só queria\l"
	.string "saber por que meu POKéMON\l"
	.string "nunca vence, entende?\p"
	.string "Entao falei umas verdades para o JUIZ,\n"
	.string "já que opiniao é de graça.\p"
	.string "Mas ele nem quis me ouvir, poxa!\n"
	.string "Foi muito chato, cara!\p"
	.string "Ei, você! Fica quieto, entendeu?\n"
	.string "Só pega isto logo!$"

/* Unused*/
SlateportCity_ContestHall_Text_ExplainTorment:
	.string "Isso é a MT41, entendeu?\n"
	.string "Ei, é TORMENTO, tá me ouvindo?\p"
	.string "Ela nao deixa o adversário\n"
	.string "usar o mesmo golpe duas vezes seguidas, sacou?\p"
	.string "Ei, escuta aqui,\n"
	.string "nao estou atormentando você!$"

/* Unused*/
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
	.string "APRESENTADOR: Minha nossa!\n"
	.string "Que POKéMON maravilhoso, nao é?\p"
	.string "Por favor! Venha participar\n"
	.string "dos nossos incríveis CONCURSOS!\p"
	.string "Você vai se sair muito bem! Tenho certeza!\n"
	.string "Meus olhos nunca me enganaram!$"

/* Unused*/
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
	.string "JUIZ: Olá!\n"
	.string "Vejo que você é um TREINADOR!\p"
	.string "Entao nao pode deixar de\n"
	.string "participar de um CONCURSO POKéMON!\p"
	.string "Pegue um PASSE DE CONCURSO em VERDANTURF\n"
	.string "e participe quando quiser!$"

/* Unused*/
SlateportCity_ContestHall_Text_ItsAppealTime:
	.string "É hora da apresentaçao!\n"
	.string "Com qual golpe devo começar?$"

/* Unused*/
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
	.string "Eles nao prestaram muita atençao\n"
	.string "à apresentaçao do meu POKéMON…\p"
	.string "Humph, aquele JUIZ nao entende\n"
	.string "nada de coisa boa quando vê uma.$"

/* Unused*/
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
	.string "Olá! Você deve ser um grande fa para chegar\n"
	.string "tao perto da competiçao.\p"
	.string "Vou recompensar seu entusiasmo com\n"
	.string "este sábio conselho.\p"
	.string "Se um golpe agradar bastante,\n"
	.string "o público ficará empolgado.\p"
	.string "O POKéMON que se apresentar\n"
	.string "bem quando todos estiverem animados…\p"
	.string "Bem, é de se esperar que algo bom\n"
	.string "aconteça!$"

/* Unused*/
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
	.string "Nao consigo! Estou mais nervoso\n"
	.string "que meu POKéMON.\p"
	.string "Estou tremendo e meu coraçao está acelerado!$"

/* Unused*/
SlateportCity_ContestHall_Text_BattleAndContestAlike:
	.string "Uma batalha e um CONCURSO nao sao\n"
	.string "iguais, mas também têm semelhanças.\p"
	.string "Você precisa se esforçar e confiar\n"
	.string "no POKéMON que criou.$"

/* Unused*/
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
	.string "Aquele POKéMON parece estar no auge\n"
	.string "da forma, hein?\p"
	.string "Um POKéMON que se sai bem na\n"
	.string "avaliaçao secundária parece ficar mais\l"
	.string "tranquilo durante as apresentaçoes.$"

/* Unused*/
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
	.string "Olha só que figura lamentável!\p"
	.string "Heh, meu POKéMON é muito melhor\n"
	.string "do que aqueles ali!$"

/* Unused*/
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
	.string "Você nao sente vontade de dançar junto\n"
	.string "com os POKéMON quando eles fazem uma\l"
	.string "apresentaçao cheia de energia?$"

/* Unused*/
SlateportCity_ContestHall_Text_HyperRankStage:
	.string "CONCURSOS POKéMON\n"
	.string "PALCO DA CATEGORIA HIPER!$"

