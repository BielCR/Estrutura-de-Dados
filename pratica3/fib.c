#include "fib.h"
#include<stdio.h>
#include<stdlib.h>

long long fibonacci(int i, TADFib *f){
    f->chamadas ++;
    if(i == 0)
        return 0;
    if (i==1)
        return 1;
    
    return (fibonacci(i -1, f) + fibonacci(i -2, f));
}

