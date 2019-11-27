#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void lerArquivoTexto(char **argv, char jogoResolvido[100][100], int *linha, int *coluna){
  FILE *arquivo = fopen(argv[1], "r");

  if (arquivo == NULL) {
    exit (1);
  }

  fscanf(arquivo, "%d %d", linha, coluna);

  while (!feof(arquivo)) { //lendo enquanto não chegar ao fim do arquivo.

    for (int i = 0; i < *linha; i++) {
      for (int j = 0; j < *coluna; j++) {
        fscanf(arquivo, "%c ", &jogoResolvido[i][j]);
      }
    }
  }

  fclose(arquivo);

  //imprimindo a matriz na tela para o jogador
  char jogoLimpo[100][100];
  for (int i = 0; i < *linha; i++) {
    for (int j = 0; j < *coluna; j++) {
      jogoLimpo[i][j] = '-';
    }
  }

  for (int i = 0; i < *linha; i++) {
    for (int j = 0; j < *coluna; j++) {
      printf("%c ", jogoLimpo[i][j]);
    }
    printf("\n");
  }
}
void escolhendoDificuldade(int *linha, int *coluna, int dificuldade){ //função se autodenomina perfeitamente.

  if (dificuldade == 1) {
    *linha = 9;
    *coluna = 9;
  }
  if (dificuldade == 2) {
    *linha = 16;
    *coluna = 16;
  }
  if (dificuldade == 3) {
    *linha = 26;
    *coluna = 26;
  }
}
void matrizDoJogador(char jogoLimpo[100][100], int linha, int coluna){ //função utilizada para imprimir a matriz para o jogador.
  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      jogoLimpo[i][j] = '-';
    }
  }

  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      printf("%c ", jogoLimpo[i][j]);
    }
    printf("\n");
  }

}
void geraBombasResolve(char jogoResolvido[100][100], int linha, int coluna){
  int aux; //variável auxiliar parar percorrer a matriz colocando números aleatórios
  srand(time(NULL));
//inicializando a matriz com números '0'.
  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      jogoResolvido[i][j] = '0';
    }
  }

//Aleatorizando as bombas pela matriz.
  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      aux = rand() % 100;
      if (aux < 30) {
        jogoResolvido[i][j] = 'x';
      }
    }
  }

  //resolvendo o jogo.
   for (int i = 0; i < linha; i++) {
     for (int j = 0; j < coluna; j++) {
       if (jogoResolvido[i][j] == 'x') {
         for (int k = i - 1; k <= i + 1; k++) {
           for (int l = j - 1; l <= j + 1; l++) {
             if ((k >= 0 && k < linha )&& (l >= 0 && l < coluna )) { //impedindo o programa de verificar espaços fora da matriz.
               if (jogoResolvido[k][l] != 'x') {
                 jogoResolvido[k][l] ++;
               }
             }
           }
         }
      }
    }
  }
}

void comparaMatrizes(char jogoLimpo[100][100], char jogoResolvido[100][100], char argumento1, char argumento2, int linha, int coluna){
  int primeira = (int) (argumento1 - 'A');
  int segunda = (int) (argumento2 - 'A');
  printf("%d\n", argumento1);

  if (jogoResolvido[primeira][segunda] != 'x') {
    jogoLimpo[primeira][segunda] = jogoResolvido[primeira][segunda];

    for (int i = 0; i < linha; i++) {
      for (int j = 0; j < coluna; j++) {
        printf("%c ", jogoLimpo[i][j]);
      }
      printf("\n");
    }
  }


  if (jogoResolvido[primeira][segunda] == 'x') {
    jogoLimpo[primeira][segunda] = jogoResolvido[primeira][segunda];

    for (int i = 0; i < linha; i++) {
      for (int j = 0; j < coluna; j++) {
        printf("%c ", jogoLimpo[i][j]);
      }
      printf("\n");
    }
  }
}
