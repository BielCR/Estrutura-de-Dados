# ifndef ordenacao_h
# define ordenacao_h

typedef struct{
   float marcados;
   float recebidos;
} TadSaldo;

struct time {
   int pontos;
   int nome;
   TadSaldo saldo;
};

//Manter como especificado
void ordenacao(struct time *vetor, int n);
//Manter como especificado
struct time *alocaVetor(int n);
//Manter como especificado
void desalocaVetor(struct time **Vetor);
//faz a comparacao utilizada para ordenar os times
int compare(struct time t1, struct time t2);

# endif
