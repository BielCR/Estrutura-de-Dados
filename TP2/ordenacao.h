# ifndef ordenacao_h
# define ordenacao_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[100];
	int qPacientesUrgencia, qPacientesEmer, qPacientesSem, qMedicos;
} TUpa;

//Alocando vetor de upas
void alocaUpas(TUpa **Upas, int qtd);

void lerUpas (TUpa *upas, int qtd);

void desalocaUpas(TUpa **Upas, int n);

void shellsort(TUpa * upas, int n);

int compara(TUpa t1, TUpa t2);

void imprime(TUpa *upas, int n);

/*mergesort
void ordena (TUpa *Upas, int l, int r);
void merge(TUpa *upas, int l, int m, int r);
*/
# endif
