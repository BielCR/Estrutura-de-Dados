#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alocaUpas (TUpa* upas, int n){
    upas = malloc (n * sizeof(TUpa));
}

void desalocaUpas (TUpa* upas){
    free(upas);
}

void ordena(){
    
}