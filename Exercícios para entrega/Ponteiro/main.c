#include <stdio.h>
#include <stdlib.h>


double funcao_1(int n){
    double calculo;

    calculo = (double)1/(double)((4*n + 1)*(4*n + 3));
    //printf("%f\n", calculo);
    return calculo;
}

double funcao_2(int n){
    double calculo;

    calculo = (double)1/(double)((n + 1)*(n + 1));

    return calculo;
}

double funcao_3(int n){
    double calculo;

    calculo = (double)1/(double)((2*n + 1)*(2*n + 1));

    return calculo;
}

double soma(double (*funcao)(int), int argumento){
    double soma = 0;

    for (int i = 0; i <= argumento; i++) {
        soma += funcao(i);
    }

    return soma;
}

int main()
{
    int argumento;
    double resultado;

    printf("1:  1/((4n+1)(4n+3))\n");
    printf("2:  1/((n+1)^2)\n");
    printf("3:  1/((2n+1)^2)\n\n");;

    printf("Digite o valor de N: \n");
    scanf("%d", &argumento);

    resultado = soma(funcao_1, argumento);
    printf("Resultado 1: %f\n", resultado);

    resultado = soma(funcao_2, argumento);
    printf("Resultado 2: %f\n", resultado);

    resultado = soma(funcao_3, argumento);
    printf("Resultado 3: %f\n", resultado);

    return 0;
}
