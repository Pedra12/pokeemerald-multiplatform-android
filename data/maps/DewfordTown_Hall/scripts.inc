DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "O que esta na moda? So pode ser\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Nao consigo imaginar como seria a vida\n"
	.string "sem “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "O que esta na moda? So pode ser\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Mas ja estou ficando um pouco cansada disso.\p"
	.string "Preciso procurar a proxima grande novidade.$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "Estou ensinando meu POKEMON sobre\n"
	.string "“{STR_VAR_1},”\l"
	.string "mas nao esta dando muito certo.\p"
	.string "Acho que isso e um pouco demais.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "Estou estudando essa moda tao popular:\n"
	.string "“{STR_VAR_1}” now.\p"
	.string "E verdade que existe uma ligacao profunda\n"
	.string "between “{STR_VAR_1}”\l"
	.string "e “{STR_VAR_2}”?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "Oh!\n"
	.string "Entao minha suspeita estava certa!\p"
	.string "Estou um passo mais perto de ficar na moda,\n"
	.string "e por dentro das novidades! Uau!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "O que?!\n"
	.string "E mesmo?!\p"
	.string "Nao e facil para alguem mais velho como eu\n"
	.string "acompanhar as novas tendencias!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Toda essa historia sobre\n"
	.string "“{STR_VAR_1}”…\l"
	.string "Nao existe um programa de TV sobre isso?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "Do outro lado do mar...\p"
	.string "Is “{STR_VAR_1}”\n"
	.string "even more popular?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Eu coleciono produtos oficiais\n"
	.string "“{STR_VAR_1}”\l"
	.string "licenciados.\p"
	.string "Tenho bonecos oficiais\n"
	.string "“{STR_VAR_1}” ...\p"
	.string "Official “{STR_VAR_1}”\n"
	.string "bre clothing…\p"
	.string "E tambem livros ilustrados\n"
	.string "“{STR_VAR_1}”\l"
	.string "com licenca oficial.\p"
	.string "Hehehe, tudo isso e meu!\n"
	.string "Nao vou dividir nada com voce!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "COMO IDENTIFICAR\n"
	.string "“{STR_VAR_1}” &\l"
	.string "RUIM “{STR_VAR_1}”…\p"
	.string "A LIGACAO ENTRE\n"
	.string "“{STR_VAR_1}” AND\l"
	.string "POKEMON...\p"
	.string "DICAS UTEIS\n"
	.string "“{STR_VAR_1}”…\p"
	.string "A estante esta cheia de livros sobre\n"
	.string "“{STR_VAR_1}.”$"

DewfordTown_Hall_Text_TrendsScream:
	.string "“{STR_VAR_1}\n"
	.string "SCREAM” e o titulo.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "“{STR_VAR_1}\n"
	.string "SMILE” e o titulo.$"

DewfordTown_Hall_Text_LastTrend:
	.string "O titulo e “O ULTIMO\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "O titulo e “O NASCIMENTO DE\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "I saw “{STR_VAR_1}”!\n"
	.string "Legal, nao e?\p"
	.string "E a coisa mais incrivel do momento!\p"
	.string "Foi demais!\n"
	.string "Era de verdade, isso mesmo!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Ah, nao, nao, nao.\p"
	.string "Esse suposto\n"
	.string "“{STR_VAR_1}”\l"
	.string "que voce diz ter visto nao e o verdadeiro.\p"
	.string "O verdadeiro e bem...\n"
	.string "Como posso explicar?\l"
	.string "Mais marcante e, ao mesmo tempo, mais suave!\p"
	.string "Mas deixa pra la. E impressionante!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Ei, escute! Eu compus uma musica-tema\n"
	.string "para “{STR_VAR_1}”.\p"
	.string "“{STR_VAR_1}”\n"
	.string "esta muito popular agora.\p"
	.string "Certo, escute!\n"
	.string "... ...\p"
	.string "Oh!\n"
	.string "{STR_VAR_1}!\p"
	.string "Maravilhoso\n"
	.string "{STR_VAR_1}!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "... ...\p"
	.string "Meu caro, seria melhor voce\n"
	.string "treinar seu canto antes de\l"
	.string "se meter com\l"
	.string "“{STR_VAR_1}.”$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "Enfim, como eu dizia, nos deveriamos\n"
	.string "should get together e organize a\l"
	.string "“{STR_VAR_1}” festa\l"
	.string "na ilha.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "Oh, que ideia fantastica!\p"
	.string "It will settle once e for all\n"
	.string "quem e o melhor em\l"
	.string "“{STR_VAR_1}.”\l"
	.string "Brilhante, sem duvida!\p"
	.string "A partir de hoje, nossas vidas vao girar\n"
	.string "em torno de “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "Mas eu estava pensando...\p"
	.string "Voce nao concorda que\n"
	.string "“{STR_VAR_1}” deixou de ser\l"
	.string "apenas uma moda e passou a fazer parte\l"
	.string "do nosso dia a dia?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Como e?\n"
	.string "O que voce quer dizer?\p"
	.string "Mas e verdade que\n"
	.string "“{STR_VAR_1}”\l"
	.string "ocupa seus pensamentos, esteja voce\l"
	.string "acordado ou dormindo.\p"
	.string "Sem duvida, voce e o\n"
	.string "“{STR_VAR_1}”\l"
	.string "PROFESSOR, meu caro!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "If you e me team up as a combo,\n"
	.string "seremos imbatíveis em tudo que envolva\l"
	.string "“{STR_VAR_1}”!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Exatamente, meu amigo!\p"
	.string "Nos seremos a dupla\n"
	.string "“{STR_VAR_1}” !\p"
	.string "Que imagem incrivel, nao acha?\n"
	.string "Hahahaha!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Para mim, BOMBA DE LODO esta no auge\n"
	.string "da popularidade. Essa e a melhor!\p"
	.string "Hein? Voce esta dizendo que nao\n"
	.string "conhece BOMBA DE LODO?\p"
	.string "Que coisa lamentavel.\n"
	.string "Vou lhe dar uma.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "Eu adoro BOMBA DE LODO.\p"
	.string "Mas POKEMON que conhecem o golpe\n"
	.string "“{STR_VAR_1}”\l"
	.string "tambem estao na moda.$"

