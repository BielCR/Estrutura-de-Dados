# ifndef busca_h
# define busca_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int nBlocos;
    double volume, x;
} TInfo;

typedef double TAlt;

TInfo *alocaInfos(int n);

double buscaH(TInfo *infos);

int comparacao (TInfo *infos, TAlt h );

void desalocaInfos(TInfo ** infos);

# endif
