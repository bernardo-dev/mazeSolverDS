#include "matriz.h"
#include "posicao.h"
#include "percurso.h"
#include "labirinto.h"
#include "limits.h"
#include "solucaoRecursao.h"

Percurso *resolverPorRecursao(Labirinto *pLabirinto) {
  // Inicializa uma matriz do tamanho do labirinto,
  // sendo todas as posicoes nao vistadas
  char **pVisitados = alocarMatriz(pLabirinto->linhas, pLabirinto->colunas);

  for (int i = 0; i < pLabirinto->linhas; i++) {
    for (int j = 0; j < pLabirinto->colunas; j++) {
      pVisitados[i][j] = ' ';
    }
  }

  // Percurso a ser utilizado para o retorno da funcao acharSaida()
  // somando + 1 para evitar falha de segmentacao
  Percurso *pPercurso1 = alocarPercurso(pLabirinto->caminhosVazios + 1);
  pPercurso1->tamanho = UINT_MAX;

  // Percurso a ser utilizado para encontrar o menor trajeto para a saida
  // somando + 1 para evitar falha de segmentacao
  Percurso *pPercurso2 = alocarPercurso(pLabirinto->caminhosVazios + 1);
  pPercurso2->tamanho = 0;

  resolverLabirinto(pLabirinto, pVisitados, pLabirinto->comecoLinha,
                    pLabirinto->comecoColuna, pPercurso1, pPercurso2);

  desalocarMatriz(pVisitados, pLabirinto->linhas);
  desalocaPercurso(&pPercurso2);
  return pPercurso1;
}

void resolverLabirinto(Labirinto *pLabirinto, char **pVisitados, int linha,
                       int coluna, Percurso *pPercurso1, Percurso *pPercurso2) {
  // Verifica se a posicao está dentro dos limtes do labirinto
  if (linha < 0 || linha >= pLabirinto->linhas) {
    return;
  }
  if (coluna < 0 || coluna >= pLabirinto->colunas) {
    return;
  }

  // Verifica se é uma parede ou um ponto já visitado
  if (pLabirinto->pMatriz[linha][coluna] == '*' ||
      pVisitados[linha][coluna] == 'o') {
    return;
  }

  pVisitados[linha][coluna] = 'o';
  pPercurso2->pPosicoes[pPercurso2->tamanho].linha = linha;
  pPercurso2->pPosicoes[pPercurso2->tamanho].coluna = coluna;
  pPercurso2->tamanho++;

  // Copia o percurso 2 para o percurso 1 se a saida for encontrada
  if (linha == pLabirinto->saidaLinha && coluna == pLabirinto->saidaColuna) {
    if (pPercurso2->tamanho < pPercurso1->tamanho) {
      for (int i = 0; i < pPercurso2->tamanho; i++) {
        pPercurso1->pPosicoes[i].linha = pPercurso2->pPosicoes[i].linha;
        pPercurso1->pPosicoes[i].coluna = pPercurso2->pPosicoes[i].coluna;
      }
      pPercurso1->tamanho = pPercurso2->tamanho;
    }
  }

  // Tenta ir para DIREITA
  resolverLabirinto(pLabirinto, pVisitados, linha, coluna + 1, pPercurso1,
                    pPercurso2);

  // Tenta ir para BAIXO
  resolverLabirinto(pLabirinto, pVisitados, linha + 1, coluna, pPercurso1,
                    pPercurso2);

  // Tenta ir para ESQUERDA
  resolverLabirinto(pLabirinto, pVisitados, linha, coluna - 1, pPercurso1,
                    pPercurso2);

  // Tenta ir para CIMA
  resolverLabirinto(pLabirinto, pVisitados, linha - 1, coluna, pPercurso1,
                    pPercurso2);

  pVisitados[linha][coluna] = ' ';
  pPercurso2->tamanho--;
}
