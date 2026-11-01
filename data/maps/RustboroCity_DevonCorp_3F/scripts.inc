RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_CORP_3F_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_CORP_3F_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.short 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject LOCALID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.short 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Sou o SR. STONE, PRESIDENTE da\n"
	.string "CORPORACAO DEVON.\p"
	.string "Acabei de receber noticias sobre voce!\p"
	.string "Voce salvou nossos funcionarios nao apenas uma,\n"
	.string "mas duas vezes!\p"
	.string "Tenho um favor para pedir a uma pessoa\n"
	.string "incrivel como voce.\p"
	.string "Soube que voce vai entregar\n"
	.string "um pacote ao ESTALEIRO DE SLATEPORT.\p"
	.string "No caminho, poderia passar por\n"
	.string "DEWFORD?\p"
	.string "Gostaria que voce entregasse uma\n"
	.string "CARTA para STEVEN em DEWFORD.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "SR. STONE: Voce deve saber que\n"
	.string "sou um excelente PRESIDENTE.\p"
	.string "Por isso, eu jamais pediria um favor\n"
	.string "sem oferecer algo em troca.\p"
	.string "E por isso que quero lhe dar isto!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} recebeu um POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "SR. STONE: Esse aparelho…\p"
	.string "E um NAVEGADOR POKéMON, ou POKéNAV\n"
	.string "para abreviar.\p"
	.string "E uma ferramenta indispensavel para qualquer\n"
	.string "TREINADOR em uma aventura.\p"
	.string "Ele tem um mapa da regiao de HOENN.\p"
	.string "Voce pode consultar facilmente a localizacao de\n"
	.string "DEWFORD e SLATEPORT!\p"
	.string "A proposito, ouvi dizer que criminosos\n"
	.string "perigosos, MAGMA e AQUA, pelo que sei,\l"
	.string "estao causando problemas por toda parte.\p"
	.string "Acho melhor voce descansar\n"
	.string "antes de continuar sua jornada.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "SR. STONE: Entao, {PLAYER}{KUN},\n"
	.string "siga com cuidado!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "SR. STONE: Conto com voce!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "SR. STONE: Voce entregou minha CARTA?\n"
	.string "Muito obrigado!\p"
	.string "Esta e minha forma de agradecer.\n"
	.string "Isso deve ajudar voce como TREINADOR.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "SR. STONE: Um POKéMON que esteja segurando\n"
	.string "o COMPART. EXP. recebera parte dos\l"
	.string "PONTOS DE EXP. das batalhas.\p"
	.string "Ele recebera PONTOS DE EXP. mesmo que nao\n"
	.string "participe da batalha.\p"
	.string "Eu diria que o COMPART. EXP. e muito util\n"
	.string "para treinar POKéMON fracos.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "SR. STONE: Desde jovem, dediquei\n"
	.string "minha vida ao trabalho.\p"
	.string "Por isso, nao conheco muito bem\n"
	.string "as tendencias e coisas desse tipo.\p"
	.string "Mas sera que todos os jovens querem ser\n"
	.string "TREINADORES da LIGA POKéMON?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "Este e o terceiro andar da\n"
	.string "CORPORACAO DEVON.\p"
	.string "O ESCRITORIO do nosso PRESIDENTE fica\n"
	.string "neste andar.\p"
	.string "De qualquer forma, nao consigo expressar\n"
	.string "o quanto sou grato pelo que voce fez.\p"
	.string "Hum… A proposito, aquela encomenda\n"
	.string "que voce recuperou para nos…\p"
	.string "Poderia entrega-la ao\n"
	.string "ESTALEIRO DE SLATEPORT?\p"
	.string "Seria terrivel se aqueles ladroes\n"
	.string "tentassem rouba-la novamente.\p"
	.string "Entao… Hehehe… Posso contar\n"
	.string "com voce para fazer isso por mim?\p"
	.string "Ah, e verdade.\n"
	.string "Poderia esperar aqui um instante?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Nosso PRESIDENTE gostaria de\n"
	.string "conversar com voce.\p"
	.string "Por favor, acompanhe-me.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Pode entrar.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Se visitar o ESTALEIRO DE SLATEPORT,\n"
	.string "procure o CAPITAO STERN.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "Os novos produtos da DEVON, a REPEAT BALL\n"
	.string "e a TIMER BALL, ficaram muito\l"
	.string "populares entre os TREINADORES.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "E uma colecao de rochas e\n"
	.string "pedras raras reunidas pelo PRESIDENTE.$"

