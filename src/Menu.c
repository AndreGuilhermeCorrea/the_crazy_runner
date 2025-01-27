#include <stdlib.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "VGlobais.h"
#include "Header.h"

// Função que exibe o menu do jogo
char menu() {
    char opcao;
    system("cls");

    telaXY(20, 10);
    printf("#####   #######    ######  #####  ######"); 
    telaXY(20, 11);
    printf("##      ##   ##      ##    ##     ##"); 
    telaXY(20, 12);
    printf("####    #######      ##    #####  ##"); 
    telaXY(20, 13);
    printf("##      ##   ##      ##    ##     ##"); 
    telaXY(20, 14);
    printf("##      ##   ##      ##    #####  ###### "); 

    telaXY(34, 16);
    printf("W PARA INICIAR"); 
    telaXY(34, 17);
    printf("X PARA SAIR"); 
    telaXY(34, 18);
    printf("C PARA CREDITOS"); 
    telaXY(34, 19);
    printf("R PARA RANKING"); 
    
    opcao = getch(); // Recebe a opção do usuário
    return opcao;
}

//Fim do código