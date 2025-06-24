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

#endif