#include "ordenacao.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
gcc -c ordenacao.c -Wall
gcc -c principal.c -Wall
gcc ordenacao.o principal.o -o exe

gcc -c *.c -Wall
*/

int main (){
    int quantUpas;
    scanf("%d", &quantUpas);
    TUpa * upas = NULL;
    alocaUpas(&upas, quantUpas);
    lerUpas(upas, quantUpas);

    /*mergesort
    ordena(upas, 0, quantUpas - 1);
    */
    
    shellsort(upas, quantUpas);
    
    imprime(upas, quantUpas);
    desalocaUpas(&upas, quantUpas);
    return 0;
}