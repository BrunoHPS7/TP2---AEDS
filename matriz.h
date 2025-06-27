#ifndef MATRIZ_H
#define MATRIZ_H
#include "elemento.h"

typedef struct
{
    int linhas, colunas;
    Elemento *inicio;
}Matriz;

//Criar Matriz Nula (Linhas, Colunas):
Matriz *criarMatrizNula();

//Preencher Matriz:
Matriz *preencherMatriz(Matriz *matriz);

//Imprimit Matriz:
void imprimirMatriz(Matriz *matriz);

//Desalocar Matriz:
void desalocarMatriz(Matriz *matriz);

#endif