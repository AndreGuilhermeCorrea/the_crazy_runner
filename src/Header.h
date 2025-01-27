#ifndef HEADER_H
#define HEADER_H

#include "Tela.c"
#include "Time.c"
#include "Menu.c"
#include "Inicio.c"
#include "Pbstaculo.c"
#include "Personagem.c"
#include "LimpaTela.c"
#include "ArqMan.c"
#include "VGlobais.h"

extern void telaXY(int x, int y); 
extern char menu();
extern void iniciar();
extern char obstaculo(Variavel *v);
extern void personagem(int pulo, Variavel *v);
extern void creditos();
extern void limpaTela();
extern void delay(int timems);
extern void dadosUser();

#endif

//Fim do código