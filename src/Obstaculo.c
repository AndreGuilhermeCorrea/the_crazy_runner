#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "Header.h"
#include "VGlobais.h"

char obstaculo(Variavel *v) {

    static int x = 0, scr = 0; // Declaração de variáveis estáticas para controlar a posição do obstáculo e a pontuação
    char continuar = ' ';

    // Verificação de fim de jogo
    if (x == 63 && v->t < 4) // Se a posição do obstáculo atingir um certo ponto na tela e o personagem estiver abaixo de uma determinada altura
    {
        exibirScoreJogador(scr);
        chamaScore(scr);

        scr = 0; // Zera a pontuação
        v->vel = VEL_INICIAL;
        telaXY(31, 8); // Posiciona o cursor para exibir "FIM DE JOGO" na tela
        printf("FIM DE JOGO"); // Exibe "FIM DE JOGO" na tela

        telaXY(10, 9); // Posiciona o cursor para exibir instruções na tela
        printf("Aperte W para recomecar ou X para retornar ao menu"); // Exibe instruções na tela
        continuar = getch(); // Captura a entrada do jogador

        // Reinicia o jogo
        x = 0; // Reseta a posição do obstáculo

        // Limpa a área onde o personagem estava desenhado
        telaXY(19, 20);
        printf("        ");
        telaXY(19, 21);
        printf("        ");
        telaXY(19, 22);
        printf("        ");
        telaXY(19, 23);
        printf("        ");
        telaXY(19, 24);
        printf("        ");

        // Limpa a área onde a pontuação estava sendo exibida
        telaXY(70, 2);
        printf("      ");
        telaXY(31, 8);
        printf("           ");
        telaXY(10, 9);
        printf("                                                  ");

        // Se o jogador não pressionar 'w' ou 'W', retorna a entrada capturada
        if (continuar != 'w' && continuar != 'W')
        {
            return continuar;
        }
    }

    // Desenha o obstáculo na tela
    telaXY(74 - x, 20);
    printf("| |     ");
    telaXY(74 - x, 21);
    printf("| |     ");
    telaXY(74 - x, 22);
    printf("| |     ");
    telaXY(74 - x, 23);
    printf("| |     ");
    telaXY(74 - x, 24);
    printf("| |     ");
    telaXY(74 - x, 25);
    printf("| |     ");

    x++; // Move o obstáculo para a esquerda

    // Verifica se o obstáculo atingiu o limite da tela
    if (x == 73)
    {
        x = 0; // Reseta a posição do obstáculo para reiniciar o ciclo
        scr++; // Incrementa a pontuação
        // Atualiza a exibição da pontuação na tela
        telaXY(70, 2);
        printf("     ");
        telaXY(70, 2);
        printf("%d", scr);
        // Reduz a velocidade do jogo se a pontuação aumentar
        if (v->vel > 20)
        {
            v->vel--;
        }
    }

    return continuar; // Retorna a entrada capturada pelo jogador
}

//Fim do código