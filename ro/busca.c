#include "busca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


TADobra *alocaobras(int n) {
   //preencher
  TADobra *obras = malloc(n*sizeof(TADobra)); 
  return obras;

}

//Manter como especificado
void desalocaobras(TADobra **obras) {
  //preencher
  free(*obras);
}

int comparacao ( TADobra *obras, TChave h ){
  if (obras->x*(obras->x*2)*h > obras->v/obras->n ){
    return 1;
  }
  else if (fabs(obras->x*(obras->x*2)*h - obras->v/obras->n)< 0.000001){
    return 0;
  }
  else
    return -1;
}

double Pesquisa( TADobra *obras ){
  TChave h;
  double esq , dir ,result = -5;
 
  if(obras->n == 0|| obras->x == 0 ||obras->v == 0)
    return -1;
  
  esq = 0.0;
  dir = obras->x*3.0;
  
  h = (dir +esq )/2;
  
  while (result != 0)
  {
    result = comparacao(obras,h);
    if (result == 0)
      return h;
    if (result == 1 )
    {
      dir = h ;
      h = (esq + h)/2.0;
    }
    else{
      esq = h ;
      h = (dir + h)/2.0;}
    
    if (h==dir||h==esq||esq == dir)
      break;
      
  }

  //printf(" h: %lf  e 3x = %lf", h, (obras->x*3));
   
    return 1.0; 
}

