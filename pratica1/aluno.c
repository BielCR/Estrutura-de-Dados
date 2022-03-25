#include "aluno.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct aluno {
  float nota;
  char nome[20];
  char curso[20];
};

struct turma {
  int qtdAlunos;
  TAluno **alunos;
};

// Manter como especificado
void lerInfos(int *qtd, char *option) {
  scanf("%c\n%d", option, qtd);
}

// Manter como especificado
void alocaAluno(TAluno **pAluno) {
  *pAluno = malloc(sizeof(TAluno));
}

// Manter como especificado
void alocaTurma(TTurma **pTurma, int qtd) {
  *pTurma = malloc(sizeof(TTurma));
  (*pTurma)->alunos = malloc(qtd*sizeof(TAluno*));
  (*pTurma)->qtdAlunos = qtd;
  for (int i = 0; i < qtd; i++){
    alocaAluno(&(*pTurma)->alunos[i]);
  }
}

// Manter como especificado
void desalocaAluno(TAluno **pAluno) {
  free(*pAluno);
}

// Manter como especificado
void desalocaTurma(TTurma **pTurma) {
  for(int i = 0; i < (*pTurma)->qtdAlunos; i++){
    desalocaAluno(&(*pTurma)->alunos[i]);
  } 
  free(*pTurma);
}

// Manter como especificado
void lerTurma(TTurma *pTurma) {
  for(int i = 0; i <= pTurma->qtdAlunos; i++){
      scanf("%s %s %f", pTurma->alunos[i]->nome, pTurma->alunos[i]->curso, &pTurma->alunos[i]->nota);
  }
}

// Manter como especificado
float calcularMetrica(TTurma *pTurma, char* curso, char option) {
      float soma = 0;
      int count = 0;
      for(int i = 0; i < pTurma->qtdAlunos; i++){
        if(strcmp(curso, pTurma->alunos[i]->curso) == 0){
          soma += pTurma->alunos[i]->nota;
          count++;
        }
      }

      if(option == 'S'){
        return soma;
      }if(option == 'M'){
        return (soma / count);
      }
      return 0.0;
      
}

// Manter como especificado
void printMetrica(char* curso, float metrica, char option) {
  printf("A %s no curso de %s eh %.1f\n", option == 'S' ? "soma" : "media", curso, metrica);
}
