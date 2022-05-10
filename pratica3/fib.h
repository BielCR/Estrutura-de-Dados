# ifndef fib_h
# define fib_h

typedef struct{
  //preencher conforme a necessidade
  int chamadas;
  long long valor;
  int i;
} TADFib;

long long fibonacci(int i, TADFib *f);


# endif
