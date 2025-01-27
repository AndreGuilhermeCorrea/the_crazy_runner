#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "Header.h"

void delay(int timems) {
    long pause;
    clock_t now, then;

    pause = timems * (CLOCKS_PER_SEC / 1000);
    now = then = clock();
    while ((now - then) < pause)
    {
        now = clock();
    }
}

//Fim do código