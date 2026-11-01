DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

/* NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius*/
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "E ai, futuro CAMPEAO!\n"
	.string "{PLAYER}?\p"
	.string "BRAWLY, LIDER DO GINASIO DE DEWFORD, usa\n"
	.string "POKéMON do tipo LUTADOR.\p"
	.string "Enfrenta-lo com POKéMON do tipo NORMAL\n"
	.string "e pedir para ter problemas.\p"
	.string "POKéMON LUTADORES causam um grande\n"
	.string "estrago nos POKéMON NORMAIS,\l"
	.string "entao tome cuidado!\p"
	.string "E o pior: o GINASIO e escuro como\n"
	.string "o fundo do oceano.\p"
	.string "Mas o local ficara mais claro depois que voce derrotar\n"
	.string "os TREINADORES pelo caminho.\p"
	.string "Certo, va em frente!$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "Uau! Ficou claro demais aqui!\p"
	.string "Seu futuro tambem e brilhante!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "A forca e tudo!\n"
	.string "Vamos la!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "Faltou forca…$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "Sua habilidade superou minha forca!\n"
	.string "Sua tecnica e admiravel!$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "Nao ha necessidade de BRAWLY\n"
	.string "se envolver!\p"
	.string "Vou acabar com voce!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "Mas… Como?\n"
	.string "Como pude perder tao facilmente?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "Nao vou desperdiçar esta derrota.\n"
	.string "Vou usa-la como motivacao para treinar!\p"
	.string "Um dia vou me tornar LIDER DE GINASIO…\p"
	.string "Nao, vou me tornar o CAMPEAO da\n"
	.string "LIGA POKéMON!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "Nao ouse me ignorar!\n"
	.string "Nao sera culpa minha se voce chorar!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "Buuaaaa!\n"
	.string "Eu perdi!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "Eu batalho no escuro para fortalecer\n"
	.string "meu coracao.\p"
	.string "Mas, como e tao escuro, nunca consigo\n"
	.string "ver o rosto de BRAWLY…$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Hehehe…\n"
	.string "Esta tropeçando no escuro?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Ah, voce…\n"
	.string "Nao quero conhecer voce!$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "Voce merece continuar perdido e acabar\n"
	.string "voltando para a entrada!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "Vou mostrar a coragem de\n"
	.string "um homem do mar!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "Como isso aconteceu?\n"
	.string "Nao e do meu feitio perder assim!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Ora, sim! Voce merece conhecer\n"
	.string "nosso LIDER DE GINASIO.$"

DewfordTown_Gym_Text_CristianIntro:
	.string "Se quiser passar, tera que ser\n"
	.string "por cima de mim!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "Grrrrr!\n"
	.string "Fui completamente superado!$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "Voce venceu!\n"
	.string "Va buscar aquela INSIGNIA!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "Sou BRAWLY!\n"
	.string "LIDER DO GINASIO DE DEWFORD!\p"
	.string "Fui moldado pelas ondas agitadas\n"
	.string "desta regiao e fiquei forte\l"
	.string "na caverna completamente escura!\p"
	.string "Entao voce quer me desafiar?\n"
	.string "Vamos ver do que voce e capaz!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "Uau! Voce causou uma onda muito maior\n"
	.string "do que eu esperava!\p"
	.string "Voce me arrasou!\p"
	.string "Certo, voce venceu.\n"
	.string "Fique com esta INSIGNIA DE GINASIO!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} recebeu a INSIGNIA SOCO\n"
	.string "de BRAWLY.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "A INSIGNIA SOCO faz todos os POKéMON\n"
	.string "ate o nivel 30, inclusive os recebidos\l"
	.string "por troca, obedecerem sem questionar.\p"
	.string "E voce podera usar o golpe HM\n"
	.string "CLARAO fora das batalhas.\p"
	.string "Se quiser, use tambem esta\n"
	.string "MAQUINA TECNICA.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "A MT08 contem o golpe CORPULENCIA.\p"
	.string "Esse golpe aumenta tanto o ATAQUE\n"
	.string "quanto a DEFESA.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "LIDER DO GINASIO BRAWLY registrado\n"
	.string "no POKéNAV.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "Consigo ver seu talento se tornando uma enorme\n"
	.string "onda capaz de causar espanto\l"
	.string "entre os TREINADORES um dia!$"

DewfordTown_Gym_Text_GymStatue:
	.string "GINASIO POKéMON DE DEWFORD$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "GINASIO POKéMON DE DEWFORD\p"
	.string "TREINADORES CERTIFICADOS POR BRAWLY:\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "BRAWLY: Uma onda pode recuar, mas\n"
	.string "sempre retorna a praia.\p"
	.string "Um talento enorme como o seu…\n"
	.string "Eu sabia que voce voltaria!\p"
	.string "Mostre o quanto mais alto\n"
	.string "voce chegou!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "Uau!\n"
	.string "Fui derrotado de novo!$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "BRAWLY: As batalhas sao vastas e profundas.\n"
	.string "Nao e possivel ver o fundo.\l"
	.string "Sao como o mar de HOENN!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "BRAWLY: Uma onda pode recuar, mas\n"
	.string "sempre retorna a praia.\p"
	.string "Um talento enorme como o seu…\n"
	.string "Eu sabia que voce voltaria!\p"
	.string "O que? Voce so tem um POKéMON\n"
	.string "capaz de batalhar.\p"
	.string "Desculpe, mas gostaria que voltasse\n"
	.string "com pelo menos dois POKéMON.$"
