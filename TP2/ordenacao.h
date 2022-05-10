# ifndef ordenacao_h
# define ordenacao_h

typedef struct{
	char* nome;
	int qPacientesUrgencia,qPacientesSem, qMedicos;
} TUpa;

//Alocando vetor de upas
void alocaUpas(TUpa *Upas, int n);

void desalocaUpas(TUpa *Upas);

void ordena (TUpa *Upas, int n)
# endif
