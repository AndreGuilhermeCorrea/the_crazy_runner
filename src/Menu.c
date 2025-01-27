#include <stdlib.h>
#include <conio.h>

char menu() {
    char opcao;
    system("cls");
    printf("1 - Iniciar\n");
    printf("2 - Tela\n");
    printf("3 - Sair\n");
    printf("Digite a opcao desejada: ");
    opcao = getch();
    return opcao;
}

//Fim do código