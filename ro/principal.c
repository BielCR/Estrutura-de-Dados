
#include <stdio.h>
#include<stdlib.h>
#include "busca.h"

int main(){

    int C;
  
    scanf("%d",&C);
    TADobra *obras = alocaobras(C);
    double *indice = malloc (sizeof (double)*C) ; 

    for (int  i = 0; i <C; i++)
    {
        scanf("%lf",&obras[i].n);
        scanf("%lf",&obras[i].v);
        scanf("%lf",&obras[i].x);

  
        indice[i] = Pesquisa(&obras[i]);
    }    

    for (int i = 0; i < C; i++)
    {
      if (indice[i]==-1)
        
            printf("Impossivel definir a altura do corte");
        else if ( indice[i]==1)
            printf("Altura do corte igual ou maior que a camara de exposicao");
        else
            printf("%.3lf",indice[i]);
        if (i != C )
            printf("\n");
       
    }
      desalocaobras(&obras);
    return 0 ;
}
