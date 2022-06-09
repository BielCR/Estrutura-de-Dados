#include "ordenacao.h"
#include <stdio.h>

int main ()
{
	int i;
	int n, k;
	TLista lista;

	// ler as quantidades
	scanf("%d %d", &n, &k);

	// criar a lista encadeada
	TListaCria(&lista);

	// preencher a lista encadeada
	TCelula aux;
	for(i = 0; i<n;i++){
		scanf("%s", aux.item.nome);
		TListaInsereInicio(&lista, aux.item);
	}

	// ordenar a lista
	ordena(&lista);

	// imprimir o resultado
	aux = *lista.pPrimeiro;
	for(int j = 0; j < k; j++){
		aux = *aux.pProx;
	}

	printf("%s", aux.pProx->item.nome);
	// desalocar o vetor


  	return 0;
}
