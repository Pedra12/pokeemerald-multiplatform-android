RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Ola e bem-vindo a DEVON\n"
	.string "CORPORACAO.\p"
	.string "Temos orgulho de produzir itens e\n"
	.string "remedios que melhoram sua vida.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Um dos nossos pesquisadores foi roubado\n"
	.string "de uma encomenda muito importante.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Ei, esses TENIS DE CORRIDA!\n"
	.string "Sao um dos nossos produtos!\p"
	.string "Fico feliz quando vejo alguem\n"
	.string "usando algo que fabricamos.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Aquela encomenda roubada…\p"
	.string "Bem, ela e importante, mas nao e\n"
	.string "algo que qualquer pessoa possa usar.\p"
	.string "Na minha opiniao, aquele ladrao nao deve\n"
	.string "ser muito inteligente.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Parece que recuperaram\n"
	.string "as MERCADORIAS DEVON roubadas.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Desculpe, somente pessoas autorizadas\n"
	.string "podem entrar aqui.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "Isso e absurdo.\n"
	.string "Como pudemos ser roubados?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Ola!\n"
	.string "Voce sera sempre bem-vindo aqui!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Amostras de rochas e metais estao\n"
	.string "expostas na vitrine de vidro.\p"
	.string "Ha um painel com algumas informacoes\n"
	.string "escritas…\p"
	.string "“A CORPORACAO DEVON comecou como\n"
	.string "produtora de pedras extraidas de pedreiras.\p"
	.string "“A empresa tambem produzia ferro a partir\n"
	.string "de particulas encontradas na areia.\p"
	.string "“De seu humilde inicio como produtora\n"
	.string "de materias-primas, a DEVON cresceu.\p"
	.string "“Hoje, a DEVON fabrica uma grande\n"
	.string "variedade de produtos industriais.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "Protótipos e produtos em teste ocupam\n"
	.string "a vitrine de vidro.\p"
	.string "Ha um painel com uma descricao…\p"
	.string "“Alem dos produtos industriais,\n"
	.string "a DEVON agora comercializa artigos diversos e\l"
	.string "produtos farmaceuticos para melhorar a vida.\p"
	.string "“Recentemente, a DEVON comecou a vender\n"
	.string "equipamentos para TREINADORES POKéMON, como\l"
	.string "POKé BOLAS e sistemas POKéNAV.”$"

