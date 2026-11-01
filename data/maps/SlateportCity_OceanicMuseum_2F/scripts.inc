SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	removeobject LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "Sim? Se está procurando STERN,\n"
	.string "sou eu.\p"
	.string "Ah! Essas devem ser as peças que encomendei\n"
	.string "do SR. STONE, da DEVON.\p"
	.string "Obrigado! Isso é ótimo!\n"
	.string "Agora podemos preparar nossa expediçao.$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "Hehehe, espere aí!\n"
	.string "Vamos levar essas peças!$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "CAPITAO STERN: O-o quê?\n"
	.string "Quem sao vocês?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "Somos a EQUIPE AQUA!\p"
	.string "Nosso CHEFE quer essas peças!\n"
	.string "Feche a boca e entregue logo!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "Aaaah!\n"
	.string "Uma criança me derrotou!$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "Nossa, que desastre…\n"
	.string "O CHEFE vai ficar furioso…$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "Humph, seu fracote!\n"
	.string "Deixe que eu cuido disso!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "O quê?!\n"
	.string "Eu também perdi!$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "E agora? Se nao conseguirmos as peças,\n"
	.string "estamos encrencados!\p"
	.string "Arrgh, nao esperava que alguém se metesse\n"
	.string "no caminho por causa de uma criança!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "Vim ver por que estavam demorando tanto\n"
	.string "para pegar as peças, e vocês\l"
	.string "foram derrotados por uma simples criança?$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "Somos a EQUIPE AQUA,\n"
	.string "e amamos o mar!\p"
	.string "E eu sou o líder da EQUIPE AQUA,\n"
	.string "ARCHIE!\p"
	.string "Por que está se intrometendo conosco?\p"
	.string "…Nao! Nao pode ser!\n"
	.string "Você nao é da EQUIPE MAGMA?\p"
	.string "Espere, isso nao pode estar certo.\n"
	.string "Você nao está vestido para isso.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "POKéMON, pessoas… Toda a vida depende\n"
	.string "do mar.\p"
	.string "Por isso, a EQUIPE AQUA se dedica à\n"
	.string "expansao do mar.\p"
	.string "Nao concorda? O que estamos fazendo\n"
	.string "é uma obra magnífica.\p"
	.string "Ah, tudo bem…\n"
	.string "Você ainda é jovem demais para entender\l"
	.string "nosso nobre objetivo.\p"
	.string "Mas aviso: nem pense em\n"
	.string "interferir em nossos planos novamente.\p"
	.string "As consequências vao custar\n"
	.string "muito caro!\p"
	.string "E nao se esqueça disso!$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "CAPITAO STERN: Você é…\n"
	.string "Ah, certo, você é {PLAYER}{KUN}…\p"
	.string "De qualquer forma, foi uma situaçao tensa!\n"
	.string "Obrigado por nos salvar!\p"
	.string "Ah, sim, quase me esqueci de que você\n"
	.string "também trouxe as peças da DEVON!$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "CAPITAO STERN: Opa!\n"
	.string "Nao temos tempo a perder!\p"
	.string "Precisamos partir para nossa expediçao\n"
	.string "no fundo do mar muito em breve.\p"
	.string "Obrigado novamente, mas agora preciso\n"
	.string "ir!\p"
	.string "Fique à vontade para passear e conhecer\n"
	.string "nossas instalaçoes.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "Vi uma maquete de um navio aqui.\p"
	.string "Ela me lembrou do NAVIO ABANDONADO\n"
	.string "perto de DEWFORD…$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "Nem pense em sair correndo dentro\n"
	.string "do MUSEU!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "Nossa, o submarino é incrível!\n"
	.string "Quero dar uma volta nele!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "“AMOSTRA DE QUALIDADE DA ÁGUA 1”, diz\n"
	.string "a etiqueta.\p"
	.string "O mar é todo conectado, mas a\n"
	.string "água parece variar de uma regiao para outra.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "“AMOSTRA DE QUALIDADE DA ÁGUA 2”, diz\n"
	.string "a etiqueta.\p"
	.string "Será que a salinidade da água do mar varia\n"
	.string "também de uma regiao para outra?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "Uma bola de borracha está aumentando e\n"
	.string "diminuindo de tamanho.\p"
	.string "“No mar, o próprio peso da água\n"
	.string "exerce pressao.\p"
	.string "“Em águas rasas, a pressao nao é\n"
	.string "muito alta.\p"
	.string "“Porém, em águas extremamente profundas,\n"
	.string "a pressao pode chegar a dezenas de\l"
	.string "milhares de toneladas em uma pequena área.”$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "“MAQUETE DA REGIAO DE HOENN”\p"
	.string "É uma maquete em miniatura da\n"
	.string "regiao de HOENN.\p"
	.string "Onde fica LITTLEROOT nesta maquete?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "É uma exposiçao sobre o movimento da água do mar.\p"
	.string "“Perto do fundo do mar, a água\n"
	.string "se movimenta devido a diferenças em fatores como\l"
	.string "temperatura e salinidade.”$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "É uma exposiçao sobre o movimento da água do mar.\p"
	.string "“Perto da superfície, a água do mar se movimenta\n"
	.string "em correntes impulsionadas pelos ventos.”$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "“A BALSA S.S. TIDAL\p"
	.string "“Uma réplica em escala do navio que está sendo\n"
	.string "construído no ESTALEIRO STERN.”$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "“SUBMARINO EXPLORADOR 1\p"
	.string "“Uma réplica do submarino de alto desempenho\n"
	.string "usado para explorar o fundo do mar.”$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "“CÁPSULA SUBMERSÍVEL\p"
	.string "“Uma réplica de uma cápsula compacta e nao tripulada\n"
	.string "para explorar o fundo do mar.”$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "“S.S. ANNE\p"
	.string "“Uma réplica do navio de luxo que\n"
	.string "dá a volta ao mundo.”$"

