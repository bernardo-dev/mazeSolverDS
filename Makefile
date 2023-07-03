CC = gcc
CFLAGS = -std=c99 -Wall

clean:
	rm -rf *.o
all: labirinto.o matriz.o posicao.o percurso.o solucaoRecursao.o main.o 
	$(CC) $(CFLAGS) labirinto.o matriz.o posicao.o percurso.o solucaoRecursao.o main.o -o exe
	rm -rf *.o
labirinto.o: labirinto.c labirinto.h
	$(CC) $(CFLAGS) -c labirinto.c

matriz.o: matriz.c matriz.h
	$(CC) $(CFLAGS) -c matriz.c

posicao.o: posicao.c posicao.h
	$(CC) $(CFLAGS) -c posicao.c

percurso.o: percurso.c percurso.h
	$(CC) $(CFLAGS) -c percurso.c

solucaoRecursao.o: solucaoRecursao.c solucaoRecursao.h
	$(CC) $(CFLAGS) -c solucaoRecursao.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

depurar: labirinto.o matriz.o posicao.o percurso.o solucaoRecursao.o main.o
	$(CC) $(CFLAGS) -g labirinto.o matriz.o posicao.o percurso.o solucaoRecursao.o main.o -o exe