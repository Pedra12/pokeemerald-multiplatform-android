MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

/* If the player does not have a bike on them Rydel assumes its stored in the PC*/
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Ora, ora, o que temos aqui?\n"
	.string "Um cliente cheio de energia!\p"
	.string "Eu? Pode me chamar de RYDEL.\n"
	.string "Sou o dono desta bicicletaria.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RYDEL: Seus TÊNIS DE CORRIDA…\n"
	.string "Estao bem sujos.\p"
	.string "Você veio de muito longe?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RYDEL: É mesmo?\p"
	.string "Entao acho que você nao precisa de\n"
	.string "nenhuma das minhas BICICLETAS.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "RYDEL: Hum, hum… … … … …\p"
	.string "Você está dizendo que veio de todo este\n"
	.string "caminho desde LITTLEROOT?\p"
	.string "Minha nossa!\n"
	.string "É longe demais!\p"
	.string "Se tivesse uma das minhas BICICLETAS, poderia\n"
	.string "ir a qualquer lugar com facilidade, sentindo\l"
	.string "a brisa suave do vento!\p"
	.string "Vou fazer o seguinte!\n"
	.string "Vou lhe dar uma BICICLETA!\p"
	.string "Ah, espere um instante!\p"
	.string "Esqueci de contar que existem\n"
	.string "dois tipos de BICICLETA!\p"
	.string "Sao a BICICLETA MACH e a\n"
	.string "BICICLETA ACRO!\p"
	.string "A BICICLETA MACH é para quem quer\n"
	.string "sentir o vento no corpo!\p"
	.string "Já a BICICLETA ACRO é para quem\n"
	.string "prefere manobras e técnica!\p"
	.string "Sou muito generoso, entao você pode\n"
	.string "escolher a que preferir!\p"
	.string "Qual delas você escolhe?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} escolheu a BICICLETA MACH.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} escolheu a BICICLETA ACRO.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "RYDEL: Se quiser trocar de\n"
	.string "BICICLETA, é só vir falar comigo!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "RYDEL: Ah? Estava pensando em\n"
	.string "trocar de BICICLETA?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "RYDEL: Certo, sem problemas!\n"
	.string "Vou trocar sua BICICLETA!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} trocou a BICICLETA MACH\n"
	.string "por uma BICICLETA ACRO.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} trocou a BICICLETA ACRO\n"
	.string "por uma BICICLETA MACH.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RYDEL: Muito bem, muito bem!\n"
	.string "Fico feliz que tenha gostado!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Ah? O que aconteceu com aquela BICICLETA\n"
	.string "que lhe dei?\p"
	.string "Ah, entendi, você a guardou no PC.\p"
	.string "Entao retire a BICICLETA do PC,\n"
	.string "e terei prazer em fazer a troca!\p"
	.string "Que o vento esteja sempre a seu favor\n"
	.string "durante sua aventura!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "Estou aprendendo sobre BICICLETAS enquanto\n"
	.string "trabalho aqui.\p"
	.string "Se precisar de dicas para andar de\n"
	.string "BICICLETA, há alguns manuais\l"
	.string "lá no fundo.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "É um manual sobre a BICICLETA MACH.\p"
	.string "Qual página você quer ler?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "A BICICLETA se move na direçao em que\n"
	.string "você pressiona o direcional.\p"
	.string "Ela ganha velocidade depois de começar a andar.\p"
	.string "Para parar, solte o direcional.\n"
	.string "A BICICLETA vai diminuir a velocidade até parar.\p"
	.string "Quer ler outra página?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "A BICICLETA MACH é veloz, mas nao consegue\n"
	.string "parar muito rápido.\p"
	.string "Fica um pouco difícil fazer curvas\n"
	.string "com ela.\p"
	.string "Solte o direcional um pouco\n"
	.string "antes da curva para diminuir a velocidade.\p"
	.string "Quer ler outra página?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "Existem pequenas ladeiras de areia\n"
	.string "por toda a regiao de HOENN.\p"
	.string "A areia solta e fofa torna\n"
	.string "impossível subir normalmente.\p"
	.string "Mas, com uma BICICLETA MACH, você pode\n"
	.string "subir rapidamente uma ladeira de areia.\p"
	.string "Quer ler outra página?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "É um manual sobre a BICICLETA ACRO.\p"
	.string "Qual página você quer ler?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Aperte o botao B enquanto pedala\n"
	.string "para levantar a roda dianteira.\p"
	.string "Você pode andar com a roda dianteira\n"
	.string "erguida usando o direcional.\p"
	.string "Essa manobra é chamada de empinar.\p"
	.string "Quer ler outra página?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "Mantendo o botao B pressionado,\n"
	.string "sua BICICLETA pode saltar sem sair do lugar.\p"
	.string "Essa manobra é chamada de saltinho.\p"
	.string "Você também pode pedalar enquanto salta.\p"
	.string "Quer ler outra página?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Aperte o botao B e o direcional\n"
	.string "ao mesmo tempo para saltar.\p"
	.string "Aperte o direcional para o lado\n"
	.string "para saltar lateralmente.\p"
	.string "Aperte para trás para fazer a BICICLETA\n"
	.string "mudar de direçao durante o salto.\p"
	.string "Quer ler outra página?$"

