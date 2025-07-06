#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ocorrencia.h"

//Preencher Lista de Ocorrencias:
Ocorrencia *criarListaOcorrencia(Matriz *matriz) 
{
    if (!matriz || !matriz->inicio) return NULL;

    Ocorrencia *listaOcorrencia = NULL;

    Elemento *linhaAtual = matriz->inicio;
    while (linhaAtual) 
    {
        Elemento *colunaAtual = linhaAtual;
        while (colunaAtual) 
        {
            char letra = tolower(colunaAtual->letra);
            if (letra >= 'a' && letra <= 'z') 
            {
                //Buscar ocorrência existente:
                Ocorrencia *ocorrencia = listaOcorrencia;
                Ocorrencia *anterior = NULL;
                while (ocorrencia && ocorrencia->letra != letra) 
                {
                    anterior = ocorrencia;
                    ocorrencia = ocorrencia->proxima;
                }

                //Criar nova ocorrência, se necessário:
                if (!ocorrencia) 
                {
                    ocorrencia = malloc(sizeof(Ocorrencia));
                    ocorrencia->letra = letra;
                    ocorrencia->coordenadas = NULL;
                    ocorrencia->proxima = NULL;
                    if (!listaOcorrencia)
                        listaOcorrencia = ocorrencia;
                    else
                        anterior->proxima = ocorrencia;
                }

                //Adicionar coordenada:
                Coordenada *nova = malloc(sizeof(Coordenada));
                nova->x = colunaAtual->linha;
                nova->y = colunaAtual->coluna;
                nova->proxima = NULL;

                if (!ocorrencia->coordenadas) 
                {
                    ocorrencia->coordenadas = nova;
                } else {
                    Coordenada *aux = ocorrencia->coordenadas;
                    while (aux->proxima) aux = aux->proxima;
                    aux->proxima = nova;
                }
            }
            colunaAtual = colunaAtual->leste;
        }
        linhaAtual = linhaAtual->sul;
    }

    return listaOcorrencia;
}

//Imprimir Ocorrencias (AJUSTAR SAIDA DE DADOS, APENAS TESTE)
void imprimirOcorrencias(Ocorrencia *listaOcorrencia) 
{
    while (listaOcorrencia) 
    {
        printf("Letra '%c': ", listaOcorrencia->letra);
        Coordenada *coordenada = listaOcorrencia->coordenadas;
        while (coordenada) 
        {
            printf("(%d, %d) ", coordenada->x, coordenada->y);
            coordenada = coordenada->proxima;
        }
        printf("\n");
        listaOcorrencia = listaOcorrencia->proxima;
    }
}

//Liberar Ocorrencias:
void liberarOcorrencias(Ocorrencia *listaOcorrencia) 
{
    while (listaOcorrencia) 
    {
        Coordenada *coordenadaAtual = listaOcorrencia->coordenadas;
        while (coordenadaAtual) 
        {
            Coordenada *coordenadaLiberar = coordenadaAtual;
            coordenadaAtual = coordenadaAtual->proxima;
            free(coordenadaLiberar);
        }
        Ocorrencia *ocorrenciaLiberar = listaOcorrencia;
        listaOcorrencia = listaOcorrencia->proxima;
        free(ocorrenciaLiberar);
    }
}
