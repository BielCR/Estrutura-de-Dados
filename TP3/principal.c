#include "busca.h"

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
    int qCasos;
    scanf("%d", &qCasos);

    TInfo * infos = alocaInfos(qCasos);

    double *result = malloc(sizeof(double)*qCasos);

    for(int i = 0; i < qCasos; i++){
        scanf("%d %lf %lf", &infos[i].nBlocos, &infos[i].volume, &infos[i].x);
        result[i] = buscaH(&infos[i]);
    }

    for (int i = 0; i < qCasos; i++){
      if (result[i] == -1)
            printf("Impossivel definir a altura do corte");
        else if (result[i] == 1)
            printf("Altura do corte igual ou maior que a camara de exposicao");
        else
            printf("%.3lf", result[i]);
        if (i != qCasos )
            printf("\n");
    }


      desalocaInfos(&infos);
    return 0 ;
    
    /*printf("\n");    
    for(int i = 0; i < qCasos; i++)
        printf("%d - %f - %f \n", infos[i].nBlocos, infos[i].volume, infos[i].x);
    */
    
}