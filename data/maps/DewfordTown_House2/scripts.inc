DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Admire isto com seus proprios olhos!\p"
	.string "E um LENCO DE SEDA. Esta no\n"
	.string "auge da moda, pode apostar!\p"
	.string "Ah, vejo seus olhos brilhando!\n"
	.string "Voce aprecia meu estilo deslumbrante!\p"
	.string "Ah, que pessoa encantadora!\n"
	.string "Tome. Quero que fique com ele!$"

DewfordTown_House2_Text_NoRoom:
	.string "Ah, voce nao tem espaco?\p"
	.string "Escute bem: este LENCO e indispensavel.\n"
	.string "Eu venderia todos os meus itens\l"
	.string "para conseguir um!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "O LENCO DE SEDA aumenta o poder dos\n"
	.string "golpes do tipo NORMAL.\p"
	.string "E um LENCO maravilhoso que combina\n"
	.string "com quase todos os POKéMON!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Nossa, voce atravessou o mar\n"
	.string "para visitar DEWFORD?\p"
	.string "Sera que veio ate aqui porque\n"
	.string "ouviu falar de BRAWLY?\p"
	.string "Ele e demais…\n"
	.string "Todo mundo o admira.$"

