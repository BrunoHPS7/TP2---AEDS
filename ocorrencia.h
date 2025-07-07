#ifndef OCORRENCIA_H
#define OCORRENCIA_H

#include "matriz.h"
#include "palavra.h"

typedef struct Coordenada 
{
    int x;
    int y;
    struct Coordenada *proxima;
} Coordenada;

typedef struct Ocorrencia 
{
    char letra;
    Coordenada *coordenadas;
    struct Ocorrencia *proxima;
} Ocorrencia;

//Criar Lista de Ocorrencias:
Ocorrencia *criarListaOcorrencia(Matriz *matriz);

//Imprimir Ocorrencias:
void imprimirOcorrencias(Ocorrencia *lista);

//Liberar Ocorrencias:
void liberarOcorrencias(Ocorrencia *lista);

//Seguir Direção:
Elemento *seguirDirecao(Elemento *atual, int direcao);

//Buscar Palavras:
void buscarPalavras(Matriz *matriz, Lista *listaPalavras);

#endif
