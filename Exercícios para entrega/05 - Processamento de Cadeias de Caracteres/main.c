#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>
#include "img.h"

// Imprime helper na tela
void helper(){
    printf("FUNCOES PGM \n");
    printf("   limiar ArquivoDeEntrada x ArquivoDeSaida -> executa a funcao limiar, com x igual a um \n valor inteiro do limiar.\n");
    printf("   inversa ArquivoDeEntrada ArquivoDeSaida -> executa a funcao inversa\n");
}

void cmd_invalido(){
    printf("Comando invalido. Digite help para ajuda.(dentro do programa)");
}

int main(int argc, char *argv[])
// linha de comando com o usuario
{
    setlocale(LC_ALL, "");

    if (argc == 5 || argc == 4 || argc == 2){
        if (argc == 5){
            if (strcmp(argv[1], "limiar") == 0){
                int lim;
                sscanf(argv[3], "%d", &lim);
                FILE *pgm = fopen(argv[2], "r");
                if (pgm != NULL){
                    imgb I = read_img(pgm);
                    if (lim < 0 || lim > I.cinza){
                        printf("Valor limiar invalido");
                    } else{
                        limiar(&I, lim);
                        write_imgb(argv[4], &I);
                        free_imgb(&I);
                        fclose(pgm);
                    }
                } else{
                    printf("Falha na leitura do arquivo.");
                }
            } else{
                cmd_invalido();
            }
        }

        if (argc == 4){
            if (strcmp(argv[1], "inversa") == 0){
                FILE *pgm = fopen(argv[2], "r");
                if (pgm != NULL){
                    imgb I = read_img(pgm);
                    inversa(&I);
                    write_imgb(argv[3], &I);
                    free_imgb(&I);
                    fclose(pgm);
                }
                else{
                    printf("Falha na leitura do arquivo.");
                }
            } else{
                cmd_invalido();
            }
        }

        if (argc == 2){
            if (strcmp(argv[1], "help") == 0){
                helper();
                return 0;
            } else{
                cmd_invalido();
            }
        }
    } else{
        cmd_invalido();
    }

    return 0;
}