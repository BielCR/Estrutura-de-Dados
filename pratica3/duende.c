#include "duende.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct duendes{
  char nome[20];
  int idade, escalado;
};

struct times{
  TADduende *lider, 
  *entregador, 
  *piloto;
};

void lerQuantidade(int *qtd){
  int verificador = 0;
  while (verificador == 0){
    scanf("%d",qtd);

    if((*qtd) % 3 != 0){
      verificador = 0;
      printf("\nEntrada invalida, nao eh multiplo de 3\n");
    }else
       verificador = 1;
  }
}


TADduende *alocaDuendes(int qtd){
  TADduende *listDoende = malloc(qtd * sizeof(TADduende));
  return listDoende;
}

TADtime *alocaTimes(int qtd){
  TADtime *listTime = malloc(qtd * sizeof(TADtime));
  return listTime;
}

//Manter como especificado
void desalocaDuendes(TADduende **D){
  free(*D);
}

//Manter como especificado
void desalocaTimes(TADtime **T){
  desalocaDuendes(&(*T)->lider);
  desalocaDuendes(&(*T)->entregador);
  desalocaDuendes(&(*T)->piloto);
  free(*T);
}

//Manter como especificado
void lerDuendes(TADduende *D, int qtd){
  //ler nome e idade de cada duente
  for(int i = 0; i < qtd; i++){
    scanf("%s %d", D[i].nome, &D[i].idade);
    D[i].escalado = 0;
  }
}

//Manter como especificado
void escalarTimes(TADduende *D, TADtime *T, int qtd){
  int indice;
  //lider
  for(int i = 0; i < (qtd/3); i ++){
    indice = proximoMaisVelho(D, qtd);
    D[indice].escalado = 1;
    T[i].lider = &D[indice];
  }
  //entregador
  for(int i = (qtd/3); i <  (2 * (qtd/3)); i++){
    indice = proximoMaisVelho(D, qtd);
    D[indice].escalado = 1;
    T[i].entregador = &D[indice];
  }
  //piloto
  for (int i = (2 * (qtd/3)); i < qtd; i++){
    indice = proximoMaisVelho(D, qtd);
    D[indice].escalado = 1;
    T[i].piloto = &D[indice];
  }

}

int proximoMaisVelho(TADduende *D, int qtd){
  int indice = 0, maisVelho = 0;
  for (int i = 0; i < qtd; i++){
    if(D[i].idade > maisVelho && D[i].escalado == 0){
      indice = i;
      maisVelho = D[i].idade;
    }
  }
  return indice;
}

//Manter como especificado
void printTimes(TADtime *T, int qtd){
  for (int i = 0; i < qtd; i++){
    printf("Time %d\n",(i+1));
    printf("%s %d\n",T[i].lider->nome, T[i].lider->idade);
    printf("%s %d\n",T[i].entregador->nome, T[i].entregador->idade);
    printf("%s %d\n\n",T[i].piloto->nome, T[i].piloto->idade);
  }
  
}
