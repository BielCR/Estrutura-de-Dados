#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alocaUpas (TUpa ** upas, int qtd){
    *upas = (TUpa*) malloc(sizeof(TUpa) * qtd); 
    if (upas == NULL ) {
        printf ("Memoria insuficiente !\n");
        exit (1);
    }
}

void desalocaUpas (TUpa* upas, int n){

}

void ordena(TUpa *upas, int l, int r){
    int m;
    if(l<r){
        m = (l+r)/2;
        ordena(upas, l, m);
        ordena(upas, m+1, r);
        merge(upas,l,m,r);
    }

    
}

void merge(TUpa *upas, int l, int m, int r){
    int tamDireta, tamEsquerda, i, j, k;
    tamEsquerda = m - l +1;
    tamDireta = r - m;

    TUpa *vetEsq = NULL, *vetDir = NULL;
    alocaUpas(&vetEsq, tamEsquerda);
    alocaUpas(&vetDir, tamDireta);

    for(i = 0; i < tamEsquerda; i++){
        vetEsq[i] = upas[i+l];
    }
    for(j = 0; j < tamDireta; j++){
        vetDir[j] = upas[m + j + 1];
    }
    i = j = 0;
    for(k = l; k <= r+1; k++){
        if(i == tamEsquerda){
            upas[k] = vetDir[j++];
        }else if(j == tamDireta){
            upas[k] = vetEsq[i++];
        }else if(vetEsq[i].qPacientesEmer > vetDir[i].qPacientesEmer){
            upas[k] = vetEsq[i++];
        }else if(vetDir[i].qPacientesEmer > vetEsq[i].qPacientesEmer){
            upas[k] = vetDir[j++];
        }else if(vetEsq[i].qPacientesUrgencia > vetDir[i].qPacientesUrgencia){
            upas[k] = vetEsq[i++];
        }else if(vetDir[i].qPacientesUrgencia > vetEsq[i].qPacientesUrgencia){
            upas[k] = vetDir[j++];
        }else if(vetEsq[i].qPacientesSem > vetDir[i].qPacientesSem){
            upas[k] = vetEsq[i++];
        }else if(vetDir[i].qPacientesSem > vetEsq[i].qPacientesSem){
            upas[k] = vetDir[j++];
        }else if(vetEsq[i].qMedicos < vetDir[i].qMedicos){
            upas[k] = vetEsq[i++];
        }else if(vetDir[i].qMedicos < vetEsq[i].qMedicos){
            upas[k] = vetDir[j++];
        }else if(strcmp(vetEsq[i].nome, vetDir[i].nome) < 0){
            upas[k] = vetEsq[i++];
        }else{
            upas[k] = vetDir[j++];
        }
    }
    desalocaUpas(vetEsq, tamEsquerda);
    desalocaUpas(vetDir, tamDireta);

}