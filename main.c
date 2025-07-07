#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"
#include "palavra.h"
#include "ocorrencia.h"

int main() 
{
    //Criar matriz de caça-palavras:
    Matriz *matriz = criarMatrizNula();
    if (!matriz) 
    {
        printf("Erro ao criar matriz!\n");
        return 1;
    }

    //Preencher matriz:
    preencherMatriz(matriz);

    //Criar lista de palavras:
    Lista *listaPalavras = criarLista();
    if (!listaPalavras) {
        printf("Erro ao alocar lista de palavras\n");
        desalocarMatriz(matriz);
        return 1;
    }

    //Preencher lista de palavras:
    preencherLista(listaPalavras);

    //Criar lista de ocorrências:
    Ocorrencia *ocorrencias = criarListaOcorrencia(matriz);

    //Buscar palavras na matriz
    buscarPalavras(matriz, listaPalavras);

    //Imprimir lista de palavras:
    imprimirLista(listaPalavras);

    //Liberações de Memórias:
    desalocarMatriz(matriz);
    desalocarLista(listaPalavras);
    liberarOcorrencias(ocorrencias);

    return 0;
}