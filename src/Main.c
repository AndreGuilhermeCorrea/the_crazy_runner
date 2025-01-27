#include <stdio.h>
#include <stdlib.h>

#include "Header.h"

int main() {
    system("mode con: lines=28 cols=82");

    inicioGame();
}

void inicioGame(){

    char ch, continuar;
    int i;

    Variavel v; // Declare uma variável do tipo Variavel
    v.vel = VEL_INICIAL; // Defina o valor inicial de vel
    v.t = T_INICIAL; // Defina o valor inicial de t


    char opcao = menu(); // Chama a função menu() para exibir o menu inicial
    while(opcao != 'x' || opcao != 'X')  // Loop principal do joxgo
    {
        if(opcao == 'w' || opcao == 'W')  // Se a opção escolhida for iniciar o jogo
        {
            iniciar(); // Chama a função iniciar() para preparar o ambiente do jogo
            // Loop infinito para verificar o teclado até a colisão
            while(1)
            {
                while(!kbhit())  // Verifica se há uma tecla pressionada
                {

                    personagem(0, &v); // Chama a função personagem() para desenhar o personagem
                    continuar = obstaculo(&v); // Chama a função obstaculo() para manipular os obstáculos, passando o ponteiro para v

                    if(continuar == 'x' || continuar == 'X')  // Se o usuário pressionar 'x', encerra o jogo
                    {
                        system("cls"); // Limpa a tela
                        break; // Sai do loop
                    }
                }

                ch=getch(); // Obtém o caractere pressionado pelo usuário

                if(ch == 'w'|| ch == 'W')  // Se o usuário pressionar 'w', o personagem pula
                {

                    // Subindo no pulo
                    for(i=0; i<6; i++)  // Loop para simular a animação do pulo para cima
                    {
                        personagem(1, &v); // Chama a função personagem() para desenhar o personagem pulando
                        continuar = obstaculo(&v); // Chama a função obstaculo() para manipular os obstáculos, passando o ponteiro para v

                        if(continuar == 'x' || continuar == 'X')  // Se o usuário pressionar 'x', encerra o jogo
                        {
                            system("cls"); // Limpa a tela
                            break; // Sai do loop
                        }
                    }


                    // Descendo no pulo
                    for(i=0; i<6; i++)  // Loop para simular a animação do pulo para baixo
                    {
                        personagem(2, &v); // Chama a função personagem() para desenhar o personagem pulando para baixo
                        continuar = obstaculo(&v); // Chama a função obstaculo() para manipular os obstáculos, passando o ponteiro para v

                        if(continuar == 'x' || continuar == 'X')  // Se o usuário pressionar 'x', encerra o jogo
                        {
                            system("cls"); // Limpa a tela
                            break; // Sai do loop
                        }
                    }
                }


                else if (ch == 'x'|| ch == 'X')  // Se o usuário pressionar 'x', retorna ao menu inicial
                {
                    opcao = menu(); // Chama a função menu() para exibir o menu inicial
                    break; // Sai do loop
                }
            }
        }

        else if(opcao == 'c' || opcao == 'C')  // Se a opção escolhida for exibir os créditos
        {
            creditos(); // Chama a função creditos() para exibir os créditos do jogo
            opcao = menu(); // Chama a função menu() para exibir o menu inicial
        }
        else if(opcao == 'r' || opcao == 'R')  // Se a opção escolhida for exibir os ranking
        {
            ranking(); // Chama a função r() para exibir os créditos do jogo
            opcao = menu(); // Chama a função menu() para exibir o menu inicial
        }
        else  // Se a opção escolhida for sair do jogo
        {
            return 0; // Encerra o programa
        }

    }
}

//Fim do código