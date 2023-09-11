#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matriz.h"

// REBECA MASCARA FURTADO, ELISA YAMASHITA RODRIGUES, VITOR MARCHINI ROLISOLA

/*------------------------------------------------------------------------------
    Funções da matriz com ponteiro duplo
------------------------------------------------------------------------------*/

mtz new_mtz(int lin, int col, float init)
/*
    Inicializa mtz.
*/
{
    mtz m;

    if (lin>0 && col>0)
    {
        m.lin = lin; m.col = col;
        //Alocação das linhas: aloca ponteiros simples
        m.data = malloc(lin*sizeof(float *));
        if (m.data!=NULL)
        {
            //Alocação das colunas: aloca variável comum
            for (int i=0; i<lin; i++)
            {
                m.data[i] = malloc(col*sizeof(float));
                if (m.data[i]!=NULL)
                    //Inicialização das entradas
                    for (int j=0; j<col; j++)
                    {
                        m.data[i][j] = init;
                    }
                else
                {
                    printf("Memória insuficiente para alocação.");
                }
            }   
        }
        else
        {
            printf("Memória insuficiente para alocação.");
        }
    }
    else
    {
        m.lin = 0; m.col = 0;
        m.data = NULL;
    }

    return m;
}

bool mtz_is_null(mtz m)
/*
    Checa se alguma das alocações de mtz falhou.
*/
{
    if (m.data==NULL)
    {
        return true;
    }
    for (int i=0; i<m.lin; i++)
        if (m.data[i]==NULL)
        {
            return true;
        }
    return false;
}

void free_mtz(mtz *m)
/*
    Libera memória de mtz. Para cada malloc, é feito um free.
*/
{
    if (m->data!=NULL)
    {
        for (int i=0; i<m->lin; i++)
        {
            if (m->data[i]!=NULL)
            {
                free(m->data[i]);
            }
        }
        free(m->data); 
        m->data = NULL;
    }
}

void mtz_read(mtz m)
/*
    Pede para usuário inserir elementos na matriz.
*/
{
    if (mtz_is_null(m))
    {
        printf("Matriz é NULL.");
        return;
    }

    for (int i=0; i<m.lin; i++)
        for (int j=0; j<m.col; j++)
        {
            printf("Digite a entrada [%d,%d]: ",i,j);
            scanf("%f",&m.data[i][j]);
        }
}

void mtz_print(mtz m)
/*
    Imprime na tela os elementos da matriz.
*/
{
    if (mtz_is_null(m))
    {
        printf("Matriz é NULL.");
        return;
    }

    for (int i=0; i<m.lin; i++)
    {
        for (int j=0; j<m.col; j++)
        {
            printf("%f ",m.data[i][j]);
        }
        printf("\n");
    }
}

mtz soma_mtz(mtz A, mtz B)
/*
    Soma de duas matrizes
*/
{
    if (!mtz_is_null(A) && !mtz_is_null(B))
    {
        if (A.lin==B.lin && A.col==B.col)
        {
            mtz res = new_mtz(A.lin,A.col,0);
            if (mtz_is_null(res))
            {
                printf("Memória insuficiente para matriz de resultado.");
                return new_mtz(0,0,0);
            }
            for (int i=0; i<A.lin; i++)
                for (int j=0; j<A.col; j++)
                {
                    res.data[i][j] = A.data[i][j]+B.data[i][j];
                }
            return res;
        }
        printf("Matrizes incompatíveis para soma.");
        return new_mtz(0,0,0);
    }
    printf("Matriz de entrada é null.");
    return new_mtz(0,0,0);
}

mtz ppscalar_mtz(mtz A,float x){
    /*
    multiplicacao de uma matriz por um escalar
    */
    if (!mtz_is_null(A))
    {
        mtz res = new_mtz(A.lin,A.col,0);
        if (mtz_is_null(res))
        {
            printf("Memória insuficiente para matriz de resultado.");
            return new_mtz(0,0,0);
        }
        for (int i=0; i<A.lin; i++)
            for (int j=0; j<A.col; j++)
            {
                res.data[i][j] = A.data[i][j] * x;
            }
        return res;
    }
    printf("Matriz de entrada é null.");
    return new_mtz(0,0,0);
}

mtz mul_mtz(mtz A, mtz B){
    /*
    produto entre duas matrizes
    */
    if (!mtz_is_null(A) && !mtz_is_null(B))
    {
        if (A.col==B.lin)
        {
            mtz res = new_mtz(A.lin,B.col,0);
            if (mtz_is_null(res))
            {
                printf("Memória insuficiente para matriz de resultado.");
                return new_mtz(0,0,0);
            }
            for (int i =0; i < A.lin; i++)
                for (int j =0; j < B.col; j++)
                {
                    res.data[i][j] = 0;
                    for (int k = 0; k < A.col; k++){
                        res.data[i][j] += A.data[i][k]* B.data[k][j];
                    }
                    
                }
            return res;
        }
        printf("Matrizes incompatíveis para soma.");
        return new_mtz(0,0,0);
    }
    printf("Matriz de entrada é null.");
    return new_mtz(0,0,0);
}

mtz transposta_mtz(mtz A){
    /*
    faz a transposta da matriz
    */
    if (!mtz_is_null(A))
    {
        mtz res = new_mtz(A.col,A.lin,0);
        if (mtz_is_null(res))
        {
            printf("Memória insuficiente para matriz de resultado.");
            return new_mtz(0,0,0);
        }
        for (int i =0; i < A.col; i++){
            for (int j =0; j < A.lin; j++){
                res.data[i][j] = A.data[j][i];
            }
        }
        return res;
    }
    printf("Matriz de entrada é null.");
    return new_mtz(0,0,0);
}