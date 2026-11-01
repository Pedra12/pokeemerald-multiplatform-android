RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "E ai, como vai?\p"
	.string "Escute, meu amigo!\n"
	.string "Gostaria de se tornar o CAMPEAO?\p"
	.string "Eu nao sou TREINADOR, mas posso\n"
	.string "dar conselhos para voce vencer.\p"
	.string "Entao esta decidido! Vamos buscar o\n"
	.string "CAMPEONATO POKéMON juntos!\p"
	.string "Seu trabalho como TREINADOR e conquistar\n"
	.string "INSIGNIAS DE GINASIO, certo?\p"
	.string "Mas os LIDERES DE GINASIO nao sao faceis!\p"
	.string "E e ai que eu entro!\n"
	.string "Estou aqui para dar conselhos especializados!\p"
	.string "ROXANNE, a LIDER DO GINASIO, usa\n"
	.string "POKéMON do tipo PEDRA.\p"
	.string "O tipo PEDRA e muito resistente, mas\n"
	.string "nao suporta golpes dos tipos AGUA e\l"
	.string "PLANTA.\p"
	.string "Venha falar comigo depois, se vencer\n"
	.string "a LIDER DO GINASIO.\p"
	.string "Entao, boa sorte!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Uau! Que vitoria impressionante!\n"
	.string "Minha torcida deve ter ajudado!\p"
	.string "Muito bem!\n"
	.string "Confira seu CARTAO DE TREINADOR.\p"
	.string "A INSIGNIA DA PEDRA que voce recebeu\n"
	.string "deve estar registrada nele.\p"
	.string "Em outras palavras…\p"
	.string "Voce subiu o primeiro degrau\n"
	.string "da escada rumo ao CAMPEONATO!\p"
	.string "Deve ser uma sensacao incrivel!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Nao subestime os TREINADORES DO GINASIO!\n"
	.string "Vou mostrar por que somos melhores!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Voce foi bom demais para mim…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Voce ainda nao viu todo o poder\n"
	.string "assustador do tipo PEDRA!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Se nao conseguir me vencer, nao tera\n"
	.string "chance contra ROXANNE!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Nossa! Voce tem potencial!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "ROXANNE e muito mais forte do que eu.\n"
	.string "\p"
	.string "E melhor ficar preparado!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Podemos estar no meio da cidade,\n"
	.string "mas e dai?\p"
	.string "Meus POKéMON de PEDRA precisam de espaco para\n"
	.string "mostrar sua forca!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Nossa, nossa!\n"
	.string "Nosso desafiante e mesmo muito valente!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Preciso reconhecer o merito da nossa LIDER.\p"
	.string "Foi preciso inteligencia e bom senso para ela\n"
	.string "escolher o tipo PEDRA ainda tao jovem.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Ola, sou ROXANNE, LIDER DO GINASIO\n"
	.string "POKéMON DE RUSTBORO.\p"
	.string "Tornei-me LIDER DE GINASIO para aplicar\n"
	.string "em batalhas o que aprendi na\l"
	.string "ESCOLA DE TREINADORES POKéMON.\p"
	.string "Poderia demonstrar como\n"
	.string "voce batalha e quais POKéMON usa?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Entao…\n"
	.string "Eu perdi…\p"
	.string "Parece que ainda tenho muito\n"
	.string "a aprender…\p"
	.string "Entendo.\p"
	.string "As regras da LIGA POKéMON determinam\n"
	.string "que os TREINADORES devem receber isto\l"
	.string "quando derrotam um LIDER DE GINASIO.\p"
	.string "Aceite a oficial INSIGNIA DA PEDRA\n"
	.string "da LIGA POKéMON.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} recebeu a INSIGNIA DA PEDRA\n"
	.string "de ROXANNE.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "A INSIGNIA DA PEDRA aumenta o poder\n"
	.string "de ATAQUE dos seus POKéMON.\p"
	.string "Ela tambem permite que usem o golpe\n"
	.string "CORTE fora das batalhas.\p"
	.string "Leve isto tambem.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "Essa MAQUINA TECNICA, MT39,\n"
	.string "contém o golpe TUMBA DE PEDRA.\p"
	.string "Ela causa dano ao derrubar\n"
	.string "pedras e tambem reduz a VELOCIDADE.\p"
	.string "Quando voce usa uma MT, ela ensina\n"
	.string "o golpe imediatamente a um POKéMON.\p"
	.string "Lembre-se: uma MT so pode ser usada uma vez,\n"
	.string "entao pense bem antes de usa-la.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Ja que voce e tao forte, deveria\n"
	.string "desafiar outros LIDERES DE GINASIO.\p"
	.string "Ao batalhar contra muitos TREINADORES, voce\n"
	.string "vai aprender muitas coisas.$"

RustboroCity_Gym_Text_GymStatue:
	.string "GINASIO POKéMON DE RUSTBORO$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "GINASIO POKéMON DE RUSTBORO\p"
	.string "TREINADORES CERTIFICADOS POR ROXANNE:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "ROXANNE: Ola, {PLAYER}!\n"
	.string "Aqui e ROXANNE, de RUSTBORO.\p"
	.string "BRAWLY me contou que voce esta\n"
	.string "subindo rapidamente na classificacao dos\l"
	.string "TREINADORES.\p"
	.string "Bem, prefiro nao pensar que\n"
	.string "nao consigo vence-lo.\p"
	.string "Prometo que vou preparar meu GINASIO\n"
	.string "para que voce possa nos desafiar novamente.\p"
	.string "Espero que esteja ansioso por\n"
	.string "essa ocasiao tanto quanto eu!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "LIDER DO GINASIO ROXANNE registrada\n"
	.string "no POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "ROXANNE: Fico feliz em ve-lo novamente.\n"
	.string "Sou ROXANNE, a LIDER deste GINASIO.\p"
	.string "Tenho certeza de que ambos participamos de\n"
	.string "muitas batalhas desde nosso ultimo encontro.\p"
	.string "Gostaria de ver o quanto\n"
	.string "melhoramos. Vamos batalhar!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr…\n"
	.string "Perdi novamente…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "ROXANNE: Ainda tenho muito a aprender\n"
	.string "quando se trata de batalhas POKéMON.\p"
	.string "Ter essa consciencia me faz gostar\n"
	.string "ainda mais de batalhar!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE: Fico feliz em ve-lo novamente.\n"
	.string "Sou ROXANNE, a LIDER deste GINASIO.\p"
	.string "Tenho certeza de que ambos participamos de\n"
	.string "muitas batalhas desde nosso ultimo encontro.\p"
	.string "Gostaria de ver o quanto\n"
	.string "we've become…\p"
	.string "Ah, nao…\n"
	.string "Voce so tem um POKéMON com voce?\p"
	.string "Volte quando tiver pelo menos mais um\n"
	.string "POKéMON.$"
