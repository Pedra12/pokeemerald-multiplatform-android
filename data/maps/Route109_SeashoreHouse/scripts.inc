Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "Eu sou o dono da CASA DA PRAIA.\n"
	.string "Mas pode me chamar de SR. MAR!\p"
	.string "O que eu mais gosto e assistir a\n"
	.string "batalhas emocionantes de POKEMON.\p"
	.string "Quero ver se voce tem fogo no coracao!\p"
	.string "Se conseguir derrotar todos os TREINADORES\n"
	.string "daqui, vou recompensar seu esforco.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Mostre batalhas emocionantes!\p"
	.string "Eu mantenho esta CASA DA PRAIA justamente\n"
	.string "por esse motivo!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Voce esta pegando fogo!\n"
	.string "Essas batalhas foram eletrizantes!\l"
	.string "Estou mais do que satisfeito!\p"
	.string "Como agradecimento por mostrar seu\n"
	.string "talento, quero que fique com isto.\p"
	.string "Sao seis garrafas de REFRIGERANTE!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Opa, sua MOCHILA esta lotada.\n"
	.string "Vou guardar isto para voce.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Quer comprar REFRIGERANTE?\n"
	.string "Os POKEMON adoram!\p"
	.string "Apenas ¥300 cada garrafa!\n"
	.string "Compre um pouco!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Aqui esta!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "Voce nao tem dinheiro suficiente.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "Nao?\n"
	.string "Que pena.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "Se esta procurando uma batalha na\n"
	.string "CASA DA PRAIA, nao vai encontrar\l"
	.string "TREINADOR mais animado do que eu, marujo!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "Essa foi uma batalha emocionante!\n"
	.string "Posso aceitar essa derrota, marujo!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "Sempre que estou em SLATEPORT, gosto de\n"
	.string "batalhas emocionantes e REFRIGERANTE gelado!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Batalhas sem emocao nao valem o esforco.\p"
	.string "Batalhas intensas e emocionantes deixam\n"
	.string "TREINADORES e POKEMON mais fortes!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "Isso foi demais!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Ufa, estou morrendo de sede.\n"
	.string "Acho que vou tomar um REFRIGERANTE.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "Vou mostrar como meus POKEMON\n"
	.string "sao incriveis, mas nao va chorar!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "...Eu perdi, mas nao vou chorar...$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Se um dos meus POKEMON conhecesse o golpe\n"
	.string "que me permite atravessar a agua em suas\l"
	.string "costas, eu poderia me livrar desta boia.$"

