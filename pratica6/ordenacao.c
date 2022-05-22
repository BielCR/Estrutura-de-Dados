

#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>


//Manter como especificado
struct time *alocaVetor(int n){
	
   struct time *Times = (struct time*)calloc(n,sizeof(struct time));//preencher
 
   return Times;
}


//Manter como especificado
void desalocaVetor(struct time **vetor){

    free((*vetor));
}



//implemente sua funcao de ordenacao aqui, que deve invocar a funcao compare
void ordenacao(struct time *vetor, int n){
    int i , j ;
    struct time value;
    int gap = 1;

    for (int  i = 0; i < n; i++)
    {
        vetor[i].nome = i+1;
    }
    
    do {
        gap = 3*gap+1;
    } while(gap < n);
    
    do {
        gap /= 3;
        for(i = gap; i < n; i++) {
            value = vetor[i];
            j = i - gap;
                
            while (j >= 0 && compare(value,vetor[j] )==1) {
                vetor[j + gap] = vetor[j];
                j -= gap;
            }
            vetor[j + gap] = value;
    }
    }while(gap > 1);
}

//compara dois elementos do vetor de times, indicado se o metodo de ordenacao deve troca-los de lugar ou nao
int compare(const struct time t1, const struct time t2){

    
        if (t1.pontos>t2.pontos){
           return 1;
        }
        
        else if (t1.pontos<t2.pontos){
            return 2;
        }

        float resultado1,resultado2;

        if (t1.saldo.recebidos == 0)
        {
            resultado1 = t1.saldo.marcados;
        }
        else 
            resultado1 = t1.saldo.marcados/t1.saldo.recebidos;

        if (t2.saldo.recebidos == 0)
        {
            resultado2 = t2.saldo.marcados;
        }
        else 
           
             resultado2 = t2.saldo.marcados/t2.saldo.recebidos;
        
       if (resultado1>resultado2)
            
                return 1;
       else 
                return 2;
        
        
}



