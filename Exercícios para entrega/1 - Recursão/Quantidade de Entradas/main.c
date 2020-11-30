#include <stdio.h>

/*
    Entrada:
        A primeira e única linha de entrada possui vários inteiros, separados por espaço. O último inteiro é sempre 0, esta entrada é a única que não deve ser contabilizada no total de quantidade de entradas.

    Saída:
        Faça uma função recursiva, sem parâmetros e seguindo o protótipo abaixo, que usando scanfs receba entradas numéricas e retorne a quantidade de entradas que foram recebidas. Ao final, na main, printe essa quantidade.

    Protótipo:
        int entradas(void);

    Restrições:
        É garantido que a última entrada sempre será o valor 0 (zero).

    Exemplos:
        Entrada
            5 9 7 8 2 9 1 -10 0
        Saída
	        8
*/

int entradas(void);

int main()
{
    printf("%d", entradas());

    return 0;
}

int entradas(void){
    int contador=0, recebeValor;

    scanf(" %d", &recebeValor);
    if(recebeValor != 0){
        contador = entradas();
        contador++;
    }

    return contador;
}
