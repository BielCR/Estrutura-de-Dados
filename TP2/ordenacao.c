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

void desalocaUpas (TUpa** upas, int n){
    free(*upas);
}

void lerUpas (TUpa * upas, int n){
    for(int i = 0; i < n; i++){
        scanf("%s %d %d %d %d", upas[i].nome, &upas[i].qPacientesEmer, &upas[i].qPacientesUrgencia, &upas[i].qPacientesSem, &upas[i].qMedicos);
    }
}


void shellsort(TUpa * upas, int n){
    //descobrindo o maior valor de h
    int h, j;
    TUpa aux;
    for(h = 1; h < n; h++){
        h = 3 * h + 1;
    }
    do{
        h = (h-1)/3;
        for(int i = h; i < n; i++){
            aux = upas[i];
            j = i;
            while (compara(upas[j - h], aux) == 1){
                upas[j] = upas[j - h];
                j = j -h;
                if(j < h)
                    break;
            }
            upas[j] = aux;
        }
    }while(h != 1);
}

int compara(TUpa t1, TUpa t2){
    if(t1.qPacientesEmer > t2.qPacientesEmer)
        return 1;
    else if(t2.qPacientesEmer > t1.qPacientesEmer)
        return 2;
    else if(t1.qPacientesUrgencia > t2.qPacientesUrgencia)
        return 1;
    else if(t2.qPacientesUrgencia > t1.qPacientesUrgencia)
        return 2;
    else if(t1.qPacientesSem > t2.qPacientesSem)
        return 1;
    else if(t2.qPacientesSem > t1.qPacientesSem)
        return 2;
    else if(t1.qMedicos < t2.qMedicos)
        return 1;
    else if(t2.qMedicos < t1.qMedicos)
        return 2;
    else if(strcmp(t1.nome, t2.nome) < 0)
        return 1;
    else if(strcmp(t1.nome, t2.nome) > 0)
        return 2;
    else
        return 3;
}

void imprime(TUpa *upas, int n){
    for(int i = n - 1; i >= 0; i--){
        printf("%s %d %d %d %d\n", upas[i].nome, upas[i].qPacientesEmer, upas[i].qPacientesUrgencia, upas[i].qPacientesSem, upas[i].qMedicos);
    }
}

/*mergesort
void ordena(TUpa *upas, int l, int r){
    int m = 0;
    if(l<r){
        m = (l+r)/2;
        //printf("\n m= %d, l= %d, r= %d", m, l, r);
        ordena(upas, l, m);
        ordena(upas, (m+1), r);
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
    for(k = l; k <= r; k++){
        if(i == tamEsquerda){
            upas[k] = vetDir[j++];
        }else if(j == tamDireta){
            upas[k] = vetEsq[i++];
        }else if(compara(vetEsq[i], vetDir[j]) == 1){
            upas[k] = vetEsq[i];
            i++;
        }else if(compara(vetEsq[i], vetDir[j]) == 2){
            upas[k] = vetDir[j];
            j++;
        }
   }
    desalocaUpas(&vetEsq, tamEsquerda);
    desalocaUpas(&vetDir, tamDireta);

}
*/