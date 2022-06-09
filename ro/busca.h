# ifndef ordenacao_h
# define ordenacao_h

typedef struct{
	double n;
    double v;
    double x;
} TADobra;

typedef double TChave;

TADobra *alocaobras(int n);

void desalocaobras(TADobra **obras) ;
TADobra *alocaobras(int n);
void desalocaobras(TADobra **obras);
double Pesquisa( TADobra *obras );

# endif
