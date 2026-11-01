RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "O quadro mostra alteracoes de status\n"
	.string "que podem afetar os POKéMON nas batalhas.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Qual assunto voce deseja ler?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Se um POKéMON estiver envenenado,\n"
	.string "perdera PS continuamente.\p"
	.string "Os efeitos do veneno continuam depois\n"
	.string "da batalha.\p"
	.string "Os PS de um POKéMON envenenado diminuem\n"
	.string "enquanto ele caminha.\p"
	.string "Cure o envenenamento usando um ANTIDOTO.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Se um POKéMON ficar paralisado,\n"
	.string "sua VELOCIDADE diminuira.\p"
	.string "Ele tambem pode ficar sem conseguir se mover\n"
	.string "durante a batalha.\p"
	.string "A paralisia continua depois da batalha.\n"
	.string "Cure-a usando um ANTIDOTO PARALISIA.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Se um POKéMON adormecer, nao podera\n"
	.string "atacar.\p"
	.string "Um POKéMON pode acordar sozinho,\n"
	.string "mas, se a batalha terminar enquanto ele\l"
	.string "estiver dormindo, continuara assim.\p"
	.string "Acorde-o usando um DESPERTADOR.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Uma queimadura reduz o poder de ATAQUE e\n"
	.string "diminui continuamente os PS da vitima.\p"
	.string "A queimadura continua depois da batalha.\n"
	.string "Cure a queimadura usando um ANTIQUEIMADURA.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Se um POKéMON ficar congelado, ele se torna\n"
	.string "completamente indefeso.\p"
	.string "Ele continuara congelado depois da batalha.\n"
	.string "Descongele-o usando um ANTICONGELANTE.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Os alunos que nao estudam recebem uma\n"
	.string "amostra da minha GARRA RAPIDA.\p"
	.string "Se voce e um bom aluno ou nao\n"
	.string "ficara evidente pela maneira como usa\l"
	.string "este item.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "Um POKéMON segurando a GARRA RAPIDA\n"
	.string "as vezes se move mais rapido e consegue agir\l"
	.string "antes do adversario.\p"
	.string "Existem muitos outros itens feitos\n"
	.string "para serem segurados pelos POKéMON.\p"
	.string "So esses itens ja oferecem muitos\n"
	.string "assuntos para estudar!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Estou trocando POKéMON com meu amigo\n"
	.string "agora mesmo.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "Eu sempre quis um SEEDOT e\n"
	.string "finalmente vou conseguir um!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "Os POKéMON podem segurar itens, mas\n"
	.string "nao sabem o que fazer com itens fabricados\l"
	.string "por humanos, como POCAO e ANTIDOTO.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Voce sabe que alguns golpes dos POKéMON\n"
	.string "podem confundir um POKéMON?\p"
	.string "Um POKéMON confuso as vezes\n"
	.string "ataca a si mesmo sem querer.\p"
	.string "Mas, quando sai da batalha, ele\n"
	.string "volta ao normal.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "Um POKéMON segurando uma BAGA pode\n"
	.string "se curar…\p"
	.string "Existem muitos tipos de itens que\n"
	.string "os POKéMON podem segurar…\p"
	.string "Nossa, e dificil anotar tudo\n"
	.string "isso…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "Este e o caderno de um aluno…\p"
	.string "Os POKéMON devem ser capturados usando\n"
	.string "POKé BOLAS.\p"
	.string "Ate seis POKéMON podem acompanhar\n"
	.string "um TREINADOR.\p"
	.string "Um TREINADOR e alguem que captura\n"
	.string "POKéMON, treina-os e batalha\l"
	.string "com eles.\p"
	.string "A missao de um TREINADOR e derrotar\n"
	.string "os TREINADORES fortes que esperam\l"
	.string "desafiantes nos GINASIOS POKéMON.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Ola! Nos ja nos encontramos antes?\n"
	.string "Acho que foi na CIDADE DE PETALBURG.\p"
	.string "Deixe-me me apresentar.\n"
	.string "Meu nome e SCOTT.\p"
	.string "Tenho viajado por toda parte\n"
	.string "em busca de TREINADORES excepcionais.\p"
	.string "Mais especificamente, estou procurando\n"
	.string "especialistas em batalhas POKéMON.\p"
	.string "Entao, o que traz voce a esta ESCOLA?\n"
	.string "Voce tambem e TREINADOR?\p"
	.string "A primeira coisa que voce deve fazer e\n"
	.string "ensinar o golpe CORTE a um POKéMON.\p"
	.string "Se me lembro bem, alguem nesta\n"
	.string "cidade conhece CORTE.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "SCOTT: Hmm…\p"
	.string "O nivel de talento dos alunos daqui\n"
	.string "ainda e desconhecido. Mas ha potencial.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "SCOTT: O que e isso?\p"
	.string "E uma INSIGNIA DA PEDRA, nao e?\n"
	.string "Isso e impressionante, devo dizer.\p"
	.string "Mas eu adoraria ter visto\n"
	.string "voce em uma batalha.\p"
	.string "E dificil saber como voce e como\n"
	.string "TREINADOR apenas por uma INSIGNIA.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Ola! Nos ja nos encontramos antes?\n"
	.string "Acho que foi na CIDADE DE PETALBURG.\p"
	.string "Deixe-me me apresentar.\n"
	.string "Meu nome e SCOTT.\p"
	.string "Tenho viajado por toda parte\n"
	.string "em busca de TREINADORES excepcionais.\p"
	.string "Mais especificamente, estou procurando\n"
	.string "especialistas em batalhas POKéMON.\p"
	.string "SCOTT: O que e isso?\n"
	.string "E uma INSIGNIA DA PEDRA, nao e?\p"
	.string "Isso e impressionante para\n"
	.string "um TREINADOR iniciante como voce.\p"
	.string "Mas eu adoraria ter visto\n"
	.string "voce em uma batalha.\p"
	.string "E dificil saber como voce e como\n"
	.string "TREINADOR apenas por uma INSIGNIA.$"

