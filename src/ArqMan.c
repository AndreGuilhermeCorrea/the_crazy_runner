#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "Header.h"

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