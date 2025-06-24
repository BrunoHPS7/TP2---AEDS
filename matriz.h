#ifndef MATRIZ_H
#include "elemento.h"

typedef struct
{
    int linhas, colunas;
    Elemento *inicio;
}Matriz;

//Criar Matriz Nula (Linhas, Colunas):
Matriz *criarMatrizNula(int linhas, int colunas);






#endif