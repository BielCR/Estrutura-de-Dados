# ifndef ordenacao_h
# define ordenacao_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[50];
	int qPacientesUrgencia, qPacientesEmer, qPacientesSem, qMedicos;
} TUpa;

//Alocando vetor de upas
void alocaUpas(TUpa **Upas, int qtd);

void desalocaUpas(TUpa *Upas, int n);

void ordena (TUpa *Upas, int l, int r);

void merge(TUpa *upas, int l, int m, int r);

# endif
