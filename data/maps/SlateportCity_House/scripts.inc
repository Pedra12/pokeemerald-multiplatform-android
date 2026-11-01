SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "Meu POKéMON tem natureza AFOBADA.\p"
	.string "Ele tem mais VELOCIDADE que\n"
	.string "meus outros POKéMON.\p"
	.string "Talvez a natureza tenha algo a ver\n"
	.string "com o aumento dos atributos dos POKéMON.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "Você é um TREINADOR, nao é?\p"
	.string "Já que veio para SLATEPORT,\n"
	.string "deve estar indo para a TENDA DE BATALHA.$"

