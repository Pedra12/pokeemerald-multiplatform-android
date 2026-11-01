GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Ei, você.\n"
	.string "Fica muito escuro mais adiante.\l"
	.string "Vai ser difícil explorar por lá.\p"
	.string "Aquele rapaz que passou por aqui…\n"
	.string "Acho que era STEVEN.\p"
	.string "Ele sabia usar FLASH, então deve ficar\n"
	.string "bem, mas…\p"
	.string "Bem, para nós, MONTANHISTAS, ajudar\n"
	.string "quem encontramos é nosso lema.\p"
	.string "Aqui está, vou passar isto para você.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Ensine o golpe oculto FLASH a\n"
	.string "um POKÉMON e use-o.\p"
	.string "Ele ilumina até a escuridão total\n"
	.string "das cavernas.\p"
	.string "Mas, para usá-lo, você precisa da INSÍGNIA\n"
	.string "do GINÁSIO POKÉMON de DEWFORD.$"

