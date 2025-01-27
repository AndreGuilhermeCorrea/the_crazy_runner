#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "Header.h"
#include "VGlobais.h"

// Função para obter os dados do usuário
void dadosUser()
{
    Player jogador;
    printf("Digite o nome do Player: ");
    fflush(stdin);// Limpa o buffer de entrada para remover caracteres indesejados
    fgets(jogador.nome, sizeof(jogador.nome), stdin); 
    jogador.score = 0;

}

void creditos() {
    system("cls");
    FILE *arq = fopen("arq//creditos.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de créditos.\n");
        return;
    }
    char c;
    while ((c = fgetc(arq)) != EOF)
    {
        printf("%c", c);
    }
    fclose(arq);
    getch();
}

//Fim do código