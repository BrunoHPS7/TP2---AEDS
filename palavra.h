#ifndef PALAVRA_H
#define PALAVRA_H
#define TamanhoPalavra 100

#include <stdbool.h>

typedef struct Palavra
{
    char palavra[TamanhoPalavra];
    bool encontrada;
    struct Palavra *proxima;
}Palavra;

typedef struct Lista
{
    Palavra *primeiro;
    Palavra *ultimo;
    int tamanho;
}Lista;


//Criar Lista de Palavras:
Palavra criarLista(Palavra *palavra, int tamanahoLista);



#endif