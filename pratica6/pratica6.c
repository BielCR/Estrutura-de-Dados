#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{   int cont =0;
    //enquanto houver dados
    while (1) {
        int n;
        int time1, time2, pontos1, pontos2;
        int i, npartidas;
        struct time *vetor =NULL;

        //leia o numero de times
        scanf("%d", &n);
        
        //se for zero, o programa acaba
        if (n ==0)
            break;
      
       
        
            
        
        //aloque o vetor
        vetor = alocaVetor(n);
       
        //calcula o numero de partidas
        npartidas = n * (n - 1) / 2;


        //para cada partida...
        for (i = 0; i < npartidas; ++i) {
     
            scanf("%d %d %d %d", &time1, &pontos1, &time2, &pontos2);
            //preencher o vetor de estruturas de acordo com os dados lidos
          //  printf("marcados 1: %f",vetor[time1-1].saldo.marcados);
            //printf("marcados 2 : %f",vetor[time2-1].saldo.marcados);
            if (pontos1>pontos2)
            {
                vetor[time1-1].pontos = vetor[time1-1].pontos + 2;
                vetor[time2-1].pontos ++;
            }
            else{

                vetor[time2-1].pontos = vetor[time2-1].pontos + 2;
                vetor[time1-1].pontos ++;
            }

            vetor[time1-1].saldo.marcados = vetor[time1-1].saldo.marcados + pontos1;
              //    printf("marcados1 : %f",vetor[time1-1].saldo.marcados);
                  
            vetor[time1-1].saldo.recebidos = vetor[time1-1].saldo.recebidos + pontos2;

            vetor[time2-1].saldo.marcados = vetor[time2-1].saldo.marcados + pontos2;
            vetor[time2-1].saldo.recebidos = vetor[time2-1].saldo.recebidos + pontos1;
            //printf("marcados2 : %f",vetor[time2-1].saldo.marcados);


        }
        
        
        //ordenar os times
        ordenacao(vetor, n);
        
        cont++;

         if (cont != 1) 
           printf("\n\n");
        //imprima o resultado
       
         printf("Instancia %d\n",cont);
    
    
        for (int i = 0; i < n; i++)
        {
            printf("%d ",vetor[i].nome);
        }
       
        
        //desaloque o vetor
        desalocaVetor(&vetor);
       
    }
    printf("\n");
   
    
    return 0;
}
