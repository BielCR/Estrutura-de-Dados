#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alocaUpas (TUpa * upas){
    upas = malloc(sizeof(TUpa)); 
}

void desalocaUpas (TUpa** upas, int n){
    for(int i = 0; i < n; i++){
        free(upas[i]);
    }
    free(upas);
}

void ordena(TUpa **Upas, int n){
    int l, r, m;
    l = 0;
    r = sizeof(Upas);
    printf("%d", r);
}