#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double mag(double m_0, double beta, int t)
/*
    Cálculo recursivo da magnetização do modelo Ising
*/
{
    if (t==0)
    {
        return m_0;
    }
    else
    {
        return tanh(beta*mag(m_0,beta,t-1)); 
    }
}

double mag_iter(double m_0, double beta, int t)
/*
    Cálculo iterativo da magnetização do modelo Ising
*/
{
    //Caso trivial
    if (t==0)
    {
        return m_0;
    }
    //Procedimento iterativo
    else
    {
        //Variável do último resultado
        double m;
        //Variável do penúltimo resultado
        double aux_m = m_0;
        //Cálculo iterativo da magnetização
        for (int i=0; i<t; i++)
        {
            m = tanh(beta*aux_m);
            aux_m = m;
        }

        return m;
    }
}

int main()
{
    //Entrada dos dados
    int t;
    printf("Digite o número de iterações: ");
    scanf("%i",&t);
    
    double beta;
    printf("Digite o valor do parâmetro beta: ");
    scanf("%lf",&beta);
    
    double m_0;
    printf("Digite o valor inicial da magnetização: ");
    scanf("%lf",&m_0);
    while (m_0<-1 || m_0>1)
    {
        printf("Erro: valor da magnetização precisa estar entre -1 e 1.\n");
        printf("Digite o valor inicial da magnetização: ");
        scanf("%lf",&m_0);
    }

    //Mag recursivo
    clock_t start = clock();
    double m = mag(m_0,beta,t);
    clock_t end = clock();
    printf("Valor final da magnetização (recursiva): %lf \n",m);
    printf("Tempo de execução (recursivo): %lf \n",
        (double)((end-start)/CLOCKS_PER_SEC));

    //Fatorial iterativo
    start = clock();
    m = mag_iter(m_0,beta,t);
    end = clock();
    printf("Valor final da magnetização (iterativa): %lf \n",m);
    printf("Tempo de execução (iterativo): %lf \n",
        (double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}