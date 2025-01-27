#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <time.h> 
#include <windows.h> 

#include "Header.h"
#include "VGlobais.h"

void iniciar() {
    system("cls"); 

    telaXY(5, 2); 
    printf("Aperte X para sair, Aperte W para Pular"); 
    telaXY(48, 2); 
    printf("SCORE : "); 
    
    // Exibe o chão
    telaXY(1, 25); 
    for (int x = 0; x < 82; x++) 
    {
        printf("__"); // Exibe caracteres "_" na tela
    }
}

//Fim do código