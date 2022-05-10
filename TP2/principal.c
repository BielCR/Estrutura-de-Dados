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
    TUpa ** upas = (TUpa**) malloc (quantUpas*sizeof(TUpa*)-1);

    for(int i = 0; i < quantUpas; i++){
        alocaUpas(upas[i]);
        scanf("%s %d %d %d %d", upas[i]->nome, &upas[i]->qPacientesEmer, &upas[i]->qPacientesUrgencia, 
        &upas[i]->qPacientesSem, &upas[i]->qMedicos);
        printf("\n%s\n", upas[i]->nome);
    }

    ordena(upas, quantUpas);

    desalocaUpas(upas, quantUpas);
    return 0;
}