#include "labirinto.h"
#include "percurso.h"
#include "solucaoFila.h"
#include "solucaoRecursao.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
  clock_t inicio, fim;
  double tempoDecorrido;

  // Marca o inicio do tempo para execucao do programa
  inicio = clock();

  int linhas, colunas;
  char opcao;

  Labirinto *pLabirinto;

  scanf("%d %d", &linhas, &colunas);
  getc(stdin); // Para limpar a entrada
  scanf("%c", &opcao);
  getc(stdin); // Para limpar a entrada

  pLabirinto = alocarLabirinto(linhas, colunas);

  leLabirinto(pLabirinto);

  Percurso *pPercurso = NULL;

  if (opcao == 'r') {
    pPercurso = resolverPorRecursao(pLabirinto);

    printf("%d\n", pPercurso->tamanho - 1);

    imprimePercursoNoLabirinto(pLabirinto, pPercurso);
  } else if (opcao == 'f') {

    pPercurso = resolverPorBFS(pLabirinto);

    printf("%d\n", pPercurso->tamanho - 1);

    imprimePercursoNoLabirinto(pLabirinto, pPercurso);
  }

  desalocaPercurso(&pPercurso);
  desalocaLabirinto(pLabirinto);

  // Marca o fim do tempo para execucao do programa
  fim = clock();

  tempoDecorrido = (double)(fim - inicio) / CLOCKS_PER_SEC;

  if (argc > 1) {
    if (strcmp(argv[1], "tempo") == 0) {
      printf("Tempo de execução: %.6f segundos\n", tempoDecorrido);
    }
  }

  return 0;
}
