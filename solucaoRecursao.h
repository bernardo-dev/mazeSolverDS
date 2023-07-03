#ifndef SOLUCAORECURSAO_H
#define SOLUCAORECURSAO_H

#include "percurso.h"
#include "labirinto.h"

// Retorna o menor percurso para a saida do labirinto
Percurso *resolverPorRecursao(Labirinto *);

// Funcao recursiva que explora o labirinto
void resolverLabirinto(Labirinto *, char **, int, int, Percurso *, Percurso *);

#endif // SOLUCAOREVERSAO_H
