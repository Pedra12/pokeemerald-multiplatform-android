PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Hmmm…\n"
	.string "Nao encontrei nenhum…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Olá, você viu algum POKÉMON\n"
	.string "chamado SHROOMISH por aqui?\p"
	.string "Eu adoro esse POKÉMON.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "Eu ia pegar você de surpresa, mas você\n"
	.string "demorou uma eternidade na FLORESTA DE PETALBURG\l"
	.string "para atravessar, nao foi?\p"
	.string "Cansei de esperar, entao apareci!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "Você! PESQUISADOR DA DEVON!\p"
	.string "Entregue esses documentos!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Aaaai!\p"
	.string "Você é um TREINADOR DE POKÉMON, nao é?\n"
	.string "Você precisa me ajudar, por favor!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Ha? O que você pensa que está fazendo?\n"
	.string "O quê? Vai protegê-lo?\p"
	.string "Quem cruza o caminho da EQUIPE AQUA\n"
	.string "nao recebe misericórdia, nem mesmo uma criança!\p"
	.string "Vamos, batalhe comigo!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "Está brincando! Você é forte!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Grrr… Você tem muita coragem\n"
	.string "para se meter com a EQUIPE AQUA!\l"
	.string "Vamos, batalhe comigo de novo!\p"
	.string "Eu queria dizer isso, mas estou sem\n"
	.string "POKÉMON…\p"
	.string "E, olha, nós da EQUIPE AQUA também estamos\n"
	.string "atrás de algo em RUSTBORO.\p"
	.string "Vou deixar você ir por hoje!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Ufa…\n"
	.string "Essa foi por pouco!\p"
	.string "Graças a você, ele nao roubou\n"
	.string "estes documentos importantes.\p"
	.string "Já sei! Vou lhe dar uma SUPERBOLA como\n"
	.string "agradecimento!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Aquele bandido da EQUIPE AQUA nao disse\n"
	.string "que estavam atrás de algo em\l"
	.string "RUSTBORO também?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Ih! Temos uma emergência!\n"
	.string "Nao posso perder tempo!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Você está carregando muitos itens.\n"
	.string "Nao posso lhe dar esta SUPERBOLA.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "Capturei um monte de POKÉMON!\p"
	.string "Vamos, vamos, vamos!\n"
	.string "Meu time de POKÉMON INSETOS!$"

PetalburgWoods_Text_ICouldntWin:
	.string "Tenho todos estes POKÉMON,\n"
	.string "mas nao consegui vencer…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "Capturei vários POKÉMON.\n"
	.string "Agora fiquei sem POKÉ BOLAS.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Se você levar POKÉMON INSETOS para a escola,\n"
	.string "vai ficar popular na mesma hora!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Nao posso ser popular se perder.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Se você tiver um POKÉMON INSETO grande,\n"
	.string "as pessoas vao respeitar você.$"

PetalburgWoods_Text_IWantRematch1:
	.string "Quero uma revanche quando meus POKÉMON\n"
	.string "INSETOS crescerem!\p"
	.string "Vou registrar você no meu POKÉNAV!$"

PetalburgWoods_Text_IWantRematch2:
	.string "I want a rematch when my BUG \n"
	.string "INSETOS crescerem!\p"
	.string "Vou registrar você no meu POKÉNAV!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "Meus POKÉMON INSETOS cresceram.\n"
	.string "Vou voltar a ser popular.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "Nao posso ser popular se perder.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "Você fica popular quando tem\n"
	.string "POKÉMON fortes, certo?\l"
	.string "Por isso, tenho treinado bastante.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Ei, você!\n"
	.string "Seus POKÉMON estao bem?\p"
	.string "Se seus POKÉMON estiverem fracos e você quiser\n"
	.string "evitar batalhas, fique longe\l"
	.string "da grama alta.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Às vezes, há coisas no\n"
	.string "chao mesmo que você nao consiga vê-las.\p"
	.string "Por isso, sempre verifico onde estou\n"
	.string "pisando.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Ah, que legal!\n"
	.string "Essa é a INSÍGNIA do GINÁSIO DE RUSTBORO!\p"
	.string "Você deve ser um TREINADOR.\n"
	.string "Experimente usar este item.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "É uma SEMENTE MILAGROSA.\n"
	.string "Quando um POKÉMON segura esse item, seus\l"
	.string "golpes do tipo GRAMA ficam mais fortes.\p"
	.string "Além da SEMENTE MILAGROSA, acho que existem\n"
	.string "outros itens úteis para os POKÉMON\l"
	.string "segurarem.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "DICAS DE TREINADOR\p"
	.string "Qualquer POKÉMON que participe ao menos uma vez\n"
	.string "de uma batalha recebe pontos de EXP.\p"
	.string "Para treinar um POKÉMON fraco, coloque-o\n"
	.string "no início da lista da equipe.\p"
	.string "Assim que a batalha começar, troque-o\n"
	.string "por outro. Ele ganhará EXP sem\l"
	.string "sofrer nenhum dano.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "DICAS DE TREINADOR\p"
	.string "Além dos Pontos de Vida (HP), os POKÉMON\n"
	.string "têm Pontos de Poder (PP), usados para\l"
	.string "executar golpes durante a batalha.\p"
	.string "Se um POKÉMON ficar sem PP, ele deve ser\n"
	.string "levado a um CENTRO POKÉMON.$"

