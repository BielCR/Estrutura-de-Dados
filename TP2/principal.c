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
    for(int i = 0; i < quantUpas; i++){
        scanf("%s %d %d %d %d", upas[i].nome, &upas[i].qPacientesEmer, &upas[i].qPacientesUrgencia, 
        &upas[i].qPacientesSem, &upas[i].qMedicos);
    }

    ordena(upas, 0, quantUpas - 1);
    printf("\n");
    
    for(int i = 0; i < quantUpas; i++){
        printf("%s %d %d %d %d\n", upas[i].nome, upas[i].qPacientesEmer, upas[i].qPacientesUrgencia, upas[i].qPacientesSem, upas[i].qMedicos);
    }
    desalocaUpas(upas, quantUpas);
    return 0;
}