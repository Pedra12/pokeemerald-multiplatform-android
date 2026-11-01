SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Olá, olá! Sou o AVALIADOR DE APELIDOS!\n"
	.string "Sou o especialista em nomes!\p"
	.string "Terei prazer em avaliar o apelido\n"
	.string "do seu POKéMON.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "O apelido de qual POKéMON devo\n"
	.string "avaliar?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hmm… {STR_VAR_1}, é? Esse é\n"
	.string "um nome muito bonito que você escolheu.\p"
	.string "Mas! O que acha se eu\n"
	.string "sugerir um nome um pouco melhor?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Muito bem. Entao, qual será o novo\n"
	.string "apelido?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Pronto! A partir de agora, este POKéMON\n"
	.string "será conhecido como {STR_VAR_1}!\p"
	.string "É um nome melhor do que o anterior!\n"
	.string "Que sorte a sua!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Entendo.\n"
	.string "Volte sempre.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Pronto! A partir de agora, este POKéMON\n"
	.string "será conhecido como {STR_VAR_1}!\p"
	.string "Parece igual a antes,\n"
	.string "mas este nome é muito melhor!\p"
	.string "Que sorte a sua!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "Hmm… {STR_VAR_1}, entao!\p"
	.string "Este é um apelido magnífico!\n"
	.string "É simplesmente impecável!\p"
	.string "Cuide muito bem do seu\n"
	.string "{STR_VAR_1} daqui em diante.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Calma, calma.\n"
	.string "Isso é apenas um OVO!$"

