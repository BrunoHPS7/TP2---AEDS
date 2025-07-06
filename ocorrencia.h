#ifndef OCORRENCIA_H
#define OCORRENCIA_H

#include "matriz.h"

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

#endif
