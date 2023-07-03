#include "solucaoFila.h"
#include "matriz.h"
#include "posicao.h"
#include "percurso.h"
#include "labirinto.h"
#include "limits.h"

Percurso *resolverPorBFS(Labirinto *pLabirinto){
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

  
  
  return pPercurso;
}
