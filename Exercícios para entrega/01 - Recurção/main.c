#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Elisa Yamashita Rodrigues, Renan Alves de Almeida, Vitor Marchini Rolisola



//Funcao para identificar numero primo de forma recursiva
int primo_recursivo(unsigned int valor, unsigned int divisor){
    if(divisor*divisor > valor){
        return 1; //Chegou ao fim da recursao sem encontrar divisores
    }
    if( (valor%divisor == 0) && (divisor != 1) ){
        return 0; //Encontrou um divisor, nao e primo
    }
    return primo_recursivo(valor, divisor + 2); //Testa somente numeros impares
}

//Funcao para identificar numero primo de forma iterativa
int primo_iterativo(unsigned int valor){
    for(unsigned  int i = 3 ; i*i <= valor ; i += 2){ //Testa somente numeros impares
        if(valor % i == 0){
            return 0; //Encontrou um divisor, nao e primo
        }
    }
    return 1; //Nao encontrou divisor, e primo
}

int main(){
    unsigned int valor;

    do{
        printf("Digite um numero inteiro positivo, 0 para sair:\n");
        scanf("%u", &valor);

        if(valor == 2){ //Unico numero primo par
            printf("%u e numero primo\n", valor);
        } else if( ( (valor % 2 == 0) && (valor != 2) ) || (valor == 1) ){ //Verifica se o numero e par
            printf("%u nao e numero primo\n", valor);
        }else{

            /*modo iterativo*/
            if(primo_iterativo(valor)){
                printf("%u e um numero primo (iterativo)\n", valor);
            }else{
                printf("%u nao e um numero primo (iterativo)\n", valor);
            }

            /*modo recursivo*/
            if(primo_recursivo(valor, 1)){
                printf("%u e um numero primo (recursivo)\n", valor);
            }else{
                printf("%u nao e um numero primo (recursivo)\n", valor);
            }
        }

    }while(valor != 0);

    return 0;
}
