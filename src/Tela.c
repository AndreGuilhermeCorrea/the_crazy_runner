#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// // Função para posicionar o cursor na tela
void telaXY() {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // Posiciona o cursor na tela
}

//Fim do código