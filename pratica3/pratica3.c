#include "fib.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
    //adicionar variaveis conforme necessidade
    TADFib *f;
    int n, i;

    //fazer a leitura do numero de casos de teste dentro do main
    scanf("%d", &n);
    f = (TADFib*)malloc(n * sizeof(TADFib));

    //ler o caso de teste e processar antes de ler o proximo
    for(int j = 0; j < n; j++){
        f[j].chamadas = 0;
        scanf("%d", &i);
        f[j].i = i;
        f[j].valor = fibonacci(i, &f[j]);
    }

    //imprimir a resposta no formato adequado
    for(int j = 0; j < n; j++)
        printf("fib(%d) = %d chamadas = %lld\n",f[j].i, f[j].chamadas-1,f[j].valor);
    

    free(f);
    return 0;//nao remova
}
