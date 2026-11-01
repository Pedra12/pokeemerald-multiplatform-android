SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Hum… Se isto vai aqui e aquilo\n"
	.string "vai ali…\p"
	.string "Entao onde esta peça deve ficar?\n"
	.string "E o que faço com aquela engenhoca?\p"
	.string "Aaaargh! Nao consigo entender nada\n"
	.string "disso!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Hm?\n"
	.string "Oi, sou DOCK.\p"
	.string "O CAPITAO STERN me contratou para\n"
	.string "projetar uma balsa.\p"
	.string "Ah! Aquilo ali…\n"
	.string "Sao produtos da DEVON?\p"
	.string "Mas, hmm…\n"
	.string "Assim nao vai dar…\p"
	.string "O CAPITAO STERN saiu para algum lugar.\n"
	.string "Disse que tinha algo para resolver.\p"
	.string "Você poderia procurar o CAPITAO\n"
	.string "STERN e entregar isso a ele?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "DOCK: Para onde será que o CAPITAO STERN\n"
	.string "foi?\p"
	.string "Você poderia encontrar o CAPITAO STERN e\n"
	.string "entregar aquele pacote a ele?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "DOCK: Construir navios é uma arte.\p"
	.string "Muitas coisas nao podem ser resolvidas\n"
	.string "apenas com cálculos.\p"
	.string "Eu gostaria muito de ouvir os conselhos de um\n"
	.string "marinheiro experiente…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "DOCK: Oi! O SR. BRINEY se juntou a nós para\n"
	.string "nos ajudar.\p"
	.string "Graças ao marinheiro experiente, a\n"
	.string "balsa está ficando pronta.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "DOCK: Finalmente, a balsa está pronta!\p"
	.string "A nova S.S. TIDAL é uma maravilha\n"
	.string "da tecnologia!\p"
	.string "Mas tenho a sensaçao de que podemos\n"
	.string "construir algo ainda melhor.\p"
	.string "Sabe, o avanço da tecnologia\n"
	.string "nunca tem fim.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "SR. BRINEY: Ah, {PLAYER}{KUN}!\n"
	.string "Quanto tempo!\p"
	.string "Desde que nos conhecemos, este velho lobo do mar\n"
	.string "anda cheio de energia!\p"
	.string "Por isso decidi ajudar DOCK a construir\n"
	.string "uma balsa.\p"
	.string "Afinal, uma balsa poderá\n"
	.string "transportar muita gente.\p"
	.string "Mas sabe, aquele DOCK é mesmo\n"
	.string "um sujeito especial.\p"
	.string "Com o talento dele para a tecnologia e\n"
	.string "a minha experiência, tenho certeza de que podemos\l"
	.string "construir um navio incrível!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "As estaçoes, o clima, a posiçao\n"
	.string "da lua no céu…\p"
	.string "Essas e outras condiçoes fazem\n"
	.string "o mar mudar de aparência.\p"
	.string "Isso mesmo!\n"
	.string "O mar é como um ser vivo!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "Fico enjoado no mar com muita facilidade.\n"
	.string "Por isso ajudo por aqui.$"

