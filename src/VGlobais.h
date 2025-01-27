#ifndef VGLOBAIS_H
#define VGLOBAIS_H

// Definição de variáveis globais do jogo com uso de struct para facilitar a manipulação

typedef struct
{
    int vel;
    int t;
} Variavel;

typedef struct
{
    int score;
    char nome[30];
} Player;

#define T_INICIAL 0 // Tempo inicial do jogo
#define VEL_INICIAL 100 // Velocidade inicial do jogo

#endif

//Fim do código