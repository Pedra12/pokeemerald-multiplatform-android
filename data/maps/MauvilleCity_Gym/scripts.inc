MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_MAUVILLE_GYM_STATE
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
	.string "Ei, como vai, futuro CAMPEAO\n"
	.string "{PLAYER}?\p"
	.string "WATTSON, LÍDER DO GINÁSIO DE MAUVILLE,\n"
	.string "usa POKéMON do tipo ELÉTRICO.\p"
	.string "Se desafiá-lo usando POKéMON do tipo ÁGUA,\n"
	.string "ele vai eletrocutá-los! Bzzzt!\p"
	.string "Além disso, ele instalou portas controladas por\n"
	.string "interruptores por todo o GINÁSIO! Que excêntrico!\p"
	.string "Ei, vá em frente!$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
	.string "Uau, você é eletrizante!\n"
	.string "Você ativou a porta!$"

MauvilleCity_Gym_Text_KirkIntro:
	.string "Minha alma elétrica vai despedaçar seus\n"
	.string "sonhos! Uou, yeah!$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "Isso foi eletrizante, intenso,\n"
	.string "energia elétrica no máximo, cara!$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "POKéMON e rock: tudo depende do coraçao,\n"
	.string "uou, yeah!$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "Treinei com WATTSON!\n"
	.string "Nao vou perder tao facilmente!$"

MauvilleCity_Gym_Text_ShawnDefeat:
	.string "Desligado e sem energia…$"

MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "WATTSON, nosso LÍDER DE GINÁSIO, está\n"
	.string "por aqui há muito, muito tempo.\p"
	.string "Ele já batalhava antes mesmo de seu\n"
	.string "pai nascer, aquele velho durao.$"

MauvilleCity_Gym_Text_BenIntro:
	.string "Este GINÁSIO tem enigmas!\n"
	.string "Nao é divertido?$"

MauvilleCity_Gym_Text_BenDefeat:
	.string "Perder nao tem graça…$"

MauvilleCity_Gym_Text_BenPostBattle:
	.string "WATTSON diz que gosta de montar\n"
	.string "pequenas armadilhas com interruptores.$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "Com meu charme e os golpes do meu POKéMON,\n"
	.string "você vai levar um choque!$"

MauvilleCity_Gym_Text_VivianDefeat:
	.string "Estou impressionado com seu poder!$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "Ouvi dizer que MAUVILLE foi fundada\n"
	.string "por WATTSON.\p"
	.string "Ele já era TREINADOR muito antes de nós\n"
	.string "nos tornarmos TREINADORES.\l"
	.string "Ele deve saber de tudo um pouco!$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "Adoro coisas brilhantes!$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "Ah…\n"
	.string "Meus olhos estao cansados…$"

MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "WATTSON, do GINÁSIO DE MAUVILLE, tem uma\n"
	.string "testa brilhante. Isso me deixa feliz!$"

MauvilleCity_Gym_Text_WattsonIntro:
	.string "Desisti dos meus planos de transformar\n"
	.string "a cidade.\p"
	.string "Por isso, passei meu tempo criando\n"
	.string "armadilhas de portas no meu GINÁSIO.\p"
	.string "Ah? O que você está fazendo aqui?\p"
	.string "O quê? Você diz que conseguiu passar\n"
	.string "por todas as minhas portas armadilhadas?\p"
	.string "Wahahahah!\n"
	.string "Isso é divertido!\p"
	.string "Entao eu, WATTSON, LÍDER DO\n"
	.string "GINÁSIO DE MAUVILLE, vou eletrizar você!$"

MauvilleCity_Gym_Text_WattsonDefeat:
	.string "Wahahahah!\n"
	.string "Muito bem, eu perdi!\p"
	.string "Você me proporcionou uma grande emoçao!\n"
	.string "Pegue esta INSÍGNIA!$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
	.string "{PLAYER} recebeu a INSÍGNIA DÍNAMO\n"
	.string "de WATTSON.$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "Com a INSÍGNIA DÍNAMO, seus POKéMON podem\n"
	.string "usar QUEBRA-ROCHA fora das batalhas.\p"
	.string "Além disso, ela fará seus POKéMON ficarem\n"
	.string "um pouco mais rápidos.\p"
	.string "Hmm…\n"
	.string "Você também deveria levar isto!$"

MauvilleCity_Gym_Text_ExplainShockWave:
	.string "A MT34 contém o golpe ONDA DE CHOQUE.\p"
	.string "É um golpe confiável que nunca\n"
	.string "erra! Pode confiar nele!\p"
	.string "… … … … … …$"

MauvilleCity_Gym_Text_RegisteredWattson:
	.string "LÍDER DE GINÁSIO WATTSON registrado\n"
	.string "no POKéNAV.$"

MauvilleCity_Gym_Text_WattsonPostBattle:
	.string "Fico cheio de esperança ao ver um jovem\n"
	.string "TREINADOR promissor como você!$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
	.string "Wahahahah!\n"
	.string "Vá em frente e se esforce, jovem!$"

MauvilleCity_Gym_Text_GymStatue:
	.string "GINÁSIO POKéMON DA CIDADE DE MAUVILLE$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "GINÁSIO POKéMON DA CIDADE DE MAUVILLE\p"
	.string "TREINADORES CERTIFICADOS POR WATTSON:\n"
	.string "{PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
	.string "WATTSON: Ahá! Finalmente chegou!\n"
	.string "Sei o que você quer.\l"
	.string "Você quer batalhar com meus POKéMON!\p"
	.string "Wahahahaha!\p"
	.string "Vou fazer faíscas saírem de você!\n"
	.string "Nao diga que nao avisei!$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
	.string "Ufa…\n"
	.string "Nossas baterias descarregaram…$"

MauvilleCity_Gym_Text_WattsonPostRematch:
	.string "WATTSON: Teremos que recarregar nossas\n"
	.string "baterias.\p"
	.string "Quando estivermos com a carga completa, vamos\n"
	.string "aceitar seu desafio com prazer.\p"
	.string "Entao volte outra hora,\n"
	.string "tudo bem?$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
	.string "WATTSON: Ahá! Finalmente chegou!\n"
	.string "Sei o que você quer.\l"
	.string "Você quer batalhar com meus POKéMON!\p"
	.string "Wahahahaha!\p"
	.string "Opa! Espere!\n"
	.string "Você só está com um POKéMON!\p"
	.string "Volte quando estiver com dois ou mais\n"
	.string "POKéMON, combinado?$"

