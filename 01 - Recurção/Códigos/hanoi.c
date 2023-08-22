#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char init, char dest, char aux)
/*
    Solução recursiva do problema das torres de Hanoi.
*/
{
    //Caso base
    if (n==1)
    {
        printf("Move disco 1 de %c para %c.\n",init,dest);
        return;
    }
    //Passo recursivo
    hanoi(n-1,init,aux,dest);
    printf("Move disco %d de %c para %c.\n",n,init,dest);
    hanoi(n-1,aux,dest,init);
}

int main()
{
    int n;
    printf("Digite o número de discos: ");
    scanf("%d",&n);

    char init = 'A';
    char dest = 'C';
    char aux = 'B';

    hanoi(n,init,dest,aux); 
}