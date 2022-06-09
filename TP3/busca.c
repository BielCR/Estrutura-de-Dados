#include "busca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

TInfo * alocaInfos(int quant){
    TInfo *inf = malloc(sizeof(TInfo)*quant); 
    return inf;
}

double buscaH(TInfo *infos)
{
    float resultado = 1, dir, esq;
    
    if(infos->nBlocos == 0|| infos->x == 0 ||infos->volume == 0)
        return -1;
  
    esq = 0.0;
    dir = 3.0 * infos->x;

    

    TAlt h;
    h = (dir + esq) / 2;

    while (resultado != 0){

        resultado = comparacao(infos, h);

        if (resultado == 0)
            return h;

        if (resultado == 1){
            dir = h;
            h = (esq + h) / 2.0;
        }else{
            esq = h;
            h = (dir + h) / 2.0;
        }

        if (h == dir || h == esq || esq == dir)
            break;
    }

    return 1;
}

int comparacao(TInfo *infos, TAlt h){
    float a = infos->x, b = infos->x * 2;
    if (a * b * h > infos->volume/infos->nBlocos){
        return 1;
    }else if (fabs(a * b * h - infos->volume/infos->nBlocos) < 0.000001){
        return 0;
    }else
        return -1;
}

void desalocaInfos(TInfo **infos)
{
    free(*infos);
}
