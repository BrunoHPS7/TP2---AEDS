#include <stdio.h>
#include <stdlib.h>
#include "palavra.h"



//Criar Lista de Palavras:
Lista *criarLista()
{
    //Alocar Memória para Lista:
    Lista *lista = malloc(sizeof(Lista));
    if(!lista) return NULL;
    
    //Capturar Tamanho da Lista
    int tamanhoLista;
    printf("Digite o tamanho de sua Lista de Palavras: ");
    scanf(" %d", &tamanhoLista);

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


//Preencher Lista de Palavras:
void preencherLista(Lista *lista)
{
    //Verifica se a Lista não está Vazia:
    if(!lista || lista->primeiro == lista->ultimo) return;

    //Começa no primeiro elemento real:
    Palavra *palavraNova = lista->primeiro->proxima;

    for(int i=0; i<lista->tamanho && palavraNova!=NULL; i++)
    {
        printf("Digite a palavra [%d]: ", i+1);
        scanf("%99s", palavraNova->palavra);
        palavraNova->encontrada = false;
        palavraNova = palavraNova->proxima;
    }
}


//Imprimir Lista de Palavras:
void imprimirLista(Lista *lista)
{
    //Verifica se a Lista não está Vazia:
    if(!lista || lista->primeiro == lista->ultimo) return;

    //Começa no primeiro elemento real:
    Palavra *palavraAtual = lista->primeiro->proxima;

    for(int i = 0; i < lista->tamanho && palavraAtual != NULL; i++)
    {
        printf("Palavra: %s | Início: (%d, %d) | Fim: (%d, %d)\n", 
               palavraAtual->palavra, palavraAtual->xi, palavraAtual->yi, palavraAtual->xf, palavraAtual->yf);
        palavraAtual = palavraAtual->proxima;
    }
}



//Desalocar Memória:
void desalocarLista(Lista *lista)
{
    //Verificar Lista Vazia:  
    if (!lista) return;

    //Começamos do Primeiro Elemento
    Palavra *atual = lista->primeiro;
    Palavra *proximo;

    //Desalocamos o atual, e fazemos atual virar o proximo enquanto o atual não for NULL
    while(atual != NULL)
    {
        proximo = atual->proxima;
        free(atual);
        atual = proximo;
    }

    // Zera a estrutura da lista
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
}