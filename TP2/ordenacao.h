# ifndef ordenacao_h
# define ordenacao_h

typedef struct{
	char nome[50];
	int qPacientesUrgencia, qPacientesEmer, qPacientesSem, qMedicos;
} TUpa;

//Alocando vetor de upas
void alocaUpas(TUpa *Upas);

void desalocaUpas(TUpa **Upas, int n);

void ordena (TUpa **Upas, int n);
# endif
