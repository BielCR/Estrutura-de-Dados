#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
TipoAluno *alocaAlunos(TipoAluno *alunos, int n){
   alunos = malloc(n * sizeof(TipoAluno));
}

//Manter como especificado
TipoAluno *desalocaAlunos(TipoAluno *alunos){
  free(alunos);
}

void ordena(TipoAluno *alunos, int n){
	int m, l, r;
  l = 0;
  r = sizeof(alunos);
  m = (l+r)/2;
  while(l<n){
    

  }
  
}
