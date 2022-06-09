#include "ordenacao.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ordena(TLista *pLista)
{
	// Get first node
	TCelula *aux1 = pLista->pPrimeiro;
	TCelula *aux2 = NULL;

	while (aux1 != NULL){
		aux2 = aux1->pProx;
		while (aux2 != NULL && aux2->pPrev != NULL && compare(aux2->item, aux2->pPrev->item) == -1){
			bilubilu(aux2, aux2->pPrev);
			aux2 = aux2->pPrev;
		}
		aux1 = aux1->pProx;
	}
}

void bilubilu(TCelula *origem, TCelula *destino)
{
	TCelula aux;
	aux.item = origem->item;
	origem->item = destino->item;
	destino->item = aux.item;
}

int compare(const TAluno t1, const TAluno t2)
{
	if (strcmp(t1.nome, t2.nome) < 0)
		return -1;
	else if (strcmp(t1.nome, t2.nome) > 0)
		return 1;
	else
		return 0;
}
