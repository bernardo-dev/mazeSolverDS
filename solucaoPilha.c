#include "solucaoPilha.h"
#include "estruturaDeDados.h"
#include "labirinto.h"
#include "limits.h"
#include "matriz.h"
#include "percurso.h"
#include "posicao.h"
#include <stdio.h>

bool estaValido(Labirinto *pLabirinto, char **pVisitados, int linha,
                int coluna) {

  // Verifica se a posicao está dentro dos limites do labirinto
  if (linha < 0 || linha >= pLabirinto->linhas)
    return false;
  if (coluna < 0 || coluna >= pLabirinto->colunas)
    return false;

  // Verifica se é uma parede ou um ponto já visitado
  if (pLabirinto->pMatriz[linha][coluna] == '*' ||
      pVisitados[linha][coluna] == 'o') {
    return false;
  }

  return true;
}

Percurso *resolverPorDFS(Labirinto *pLabirinto) {
  // Inicializa uma matriz do tamanho do labirinto,
  // sendo todas as posicoes nao vistadas
  char **pVisitados = alocarMatriz(pLabirinto->linhas, pLabirinto->colunas);

  for (int i = 0; i < pLabirinto->linhas; i++) {
    for (int j = 0; j < pLabirinto->colunas; j++) {
      pVisitados[i][j] = ' ';
    }
  }

  Percurso *pPercurso = alocarPercurso(pLabirinto->caminhosVazios + 1);
  pPercurso->tamanho = 0;

  // Cria a pilha
  Lista *pPilha = pilhaInicia();

  // Obtém a posição inicial do labirinto
  Posicao posicaoInicial;
  posicaoInicial.linha = pLabirinto->comecoLinha;
  posicaoInicial.coluna = pLabirinto->comecoColuna;

  // Empilha a posição inicial
  pilhaPush(pPilha, posicaoInicial);

  Posicao posicaoAtual;
  Posicao proximaPosicao;
  int linha, coluna;

  while (!pilhaEhVazia(pPilha)) {
    pilhaPop(pPilha, &posicaoAtual); // Desempilha a posiçao atual

    linha = posicaoAtual.linha;
    coluna = posicaoAtual.coluna;

    pVisitados[linha][coluna] = 'o';

    pPercurso->pPosicoes[pPercurso->tamanho].linha = linha;
    pPercurso->pPosicoes[pPercurso->tamanho].coluna = coluna;
    pPercurso->tamanho++;

    // Verifica se a posição atual é a saída do labirinto
    if (posicaoAtual.linha == pLabirinto->saidaLinha &&
        posicaoAtual.coluna == pLabirinto->saidaColuna) {
      desalocarMatriz(pVisitados, pLabirinto->linhas);
      pilhaLibera(&pPilha);
      return pPercurso;
    }

    // DIREITA
    if (estaValido(pLabirinto, pVisitados, linha, coluna + 1)) {
      proximaPosicao.linha = linha;
      proximaPosicao.coluna = coluna + 1;

      pilhaPush(pPilha, proximaPosicao);
    }

    // BAIXO
    if (estaValido(pLabirinto, pVisitados, linha + 1, coluna)) {
      proximaPosicao.linha = linha + 1;
      proximaPosicao.coluna = coluna;

      pilhaPush(pPilha, proximaPosicao);
    }

    // ESQUERDA
    if (estaValido(pLabirinto, pVisitados, linha, coluna - 1)) {
      proximaPosicao.linha = linha;
      proximaPosicao.coluna = coluna - 1;

      pilhaPush(pPilha, proximaPosicao);
    }

    // CIMA
    if (estaValido(pLabirinto, pVisitados, linha - 1, coluna)) {
      proximaPosicao.linha = linha - 1;
      proximaPosicao.coluna = coluna;

      pilhaPush(pPilha, proximaPosicao);
    }
  }

  desalocarMatriz(pVisitados, pLabirinto->linhas);
  pilhaLibera(&pPilha);

  return pPercurso;
}