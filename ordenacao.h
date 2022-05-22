# ifndef ordenacao_h
# define ordenacao_h


typedef struct //TAD contendo a situação de cada UPA
{
    int Emergencia;
    int Urgencia;
    int SemUrgencia;
    int QntPlantonistas;    
} TADsituacao;

 typedef struct  //TAD contendo o nome e a situação de uma UPA
{
    char nome[20];
    TADsituacao Upa;

}TADupa;

void preencheVetor(TADupa *vetorUpas, int n); 
void selectionsort (TADupa *vet, int tam);
TADupa *desalocaUpas(TADupa *upas);
TADupa *alocaUpas(TADupa *upas, int n);
void imprimeResultado(TADupa *vetorUpas, int n);

# endif