#include <stdio.h>
int main()
{
    float s = 0.0, M[12][12], count = 0.0;
    char t;

    // Leitura do Char
    scanf("%c", &t);

    // Leitura da Matriz e Cálculos
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            scanf("%f", &M[i][j]);
        }
    }

    //calculos
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            if (j - i == 1 && i <= 4){
                do{
                    s += M[i][j];
                    count++;
                    j++;
                }while(i + j < 11);
            }
        }
    }

    // Impressão dos resultados
    if (t == 'S'){
        printf("%.1f", s);
    }
    else{
        printf("%.1f", (s / count));
    }
    return 0;
}
