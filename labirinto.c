#include "matriz.h"
#include "posicao.h"
#include "labirinto.h"
#include <stdio.h>
#include <stdlib.h>

Labirinto *alocarLabirinto(int linhas, int colunas) {
  Labirinto *pLabirinto = (Labirinto *)malloc(sizeof(Labirinto));

  pLabirinto->pMatriz = alocarMatriz(linhas, colunas);

  pLabirinto->linhas = linhas;
  pLabirinto->colunas = colunas;
  pLabirinto->caminhosVazios = 0;

  return pLabirinto;
}

void desalocaLabirinto(Labirinto *pLabirinto) {
  int linhas = pLabirinto->linhas;

  desalocarMatriz(pLabirinto->pMatriz, linhas);

  // Desaloca a estrutura labirinto
  free(pLabirinto);
}

void leLabirinto(Labirinto *pLabirinto) {
  int linhas = pLabirinto->linhas;
  int colunas = pLabirinto->colunas;

  // Saida sempre no canto inferior direito
  pLabirinto->saidaLinha = linhas - 2;
  pLabirinto->saidaColuna = colunas - 1;

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      pLabirinto->pMatriz[i][j] = getc(stdin);
      if (pLabirinto->pMatriz[i][j] == ' ') {
        pLabirinto->caminhosVazios++;
      }
    }
    // Limpa o '\n' da última quebra de linha
    getc(stdin);
  }

  // Encontra a posicao incial do labirinto
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      if (pLabirinto->pMatriz[i][j] == 'M') {
        pLabirinto->comecoLinha = i;
        pLabirinto->comecoColuna = j;
        return;
      }
    }
  }
}

void imprimePercursoNoLabirinto(Labirinto *pLabirinto, Percurso *pPercurso) {
  int linhas = pLabirinto->linhas;
  int colunas = pLabirinto->colunas;
  int impresso = 0;
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      for (int k = 1; k < pPercurso->tamanho; k++) {
        if (i == pPercurso->pPosicoes[k].linha &&
            j == pPercurso->pPosicoes[k].coluna) {
          printf(".");
          impresso = 1;
          // k++;
        }
      }
      if (!impresso){
        printf("%c", pLabirinto->pMatriz[i][j]);
      }
      impresso = 0;
    }
    printf("\n");
  }
}

