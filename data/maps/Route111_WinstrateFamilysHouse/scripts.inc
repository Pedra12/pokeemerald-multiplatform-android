Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "Você é o primeiro TREINADOR que vejo que\n"
	.string "usa POKéMON com tanta maestria.\p"
	.string "Mas preciso avisar: meu filho é\n"
	.string "mais forte que você.\p"
	.string "Ele até participou do desafio da LIGA\n"
	.string "POKéMON, sabia?$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "Usamos esta BRAÇADEIRA MACHO para\n"
	.string "fortalecer nossos POKéMON de forma mais\l"
	.string "eficiente durante o treinamento.\p"
	.string "Já que você derrotou todos nós aqui,\n"
	.string "nao sei se precisa dela, mas gostaríamos\l"
	.string "que ficasse com nossa BRAÇADEIRA MACHO.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "Quando o assunto sao batalhas POKéMON,\n"
	.string "somos bastante competitivos.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "A mamae é mais forte que o papai.\p"
	.string "Eu sou mais forte que a mamae.\p"
	.string "E a vovó é mais forte que eu!\p"
	.string "Mas meu irmao mais velho é ainda mais forte\n"
	.string "que a vovó.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "Nao há dúvida de que você é forte.\p"
	.string "Mas, se batalhasse com meu neto,\n"
	.string "acabaria chorando de frustraçao.\p"
	.string "Ele é muito mais forte que qualquer TREINADOR\n"
	.string "que nossa família conhece.\p"
	.string "Ele deve estar desafiando o\n"
	.string "CAMPEAO da LIGA POKéMON agora.\p"
	.string "Conhecendo meu neto, ele pode até ser o\n"
	.string "CAMPEAO!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "Meu neto deve estar desafiando o\n"
	.string "CAMPEAO da LIGA POKéMON agora.\p"
	.string "Conhecendo meu neto, ele pode até ser o\n"
	.string "CAMPEAO!$"

