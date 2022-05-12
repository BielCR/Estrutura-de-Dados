#include "ordenacao.h"
#include <stdio.h>


/*
gcc -c ordenacao.c -Wall
$ gcc -c pratica6.c -Wall
$ gcc ordenacao.o pratica6.o -o exe
*/

int main()
{
    //enquanto houver dados
    while (1) {
        int n;
        int time1, time2, pontos1, pontos2;
        int i, npartidas;
        struct time *vetor;

        //leia o numero de times
        scanf("%d", &n);

        //se for zero, o programa acaba
        if(n == 0)
            exit(1);

        //aloque o vetor
        vetor = alocaVetor(n);

        //calcula o numero de partidas
        npartidas = n * (n - 1) / 2;

        //para cada partida...
        for (i = 0; i < npartidas; ++i) {
            scanf("%d %d %d %d", &time1, &pontos1, &time2, &pontos2);
            //preencher o vetor de estruturas de acordo com os dados lidos
            vetor[time1-1].saldoCes += pontos1 - pontos2;
            vetor[time2-1].saldoCes += pontos2 - pontos1;
            vetor[time1-1].insL += 1;
            vetor[time2-1].insL += 1;

            vetor[time1-1].numeroTime = time1;
            vetor[time2-1].numeroTime = time2;

            if(pontos1 > pontos2){
                vetor[time1-1].pontos += 2;
                vetor[time2-1].pontos += 1;
            }else if(pontos2 > pontos1){
                vetor[time2-1].pontos += 2;
                vetor[time1-1].pontos += 1;
            }
            printf("\ntime %d = %d time %d = %d\n", vetor[time1-1].numeroTime, vetor[time1-1].pontos, vetor[time2-1].numeroTime, vetor[time2-1].pontos);
            
        }

        //ordenar os times

        ordenacao(vetor, n);

        //imprima o resultado
        printf("Instancia 1\n");
        for(int i = 0; i < n; i++){
            printf("%d ", vetor[i].numeroTime);
        }

        //desaloque o vetor
    }

    return 0;
}
