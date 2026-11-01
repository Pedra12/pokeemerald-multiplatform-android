MauvilleCity_House2_MapScripts::
	.byte 0

MauvilleCity_House2_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_House2_EventScript_AskToTradeForHarborMail
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForHarborMail::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_House2_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade::
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	removeitem ITEM_HARBOR_MAIL
	giveitem ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase::
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade::
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport:
	.string "Se eu tivesse uma BICICLETA, seria fácil ir até\n"
	.string "SLATEPORT fazer compras.\p"
	.string "Eu poderia comprar uma CARTA DO PORTO na\n"
	.string "LOJA POKéMON de SLATEPORT…$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase:
	.string "Ah! Você tem uma CARTA DO PORTO?\n"
	.string "Quer trocá-la por uma CAIXA DE MOEDAS?$"

MauvilleCity_House2_Text_IllTradeYouCoinCase:
	.string "Ah, estou tao feliz!\n"
	.string "Certo, vou trocar por uma CAIXA DE MOEDAS!$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner:
	.string "Você pode usar essa CAIXA DE MOEDAS\n"
	.string "no CASSINO.$"

MauvilleCity_House2_Text_ThatsDisappointing:
	.string "Ah, que pena.\p"
	.string "Você precisa de uma CAIXA DE MOEDAS para usar o\n"
	.string "CASSINO.$"

