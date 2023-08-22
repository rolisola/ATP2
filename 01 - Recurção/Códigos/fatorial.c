#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long int fatorial(unsigned long int n)
/*
    Implementação recursiva da função fatorial.
*/
{
    //Se n=1 ou n=0, retorna 1. (Casos base)
    if (n<2)
    {
        printf("1 \n");
        return 1;
    }
    //Passo recursivo.
    else
    {
        unsigned long int fat = n*fatorial(n-1);
        printf("%lu \n",fat); 
        return fat;
    }    
}

unsigned long int fatorial_iter(unsigned long int n)
/*
    Implementação iterativa da função fatorial.
*/
{
    //Inicialização da variável de saída
    unsigned long int fat = 1;
    //Casos triviais
    if (n<2)
    {
        printf("%lu",fat);
        return fat;
    }
    else
    {
        //Cálculo iterativo do fatorial
        for (int i=2; i<=n; i++)
        {
            fat = i*fat;
            printf("%lu \n",fat);
        }
        return fat;
    }
}


int main()
{
    //Entrada dos dados
    unsigned long int n;
    printf("Digite um inteiro não-negativo: ");
    scanf("%lu",&n);
    
    //Fatorial recursivo
    clock_t start = clock();
    unsigned long int fat = fatorial(n);
    clock_t end = clock();
    printf("Tempo de execução (recursivo): %f \n",
        (double)((end-start)/CLOCKS_PER_SEC));

    //Fatorial iterativo
    start = clock();
    fat = fatorial_iter(n);
    end = clock();
    printf("Tempo de execução (iterativo): %lf \n",
        (double)(end-start)/CLOCKS_PER_SEC);
    
    return 0;
}