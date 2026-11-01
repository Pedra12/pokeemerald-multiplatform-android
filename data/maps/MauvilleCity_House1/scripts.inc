MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Uhuu!\p"
	.string "Ouço as pessoas me chamarem de QUEBRA-ROCHA\n"
	.string "mas acho esse apelido meio ofensivo.\p"
	.string "Acho que mereço um pouco mais de respeito,\n"
	.string "talvez QUEBRA-ROCHA, O CARA.\p"
	.string "Uhuu!\p"
	.string "De qualquer forma, seus POKéMON parecem\n"
	.string "bem fortes.\p"
	.string "Gostei disso!\n"
	.string "Aqui, pegue esta MÁQUINA OCULTA!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "Essa MO contém QUEBRA-ROCHA.\p"
	.string "Se encontrar grandes pedras\n"
	.string "bloqueando seu caminho…\p"
	.string "Use esse golpe da MO e quebre\n"
	.string "as pedras para liberar a passagem!\p"
	.string "Isso mesmo! Quebre as pedras, eu digo!\n"
	.string "Uhuu!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Ah, sim, se quebrar uma pedra, um POKéMON\n"
	.string "pode sair voando de seu esconderijo.\p"
	.string "Uhuu!$"

