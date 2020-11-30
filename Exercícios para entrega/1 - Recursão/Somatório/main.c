#include <stdio.h>

/*
    Entrada:
        A primeira e única linha de entrada possui um inteiro N.

    Saída:
        Faça uma função recursiva que receba um inteiro N como parâmetro e retorne o somatório todos os números de 1 até N.

    Restrições:
        As restrições são garantias dos intervalos mínimos e máximos dos casos de teste. Assim, não é preciso validar as entradas, a menos que seja solicitado.
            1 ≤ N ≤ 250.

    Exemplos:
        Entrada	Saída
           10	  55

    Média Ponderada:
        Considere que este exercício tem peso 1 (um) na média ponderada das notas dos exercícios.
*/

int somador();

int main()
{
    int recebeValor, contador=0;

    scanf(" %d", &recebeValor);
    if((recebeValor >= 1) && (recebeValor <= 250)){
        printf("%d", somador(recebeValor, contador));
    }

    return 0;
}

int somador(int i, int soma){
    soma += i;
    i--;

    if(i == 0){
        return soma;
    }

    soma = somador(i, soma);

    return soma;
}
