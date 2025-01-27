#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#include "Header.h"
#include "VGlobais.h"

void limpaTela() {
    system("cls");
    telaXY(2, 25);
    printf("PRESSIONE X PARA VOLTAR AO MENU"); 
}

//Fim do código