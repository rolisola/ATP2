#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Elisa Yamashita Rodrigues, Renan Alves de Almeida, Vitor Marchini Rolisola

//funcao para identificar numero primo de forma recursiva
int primo_recursivo(unsigned int valor, unsigned int i){
    if(valor%2==0){
        return 0;
    }
    if(i == 1){
        return 1; //Chegou ao fim da recursao sem encontrar divisores
    }
    if(valor % i == 0){
        return 0; //Encontrou um divisor, nao e primo
    }
    return primo_recursivo(valor, i - 1);
}

//funcao para identificar numero primo de forma interativa
int primo_iterativo(unsigned int valor){
    for(unsigned  int i = 2 ; i <= sqrt(valor) ; i++){
        if(valor % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    unsigned int valor;

    do{
        printf("Digite um numero inteiro positivo, 0 para sair:\n");
        scanf("%u", &valor);

        //if( valor % 2 == 0){
          //  printf("%u e numero par\n", valor);
        //}else{
            /*modo iterativo*/
            if(primo_iterativo(valor)){
                printf("%u e um numero primo (iterativo)\n", valor);
            }else{
                printf("%u nao e um numero primo (iterativo)\n", valor);
            }

            /*modo recursivo*/
            if(primo_recursivo(valor, sqrt(valor))){
                printf("%u e um numero primo (recursivo)\n", valor);
            }else{
                printf("%u nao e um numero primo (recursivo)\n", valor);
            }
        //}
    }while(valor != 0);

    return 0;
}
