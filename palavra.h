#ifndef PALAVRA_H
#define PALAVRA_H
#define TamanhoPalavra 100

#include <stdbool.h>

typedef struct Palavra
{
    char palavra[TamanhoPalavra];
    bool encontrada;
    struct Palavra *proxima;
    int xi, yi, xf, yf; //X e Y Iniciais e Finais
}Palavra;

typedef struct Lista
{
    Palavra *primeiro;
    Palavra *ultimo;
    int tamanho;
}Lista;


//Criar Lista de Palavras:
Lista *criarLista();

//Preencher Lista de Palavras:
void preencherLista(Lista *lista);

//Imprimir Lista de Palavras:
void imprimirLista(Lista *lista);

//Desalocar Memória:
void desalocarLista(Lista *lista);


#endif