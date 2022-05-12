#include "ordenacao.h"
#include <stdio.h>


//Manter como especificado
struct time *alocaVetor(int n){
    struct time *t = malloc(n * sizeof(struct time));
    for (int i = 0; i < n; i++)
    {
        t[i].pontos = 0;
    }
    
    return t;
    
}

//Manter como especificado
void desalocaVetor(struct time **vetor){
    for(int i = 0; i < sizeof(vetor); i++){
        free(vetor[i]);
    }
    free(vetor);
}

//implemente sua funcao de ordenacao aqui, que deve invocar a funcao compare
//merge-sort
void ordenacao(struct time *vetor, int n){
    mergesort(vetor, 0, n-1);
    printf("\nentra no ordenacao");
}

void mergesort(struct time *vetor, int l, int r){
    if(l < r){
        int m = (l +r) / 2;
        mergesort(vetor, l, m);
        mergesort(vetor, m+1, r);
        merge(vetor, l, m, r);
    }
}

void merge(struct time * vetor, int l, int m, int r){
    int tesq = (m - l + 1), tdir = (r - m);
    struct time * esq = alocaVetor(tesq);
    struct time * dir = alocaVetor(tdir);
    int i, j;
    for(i = 0; i<tesq; i++){
        esq[i] = vetor[i+l];
    }
    for(j = 0; j<tesq; j++){
        dir[j] = vetor[m+j+1];
    }
    i = 0;
    j = 0;

    for(int k = 0; k <= r; k++){
        if(i == tesq){
            vetor[k] = dir[j++];
        }else if(k == tdir){
            vetor[k] = esq[i++];
        }else if(compare(esq[i], dir[j]) == 1){
            vetor[k] = esq[i++];
        }else{
            vetor[k] = dir[j++];
        }
    }

    desalocaVetor(&esq);
    desalocaVetor(&dir);
}

//compara dois elementos do vetor de times, indicado se o metodo de ordenacao deve troca-los de lugar ou nao
int compare(const struct time t1, const struct time t2){

        if(t1.pontos > t2.pontos){
            return 1;
        }else if(t2.pontos > t1.pontos){
            return 2;
        }else if(t1.saldoCes > t2.saldoCes){
            return 1;
        }else if(t2.saldoCes > t1.saldoCes){
            return 2;
        }else if(t1.insL < t2.insL){
            return 1;
        }else if(t2.insL < t1.insL){
            return 2;
        }
    return 0;
}
