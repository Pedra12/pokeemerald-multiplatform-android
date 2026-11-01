DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "Ha muitas vantagens em viver\n"
	.string "em uma pequena ilha como esta, em harmonia com\l"
	.string "os POKéMON e a familia.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "Deixei o grande porto de SLATEPORT\n"
	.string "quando me casei com meu marido aqui.\p"
	.string "A vida passa devagar nesta pequena\n"
	.string "ilha. Mas estar cercada pelo\l"
	.string "belo mar tambem e uma felicidade.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Guguuh!$"

