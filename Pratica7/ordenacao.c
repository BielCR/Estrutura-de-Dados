#include "ordenacao.h"
#include <stdlib.h>
#include <string.h>

void ordena(TLista *pLista, int n) {
    insertionSort(&pLista->pPrimeiro);
}

void insertionSort(TCelula ** cabeca){
    TCelula *ordenada = NULL;
    TCelula *atual = *cabeca;

    while(atual != NULL){
        TCelula *prox = atual->pProx;

        atual->pPrev = atual->pProx = NULL;

        sortedInsert(&ordenada, atual);

        atual = atual->pProx;
    }

    *cabeca = ordenada;
}

void sortedInsert(TCelula** cabeca, TCelula* novo)
{
    TCelula* atual;
    
    //se a lista for vazia
    if (*cabeca == NULL)
        *cabeca = novo;
 
     
    else if (compare((*cabeca)->item, atual->item) <= 0) {
        novo->pProx = *cabeca;
        novo->pProx->pPrev = novo;
        *cabeca = novo;
    }
 
    else {
        atual = *cabeca;
 
        while (atual->pProx != NULL &&
               compare(atual->pProx->item, novo->item) > 0)
            atual = atual->pProx;
 
        novo->pProx = atual->pProx;
 
        if (atual->pProx != NULL)
            novo->pProx->pPrev = novo;
 
        atual->pProx = novo;
        novo->pPrev = atual;
    }
}

int compare(const TAluno t1, const TAluno t2) {
    return strcmp(t1.nome, t2.nome);
}
