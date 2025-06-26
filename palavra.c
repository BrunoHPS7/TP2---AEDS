#include <stdio.h>
#include <stdlib.h>
#include "palavra.h"



//Criar Lista de Palavras:
Lista *criarLista(Lista *lista, int tamanhoLista)
{
    //Inicializar Tamanho da Lista:
    lista->tamanho = tamanhoLista;

    //Alocando o primeiro elemento da minha lista:
    lista->primeiro = (Palavra*) malloc(sizeof(Palavra));
    if(!lista->primeiro) return lista;

    lista->ultimo = lista->primeiro;
    lista->primeiro->proxima = NULL; //Não existe próximo

    for(int i=0; i<tamanhoLista; i++)
    {
        //Palavra Auxiliar:
        Palavra *novaPalavra = malloc(sizeof(Palavra));
        if(!novaPalavra) break;
        novaPalavra->proxima = NULL; //Ao acabar o laço, não temos uma proxima

        //Reorganizar Lista:
        lista->ultimo->proxima = novaPalavra;
        lista->ultimo = novaPalavra;
    }
    return lista;
}
