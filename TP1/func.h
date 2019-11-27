#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


void lerArquivoTexto(char **argv, char jogoResolvido[100][100], int *linha, int *coluna);
void escolhendoDificuldade(int *linha, int *coluna, int dificuldade);
void matrizDoJogador(char jogoLimpo[100][100], int linha, int coluna);
void geraBombasResolve(char jogoResolvido[100][100], int linha, int coluna);
void comparaMatrizes(char jogoLimpo[100][100], char jogoResolvido[100][100], char argumento1, char argumento2, int linha, int coluna);
void colocaBandeiras(char jogoLimpo[100][100],char argumento1, char argumento2, int linha, int coluna);
void salvaJogo(char jogoResolvido[100][100], int linha, int coluna);
