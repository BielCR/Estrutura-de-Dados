#include "ordenacao.h"
#include <stdio.h>
#include<stdlib.h>

int main ()
{
	
	int n;
	TADupa *vetorupas = NULL;//inicia o vetor

	//le as quantidades
	scanf("%d",&n);
	//aloca o vetor
	vetorupas = alocaUpas(vetorupas,n);
	//preenche o vetor
	preencheVetor(vetorupas, n);
	//ordena
	selectionsort(vetorupas,n);
	//imprime o resultado
	imprimeResultado(vetorupas, n);
	//desaloca o vetor
	vetorupas = desalocaUpas(vetorupas);
  return 0;
}