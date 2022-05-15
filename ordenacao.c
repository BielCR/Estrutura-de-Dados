
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"ordenacao.h"

TADupa *alocaUpas(TADupa *upas, int n){
	
   upas = malloc(n*sizeof(TADupa));//aloca espaço para um vetor de UPAS
   return upas;
}

TADupa *desalocaUpas(TADupa *upas){ //desaloca o vetor de UPAS
  free(upas);
  return upas;
}

void preencheVetor(TADupa *upas, int n){// preenche o vetor 
    for(int i = 0; i < n; i++){
        scanf("%s",upas[i].nome);// pega o nome da UPA
        scanf("%d %d %d %d", &upas[i].Upa.Emergencia, &upas[i].Upa.Urgencia, &upas[i].Upa.SemUrgencia, &upas[i].Upa.QntPlantonistas);//pega a situação da UPA
    }

}




void selectionsort (TADupa *vet, int tam){ // usando o metodo selection sort ordena o vetor de UPAS
    int i, j, max;
    TADupa aux;//auxiliar que vai receber a UPA durante a troca 
    for (i=0; i<=tam-1; i++){
        max = i;//recebe uma posição que vai ser comparada com o objetivo de achar o maior valor 
	for (j=i+1; j<=tam; j++){
            if (vet[j].Upa.Emergencia > vet[max].Upa.Emergencia)
	        max = j; // se a emergencia na posição J for maior que a na posição max ,então max recebe j
            else if (vet[j].Upa.Emergencia == vet[max].Upa.Emergencia) // caso tenham um numero igual de casos de emergencias vão ser comparados demais casos 
            {
                if (vet[j].Upa.Urgencia > vet[max].Upa.Urgencia)
                {
                    max = j;
                }
                 else if (vet[j].Upa.Urgencia == vet[max].Upa.Urgencia)
                 {
                    if (vet[j].Upa.SemUrgencia > vet[max].Upa.SemUrgencia)
                    {
                     max = j;
                    }
                    else if(vet[j].Upa.SemUrgencia == vet[max].Upa.SemUrgencia)
                    {
						if (vet[j].Upa.QntPlantonistas<vet[max].Upa.QntPlantonistas)
						{
							max = j;
						}
						
						else if (vet[j].Upa.QntPlantonistas == vet[max].Upa.QntPlantonistas){
                         
						 if(strcmp(vet[max].nome,vet[j].nome )>0){//se todos os casos forem iguais serão ordenados em ordem alfabetica
                             max = j;
                         }
						}
                    }
                }
                
            }
            
	}
	aux = vet[max];// auxiliar recebe o vetor com pior caso 
	vet[max] = vet[i]; // é feita a troca 
	vet[i] = aux;// o vetor na posição i recebe o auxiliar e assim ate a ordenção ser completa 
    }
}


void imprimeResultado(TADupa *upas, int n){//Imprime as UPAS ordenadas de acordo com a situação 
    for (int i = 0; i < n; i++){
        printf("%s %d %d %d %d\n", upas[i].nome, upas[i].Upa.Emergencia, upas[i].Upa.Urgencia, upas[i].Upa.SemUrgencia, upas[i].Upa.QntPlantonistas);
    }
}

