#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long int fibo(unsigned long int n)
/*
    Implementação recursiva da função Fibonnaci.
*/
{
    //Casos base
    if (n<2)
    {
        return n;
    }
    //Passo recursivo
    else
    {
        return fibo(n-1)+fibo(n-2);
    }
}

unsigned long int fibo_iter(unsigned long int n)
/*
    Implementação iterativa da função de Fibonacci
*/
{
    //Casos base
    if (n<2)
    {
        return n;
    }
    //Iterativo
    else
    {
        //Variáveis para armazenar resultado atual e dois antecessores
        int fibo = 1;
        int aux1 = 1; 
        int aux2 = 0;
        //Itera até n. Note que o caso n=2 é tratado como um caso base
        for (int i=3; i<=n; i++)
        {
            //Resultado de aux1 passa para antepenúltimo (f(n-2))
            aux2 = aux1;
            //Resultado de fibo passa para penúltimo (f(n-1))
            aux1 = fibo;
            //Calcula o último valor
            fibo = aux1+aux2;
        }
        return fibo;
    }
}

int main()
{
    unsigned long int n;
    printf("Entre com um inteiro positivo: \n");
    scanf("%lu",&n);

    //Fibonacci recursivo
    clock_t start = clock();
    printf("Chegou aqui.");
    unsigned long int f = fibo(n);
    clock_t end = clock();
    printf("Fibonacci de %lu: %lu \n",n,f);
    printf("Tempo de execução (recursivo): %f \n",
        (double)((end-start)/CLOCKS_PER_SEC));
    
    //Fibonacci iterativo
    start = clock();
    f = fibo_iter(n);
    end = clock();
    printf("Fibonacci de %lu: %lu \n",n,f);
    printf("Tempo de execução (iterativo): %f \n",
        (double)((end-start)/CLOCKS_PER_SEC));

    return 0;
}