SlateportCity_Mart_MapScripts::
	.byte 0

SlateportCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Mart_Pokemart:
	.short ITEM_POKE_BALL
	.short ITEM_GREAT_BALL
	.short ITEM_POTION
	.short ITEM_SUPER_POTION
	.short ITEM_ANTIDOTE
	.short ITEM_PARALYZE_HEAL
	.short ITEM_ESCAPE_ROPE
	.short ITEM_REPEL
	.short ITEM_HARBOR_MAIL
	pokemartlistend

SlateportCity_Mart_EventScript_BlackBelt::
	msgbox SlateportCity_Mart_Text_SomeItemsOnlyAtMart, MSGBOX_NPC
	end

SlateportCity_Mart_EventScript_Man::
	msgbox SlateportCity_Mart_Text_GreatBallIsBetter, MSGBOX_NPC
	end

SlateportCity_Mart_Text_SomeItemsOnlyAtMart:
	.string "O MERCADO tem alguns produtos\n"
	.string "interessantes.\p"
	.string "Mas há alguns itens que você só consegue\n"
	.string "encontrar em uma LOJA POKéMON.$"

SlateportCity_Mart_Text_GreatBallIsBetter:
	.string "uma GRANDE BOLA é melhor que uma POKé BOLA\n"
	.string "para capturar POKéMON.\p"
	.string "Com isto, acho que vou conseguir aquele\n"
	.string "POKéMON difícil de encontrar…$"

