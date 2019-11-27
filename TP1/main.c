#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

int main (int argc, char **argv) {
  int linha, coluna, dificuldade = 0;
  char jogoResolvido[100][100];
  char jogoLimpo[100][100];
  char comando [50];
  char argumento1, argumento2;


  if (argc > 1) {
    lerArquivoTexto(argv, jogoResolvido, &linha, &coluna);
    printf("Digite um comando: ");
    scanf("%s", comando);

    if (strcmp(comando, "resolver") == 0) { // mostrando o jogo resolvido.
      for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
          printf("%c ", jogoResolvido[i][j]);
        }
        printf("\n");
      }
    }


}
  else {
    printf("Escolha a dificuldade na qual deseja jogar:\n1-Fácil\n2-Média\n3-Difícil");
    printf("\n");

    scanf("%d", &dificuldade);
    printf("\n");
    getchar();
    escolhendoDificuldade(&linha, &coluna, dificuldade);
    matrizDoJogador(jogoLimpo, linha, coluna);
    geraBombasResolve(jogoResolvido, linha, coluna);

    do {
      printf("Digite um comando: ");
      scanf("%s", comando);
      getchar();
      if (strcmp(comando, "resolver") == 0) {
        for (int i = 0; i < linha; i++) {
          for (int j = 0; j < coluna; j++) {
            printf("%c ", jogoResolvido[i][j]);
          }
          printf("\n");
        }
      }

      if (strcmp(comando, "x") == 0) {
        scanf("%c%c", &argumento1, &argumento2);
        colocaBandeiras(jogoLimpo, argumento1, argumento2, linha, coluna);

      }

      if (strcmp(comando, "o") == 0) {
        scanf("%c%c", &argumento1, &argumento2);
        comparaMatrizes(jogoLimpo, jogoResolvido, argumento1, argumento2, linha, coluna);
      }

      if (strcmp(comando, "salvar") == 0) {
        salvaJogo(jogoResolvido, linha, coluna);
      }

    } while(strcmp(comando, "sair") != 0);

  }


return 0;
}
