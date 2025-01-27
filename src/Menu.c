#include <stdlib.h>
#include <stdlib.h>
#include <conio.h>

// Função que exibe o menu do jogo
char menu() {
    char opcao;
    system("cls");

    printf("#####   #######    ######  #####  ######"); 
    printf("##      ##   ##      ##    ##     ##"); 
    printf("####    #######      ##    #####  ##"); 
    printf("##      ##   ##      ##    ##     ##"); 
    printf("##      ##   ##      ##    #####  ###### "); 

    printf("W PARA INICIAR"); 
    printf("X PARA SAIR"); 
    printf("C PARA CREDITOS"); 
    printf("R PARA RANKING"); 
    
    opcao = getch(); // Recebe a opção do usuário
    return opcao;
}

//Fim do código