#include <stdio.h>
#include "elemento.h"
#include "matriz.h"

//Criar Matriz Nula (I,J):
Matriz *criarMatrizNula(int linhas, int colunas)
{
    //Alocar memória para a Matriz:
    Matriz *matriz = malloc(sizeof(Matriz));
    if (!matriz) return NULL;

    //Definir dimensões:
    matriz->linhas = linhas;
    matriz->colunas = colunas;

    //Instanciar Elemento Inicial:
    Elemento *elementoInicial = malloc(sizeof(Elemento));
    if(!elementoInicial)
    {
        free(matriz);
        return NULL;
    }
    
    //Definir Elemento Inicial:
    elementoInicial->linha = 0;
    elementoInicial->coluna = 0;
    elementoInicial->letra = '-'; //Irei usar "-" para simular o elemento vazio

    //Apontadores NULL:
    elementoInicial->norte = NULL;
    elementoInicial->sul = NULL;
    elementoInicial->leste = NULL;
    elementoInicial->oeste = NULL;
    elementoInicial->nordeste = NULL;
    elementoInicial->noroeste = NULL;
    elementoInicial->suldeste = NULL;
    elementoInicial->sudoeste = NULL;

    //Primeiro Elemeto de Matriz é o Elemento Inicial:
    matriz->inicio = elementoInicial;

    //Retorna Matriz com primeiro Elemento criado e vazio, além de definir suas dimensões
    return matriz;
}