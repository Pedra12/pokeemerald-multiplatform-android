SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_SLATEPORT_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_SLATEPORT_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_SLATEPORT_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_SLATEPORT_COOK, 27, 16
	setobjectxyperm LOCALID_SLATEPORT_GIRL, 28, 16
	setobjectxyperm LOCALID_SLATEPORT_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_SLATEPORT_MAN_1, 31, 14
	setobjectmovementtype LOCALID_SLATEPORT_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SLATEPORT_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.short 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.short ITEM_PROTEIN
	.short ITEM_IRON
	.short ITEM_CARBOS
	.short ITEM_ZINC
	.short ITEM_CALCIUM
	.short ITEM_HP_UP
	pokemartlistend

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

/* Unclear if the text here was meant to be different, but its not*/
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.short DECOR_AZURILL_DOLL
	.short DECOR_MARILL_DOLL
	.short DECOR_SKITTY_DOLL
	pokemartlistend

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.short DECOR_RED_BRICK
	.short DECOR_BLUE_BRICK
	.short DECOR_YELLOW_BRICK
	.short DECOR_RED_BALLOON
	.short DECOR_BLUE_BALLOON
	.short DECOR_YELLOW_BALLOON
	.short DECOR_C_LOW_NOTE_MAT
	.short DECOR_D_NOTE_MAT
	.short DECOR_E_NOTE_MAT
	.short DECOR_F_NOTE_MAT
	.short DECOR_G_NOTE_MAT
	.short DECOR_A_NOTE_MAT
	.short DECOR_B_NOTE_MAT
	.short DECOR_C_HIGH_NOTE_MAT
	pokemartlistend

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.short ITEM_TM_HIDDEN_POWER
	.short ITEM_TM_SECRET_POWER
	pokemartlistend

/* Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine*/
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_SLATEPORT_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_SLATEPORT_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_SLATEPORT_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_GABBY
	removeobject LOCALID_SLATEPORT_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_SLATEPORT_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_SLATEPORT_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_SLATEPORT_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "Sou o GURU DA ENERGIA! Vou fazer o possível e\n"
	.string "vender o que você precisa!$"

SlateportCity_Text_OhYourPokemon:
	.string "Ué?\n"
	.string "Seu {STR_VAR_1}…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "Você se esforçou bastante!\p"
	.string "Como recompensa, entregue a ele esta\n"
	.string "FITA DO ESFORÇO.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} recebeu a FITA DO ESFORÇO.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} colocou a FITA DO ESFORÇO\n"
	.string "em {STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Você precisa se esforçar um pouco mais.\p"
	.string "Se conseguir, darei ao seu POKéMON\n"
	.string "algo especial.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Oh! Seu {STR_VAR_1}, essa FITA DO\n"
	.string "ESFORÇO ficou ótima nele!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "A luz do farol alcança\n"
	.string "dezenas de quilômetros de distância.\p"
	.string "Será que ela assusta os POKéMON\n"
	.string "que vivem no mar?$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Uau, veja só!\p"
	.string "As algas que encontramos por aqui\n"
	.string "sao frescas e cheias de vida.\p"
	.string "Parece até que elas podem se erguer\n"
	.string "e atacar!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Onde a água é limpa, os frutos\n"
	.string "de uma colheita abundante se acumulam.\p"
	.string "E onde as pessoas se reúnem, logo\n"
	.string "surge um mercado.\p"
	.string "É assim que uma cidade nasce e cresce.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Fazer compras sentindo o\n"
	.string "cheiro do oceano…\p"
	.string "SLATEPORT é um lugar maravilhoso!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Se você deixar BONECAS ou ALMOFADAS\n"
	.string "no chao, elas vao ficar sujas.\p"
	.string "Vou comprar alguns BLOCOS para que minhas\n"
	.string "BONECAS e ALMOFADAS nao fiquem sujas\l"
	.string "quando eu as deixar espalhadas.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Uhuu! Também vou competir na\n"
	.string "TENDA DE BATALHA!\p"
	.string "Mas antes preciso capturar\n"
	.string "alguns POKéMON!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Ufa… Estou acabado…\p"
	.string "Vim caminhando desde MAUVILLE.\n"
	.string "Nossa, esta cidade é enorme.\p"
	.string "Se eu soubesse, teria vindo\n"
	.string "de BICICLETA.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "STERN, o homem que construiu o\n"
	.string "MUSEU, também é o líder\l"
	.string "de uma equipe de exploraçao submarina.\p"
	.string "Por isso todos o chamam de CAPITAO STERN.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "O que é aquilo ali?\n"
	.string "Que fila enorme…$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Quando eu era criança, visitava\n"
	.string "o MUSEU com frequência.\p"
	.string "Eu sonhava com os mistérios\n"
	.string "do mar depois de ver as exposiçoes.$"

SlateportCity_Text_QuitPushing:
	.string "Ei! Pare de empurrar!\n"
	.string "Esta é a fila, nao está vendo?$"

SlateportCity_Text_AquaHasPolicy:
	.string "A EQUIPE AQUA tem o costume de\n"
	.string "se reunir e se dispersar\l"
	.string "no local da operaçao.$"

SlateportCity_Text_BossIsBrilliant:
	.string "Nosso CHEFE é brilhante.\p"
	.string "O que será que ele quer fazer com\n"
	.string "um MUSEU agora?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Qual será o novo plano?\p"
	.string "Nosso CHEFE fica assustador quando está bravo, entao\n"
	.string "é melhor eu nao estragar nada…$"

SlateportCity_Text_ShouldTakeItAll:
	.string "Se existe algo de que precisamos no\n"
	.string "MUSEU, devemos levar tudo!$"

SlateportCity_Text_DontButtIn:
	.string "Ei, você aí!\n"
	.string "Nao se meta!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "Que fila comprida, hein?\p"
	.string "Isso me lembra das vezes em que fiquei na fila para\n"
	.string "comprar jogos de sucesso…$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Por que estamos na fila e pagando?\n"
	.string "Era só entrar de uma vez!$"

SlateportCity_Text_WhatDoYouWant:
	.string "O quê?\n"
	.string "O que você quer?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Quer ler esta placa?\n"
	.string "Eu leio para você!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Vamos ver…\p"
	.string "Hum… Acho que diz algo como\n"
	.string "“a vida no mar é infinita.”\p"
	.string "Sim, tenho quase certeza de que é isso\n"
	.string "que está escrito.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Resmungando…\p"
	.string "Eu devia ter trazido meu Game Boy\n"
	.string "Advance para nao ficar entediado na fila…\p"
	.string "Resmungando…$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Quando esta operaçao terminar, vou levar\n"
	.string "você a um spa de águas termais!\p"
	.string "Foi isso que nosso líder prometeu.\n"
	.string "Mal posso esperar!$"

SlateportCity_Text_SeaIsSoWet:
	.string "O mar é tao imenso…\p"
	.string "Será que o mar foi formado\n"
	.string "pelas lágrimas derramadas pelos POKéMON?$"

SlateportCity_Text_SinkOldBoats:
	.string "Você sabe o que fazem com navios antigos\n"
	.string "que já estao velhos demais para navegar?\p"
	.string "Eles os afundam no mar para que\n"
	.string "se tornem habitats para POKéMON.$"

SlateportCity_Text_BuyTooMuch:
	.string "Sempre que venho aqui, acabo me empolgando\n"
	.string "e compro coisas demais.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Se quiser mudar o apelido do seu POKéMON,\n"
	.string "você terá que procurar o AVALIADOR\l"
	.string "DE APELIDOS.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "Você nao pode mudar o apelido de um POKéMON\n"
	.string "que recebeu por troca.\p"
	.string "O carinho do TREINADOR original por aquele\n"
	.string "POKéMON está no apelido.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Recentemente, uma TENDA DE BATALHA foi construída\n"
	.string "em SLATEPORT.\p"
	.string "GINÁSIOS sao divertidos, mas a TENDA DE BATALHA\n"
	.string "também tem seu charme.\p"
	.string "Você deveria procurar POKéMON fortes\n"
	.string "para a TENDA DE BATALHA!$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "Eu esperava que fosse uma estrela famosa\n"
	.string "para conseguir um autógrafo.\p"
	.string "Mas quem está dando a entrevista?\n"
	.string "Nao é o CAPITAO STERN?$"

SlateportCity_Text_InterviewerSoCool:
	.string "Aquela repórter é tao elegante\n"
	.string "e bonita.\p"
	.string "Quando eu crescer, vou ser\n"
	.string "uma jornalista internacional!$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "O CAPITAO STERN disse que descobriram\n"
	.string "algo no fundo do mar.\p"
	.string "O que será?\n"
	.string "O que poderia ser?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "O que está acontecendo aqui?\p"
	.string "Será que o bom CAPITAO voltou com\n"
	.string "um peixe enorme do fundo do mar?$"

SlateportCity_Text_AmIOnTV:
	.string "Ei! Você está assistindo?\n"
	.string "Estou na TV?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "Uma entrevista para a TV! Aqui!\n"
	.string "O CAPITAO é uma celebridade!$"

SlateportCity_Text_BigSmileForCamera:
	.string "TY: Certo, CAPITAO STERN, abra um grande sorriso\n"
	.string "para a câmera!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "GABBY: Entendo, entendo. Você teve uma experiência\n"
	.string "muito valiosa…$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "CAPITAO STERN: Sim, de fato. Pretendemos\n"
	.string "continuar nossa exploraçao.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "GABBY: Isso é maravilhoso, CAPITAO STERN!\n"
	.string "Obrigada por reservar um tempo da\l"
	.string "sua agenda cheia para conversar conosco.\p"
	.string "Esperamos entrevistá-lo novamente\n"
	.string "com notícias de novas descobertas!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "CAPITAO STERN: Ufa…\p"
	.string "Foi a primeira vez que fui filmado para\n"
	.string "a TV. Foi muito tenso.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "Opa! {PLAYER}{KUN}!\n"
	.string "Você está ótimo!\p"
	.string "Fizemos uma grande descoberta em nossa última\n"
	.string "exploraçao do fundo do mar.\p"
	.string "Encontramos uma caverna submarina na\n"
	.string "ROTA 128.\p"
	.string "Acreditamos que seja o habitat de um POKéMON\n"
	.string "que se acreditava extinto há muito tempo.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Fufufu…\n"
	.string "CAPITAO STERN, suponho.\p"
	.string "Nós, da EQUIPE AQUA, vamos assumir\n"
	.string "o controle do seu submarino!\p"
	.string "Suas objeçoes nao significam nada!\n"
	.string "Esperamos sua total cooperaçao!\p"
	.string "Fufufu…\n"
	.string "Apenas observe e descubra o que a EQUIPE\l"
	.string "AQUA está planejando!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "CAPITAO STERN: O que foi aquilo?\p"
	.string "Parecia alguém usando\n"
	.string "um megafone…\p"
	.string "De onde veio?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "Veio do PORTO!\p"
	.string "O submarino!\n"
	.string "Estao tentando roubá-lo!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN}!\n"
	.string "Por favor, venha comigo!$"

SlateportCity_Text_BattleTentSign:
	.string "TENDA DE BATALHA DE SLATEPORT\n"
	.string "“Encontre-o! O POKéMON supremo!”$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "ESTALEIRO STERN\p"
	.string "“Procura-se: marinheiro capaz de navegar\n"
	.string "em qualquer correnteza.”$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "ESTALEIRO STERN\p"
	.string "“A balsa S.S. TIDAL está quase\n"
	.string "pronta para atender aos portos de\l"
	.string "SLATEPORT e LILYCOVE.”$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "ESTALEIRO STERN\p"
	.string "“O embarque na balsa SLATEPORT-LILYCOVE\n"
	.string "S.S. TIDAL é feito no\l"
	.string "PORTO.”$"

SlateportCity_Text_PokemonFanClubSign:
	.string "CLUBE DE FAS DE POKéMON\n"
	.string "“Atençao, fas de POKéMON!”$"

SlateportCity_Text_OceanicMuseumSign:
	.string "“O mar infinito sustenta\n"
	.string "toda a vida.”\p"
	.string "MUSEU OCEÂNICO$"

SlateportCity_Text_CitySign:
	.string "CIDADE DE SLATEPORT\p"
	.string "“O porto onde pessoas e POKéMON\n"
	.string "se encontram.”$"

SlateportCity_Text_MarketSign:
	.string "MERCADO DE SLATEPORT\n"
	.string "“Itens exclusivos que você só encontra aqui!”$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "PORTO DE SLATEPORT\p"
	.string "“A balsa S.S. TIDAL está sendo\n"
	.string "construída no ESTALEIRO.\p"
	.string "“O serviço deve começar\n"
	.string "em breve.”$"

SlateportCity_Text_HarborSign:
	.string "PORTO DE SLATEPORT\p"
	.string "“Aproveite um passeio agradável na\n"
	.string "balsa S.S. TIDAL.”$"

SlateportCity_Text_NameRatersHouseSign:
	.string "CASA DO AVALIADOR DE APELIDOS\n"
	.string "“Avaliaçao de apelidos de POKéMON.”$"

SlateportCity_Text_ExplainBerries:
	.string "Se um POKéMON selvagem se machuca, ele se cura\n"
	.string "mastigando FRUTAS.\p"
	.string "Você sabia?\p"
	.string "Alguém viu isso e teve a ideia\n"
	.string "de fazer remédios usando FRUTAS.\p"
	.string "Você sabia?\p"
	.string "Para transformar FRUTAS em remédio,\n"
	.string "é preciso triturá-las até virar pó.\p"
	.string "Você sabia?\p"
	.string "Parece que você se interessa\n"
	.string "por FRUTAS!\p"
	.string "Tenho algo especial para alguém\n"
	.string "como você.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "Recentemente instalei máquinas nos\n"
	.string "CENTROS POKéMON para triturar FRUTAS.\p"
	.string "As máquinas TRITURADORAS DE FRUTAS ficam\n"
	.string "no CANTO DIRETO, no andar de cima.\p"
	.string "Você sabia?\p"
	.string "Você poderia fazer PÓ DE FRUTA para\n"
	.string "mim usando aquelas máquinas?\p"
	.string "Posso preparar vários tipos de remédio\n"
	.string "se você me trouxer bastante PÓ DE FRUTA.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "Você trouxe um pouco de\n"
	.string "PÓ DE FRUTA?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Por qual item você gostaria de trocar\n"
	.string "esse pó?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "Certo, você quer trocar seu\n"
	.string "PÓ DE FRUTA por um(a) {STR_VAR_1}?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Puxa, você nao tem PÓ DE FRUTA\n"
	.string "suficiente.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "Este PÓ DE FRUTA é de ótima qualidade.\n"
	.string "Vai render um excelente remédio.\p"
	.string "Gostaria de trocar mais do seu\n"
	.string "PÓ DE FRUTA por outra coisa?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "Certo! Quando conseguir mais\n"
	.string "PÓ DE FRUTA, traga para mim!$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Volte se quiser trocar seu\n"
	.string "PÓ DE FRUTA por algum remédio.\p"
	.string "Estou sempre organizando um bazar aqui.\p"
	.string "Você sabia?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "SCOTT: Ué?\n"
	.string "Tenho certeza de que já nos encontramos.\p"
	.string "Já me apresentei a você?\n"
	.string "Se ainda nao, meu nome é SCOTT.\p"
	.string "Acabei de ver a EQUIPE AQUA fugindo\n"
	.string "daqui como se tivessem levado uma ferroada.\p"
	.string "Deixe-me adivinhar: foi você quem os expulsou?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "SCOTT: Hmm…\n"
	.string "Talvez, só talvez, este TREINADOR…$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "SCOTT: Muito bem! Acho que você vai\n"
	.string "se tornar um bom amigo.\p"
	.string "Entao vamos registrar um ao outro em nossas\n"
	.string "POKéNAVS.\p"
	.string "… … … … … …$"

SlateportCity_Text_RegisteredScott:
	.string "Pessoa chamada SCOTT registrada\n"
	.string "no POKéNAV.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "SCOTT: Eu gostaria de acompanhar você,\n"
	.string "mas também quero ficar de olho\l"
	.string "no talento de outras pessoas.\p"
	.string "Entao vou visitar outras cidades\n"
	.string "por mais algum tempo.\p"
	.string "Até mais, {PLAYER}{KUN}!$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "SCOTT: Ei!\n"
	.string "Olha só, é {PLAYER}{KUN}!\p"
	.string "{PLAYER}{KUN}, deixe-me adivinhar: você vai\n"
	.string "participar do desafio da TENDA DE BATALHA?\p"
	.string "Isso! É uma boa ideia!\n"
	.string "É uma ideia excelente!\p"
	.string "Afinal, um TREINADOR forte é\n"
	.string "perfeito para a TENDA DE BATALHA!\p"
	.string "Dê o seu melhor!$"
