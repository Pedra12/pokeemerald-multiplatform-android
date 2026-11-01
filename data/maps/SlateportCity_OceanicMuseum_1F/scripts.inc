SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "Bem-vindo ao MUSEU OCEÂNICO.\p"
	.string "A entrada custa ¥50.\n"
	.string "Gostaria de entrar?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "Aproveite a visita.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "Ah? Desculpe, mas parece que você nao\n"
	.string "tem dinheiro suficiente.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "Ah? Você faz parte daquele grupo que\n"
	.string "entrou antes?\p"
	.string "Você é o único que chegou atrasado.\n"
	.string "É melhor ir atrás deles!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "Nós, da EQUIPE AQUA, existimos pelo bem\n"
	.string "de todos!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "Mandaram que nos reuníssemos aqui,\n"
	.string "e foi o que fizemos, mas…\p"
	.string "Nosso CHEFE, a peça principal, nao está aqui.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "Se eu roubasse as coisas daqui,\n"
	.string "ficaria rico?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "O que eu aprender aqui, posso usar em\n"
	.string "planos maldosos…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "Se nossos capangas nao tivessem estragado tudo\n"
	.string "em RUSTBORO, nao estaríamos aqui!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "Eu nao tinha ¥50, entao demorei muito\n"
	.string "para passar pela recepcionista.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "Quero aprender sobre o mar e\n"
	.string "usar esse conhecimento nas batalhas.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "Fico todo animado quando\n"
	.string "vejo o mar!\p"
	.string "Para mim, o CAPITAO STERN é o\n"
	.string "maior exemplo!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "O mar é imenso e sem fim, além de\n"
	.string "infinitamente profundo…\p"
	.string "Deve haver muitos POKéMON que\n"
	.string "ainda nao conhecemos.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "Quero um POKéMON do mar.\p"
	.string "Acho que seria gostoso e refrescante\n"
	.string "abraçá-lo.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "Aaaah!\n"
	.string "O que você está fazendo aqui?\p"
	.string "Eu? Sou o membro da EQUIPE AQUA\n"
	.string "que você derrotou antes, lembra?\l"
	.string "No TÚNEL RUSTURF?\p"
	.string "Aqui, pegue isto!\n"
	.string "Por favor, me perdoe!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "Essa MT combina mais com você do que\n"
	.string "comigo.\p"
	.string "Espero nunca mais encontrar você!\n"
	.string "Hahahaha!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "Ah, qual é!\n"
	.string "Pegue isto e me deixe ir!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "Um líquido azul gira dentro\n"
	.string "de um recipiente de vidro.\p"
	.string "“Este é um experimento para criar um\n"
	.string "REDEMOINHO artificial usando o vento.”$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "Uma bola vermelha sobe e desce\n"
	.string "dentro de um recipiente de vidro.\p"
	.string "“Este é um experimento que simula uma\n"
	.string "CACHOEIRA usando a flutuabilidade da bola.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "É uma amostra de solo do fundo\n"
	.string "do mar.\p"
	.string "“Ao longo de muitos anos, restos de\n"
	.string "seres vivos se acumulam no fundo\l"
	.string "do mar, formando camadas sedimentares.\p"
	.string "“Ao analisar essas camadas, o\n"
	.string "passado antigo é revelado.”$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "É uma amostra de areia da praia.\p"
	.string "“Pedras das montanhas sao levadas\n"
	.string "pelos rios, onde sao\l"
	.string "quebradas e desgastadas.\p"
	.string "“Elas se transformam em graos e acabam\n"
	.string "virando areia nas praias.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "“CURIOSIDADE DO OCEANO 1\n"
	.string "Por que a água do mar é azul?\p"
	.string "“A luz é composta por muitas cores.\p"
	.string "“Quando a luz atravessa a água,\n"
	.string "a maioria das cores desaparece.\p"
	.string "“Porém, a luz azul mantém sua\n"
	.string "cor, fazendo o mar parecer azul.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "“CURIOSIDADE DO OCEANO 2\n"
	.string "Por que o mar é salgado?\p"
	.string "“A água do mar contém sais dissolvidos\n"
	.string "na forma de íons de sódio e cloro.\p"
	.string "“Esses íons saem das rochas\n"
	.string "e sao levados até o mar pela chuva.\p"
	.string "“A concentraçao de sais dissolvidos\n"
	.string "deixa o mar salgado.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "“CURIOSIDADE DO OCEANO 3\n"
	.string "O que é maior: o mar ou a terra?\p"
	.string "“O mar cobre cerca de 70%\n"
	.string "do planeta, e o restante é terra.\p"
	.string "“Por isso, o mar tem mais que o dobro\n"
	.string "do tamanho da terra.”$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "É um fóssil com marcas onduladas.\p"
	.string "“O solo do fundo do mar é desgastado\n"
	.string "pelas marés.\p"
	.string "“A água em movimento deixa marcas no solo\n"
	.string "com pequenas cristas e vales.\p"
	.string "“Se esse solo se transformar em fóssil, ele é\n"
	.string "chamado de marca de ondulaçao.”$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "Uma máquina estranha está girando sob\n"
	.string "uma cúpula de vidro.\p"
	.string "Talvez sirva para medir a profundidade\n"
	.string "de alguma coisa…$"

