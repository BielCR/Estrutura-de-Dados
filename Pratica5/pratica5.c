#include "ordenacao.h"
#include <stdio.h>

int main ()
{
	int i;
	int n, k;
  TipoAluno *alunos;

	scanf("%d %d", &n, &k);

	alocaAlunos(alunos, n);
	for(int i = 0; i < n; i++){
		scanf("%s", &alunos->nome);
	}
	
	ordena(alunos, n);
	//ordenar
	//imprimir o resultado
	//desalocar o vetor
  return 0;
}
