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
    int n = 1;
    int inst = 0;
    while (n != 0) {
        
        int time1, time2, pontos1, pontos2;
        int i, npartidas;
        struct time *vetor;

        //leia o numero de times
        scanf("%d", &n);

        //se for zero, o programa acaba
        if(n != 0){
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
            }
            ordenacao(vetor, n);
            inst++;
        }

        //ordenar os times

        

        //imprima o resultado
        printf("Instancia 1\n");
        for(int i = 0; i < n; i++){
            printf("%d ", vetor[i].numeroTime);
        }

        //desaloque o vetor
    }

    return 0;
}
