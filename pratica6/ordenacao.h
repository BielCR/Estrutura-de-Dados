# ifndef ordenacao_h
# define ordenacao_h
#include <stdlib.h>

struct time {
    int numeroTime;
    float saldoCes;
    int insL;
    float pontos;
};

//Manter como especificado
void ordenacao(struct time *vetor, int n);
//Manter como especificado
struct time *alocaVetor(int n);
//Manter como especificado
void desalocaVetor(struct time **vetor);
//faz a comparacao utilizada para ordenar os times
int compare(struct time t1, struct time t2);

//func mergesort
void mergesort(struct time *vetor, int l, int r);
void merge(struct time *v, int l,int m,int r);

# endif
