#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Header.h"

// // Função para posicionar o cursor na tela
void telaXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // Posiciona o cursor na tela
}

//Fim do código