#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h> 
#include <windows.h> 

#include "Header.h" 
#include "VGlobais.h"

void personagem(int pulo, Variavel *v) {
    static int a = 1; // Variável para controlar a alternância das pernas

   // Verifica o estado do pulo e atualiza a posição vertical do personagem
    if (pulo == 1 && v->t < 10) // Se pulo para cima e t ainda não atingiu o máximo
    {
        v->t++; // Incrementa t
    }
    else if (pulo == 2 && v->t > 0) // Se pulo para baixo e t ainda não atingiu o mínimo
    {
        v->t--; // Decrementa t
    }

    // Limpa a posição anterior do personagem
    for (int i = 0; i < 6; i++)
    {
        telaXY(2, 20 - v->t + i);
        printf("           ");
    }

    // Desenha o novo personagem na tela
    telaXY(2, 22 - v->t);
    printf("     O        ");
    telaXY(2, 23 - v->t);
    printf("    /|\\      ");
    telaXY(2, 24 - v->t);
    printf("    / \\      ");

    // Desenha as pernas do personagem
    if (pulo == 1 || pulo == 2)
    {
        telaXY(2, 24 - v->t);
        printf("     //       ");
    }
    else if (a == 1)
    {
        telaXY(2, 24 - v->t);
        printf("     \\\\       ");
        a = 2;
    }
    else if (a == 2)
    {
        telaXY(2, 24 - v->t);
        printf("     />       ");
        a = 1;
    }
    telaXY(10, 24 - v->t);
    delay(v->vel); // Delay para controlar a velocidade do personagem
}

//Fim do código