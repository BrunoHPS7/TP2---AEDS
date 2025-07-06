#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"
#include "palavra.h"
#include "ocorrencia.h"

int main() 
{
    //Criar matriz de caça-palavras
    Matriz *matriz = criarMatrizNula();
    if (!matriz) {
        printf("Erro ao criar matriz!\n");
        return 1;
    }

    printf("Matriz criada com %d linhas e %d colunas\n", matriz->linhas, matriz->colunas);

    //Preencher matriz
    preencherMatriz(matriz);

    //Imprimir matriz
    imprimirMatriz(matriz);

    //Criar lista de palavras
    Lista *listaPalavras = criarLista();
    if (!listaPalavras) {
        printf("Erro ao alocar lista de palavras\n");
        desalocarMatriz(matriz);
        return 1;
    }

    //Preencher lista de palavras
    preencherLista(listaPalavras);

    //Imprimir lista
    imprimirLista(listaPalavras);

    //Criar lista de ocorrências (baseado na matriz)
    Ocorrencia *ocorrencias = criarListaOcorrencia(matriz);

    //Imprimir lista de ocorrências
    imprimirOcorrencias(ocorrencias);

    //Liberações
    desalocarMatriz(matriz);
    desalocarLista(listaPalavras);
    liberarOcorrencias(ocorrencias);

    return 0;
}



/* MAIN ANTIGO:
// Criar Matriz (Caça-Palavras)
    Matriz *matriz = criarMatriz();
    if (!matriz) {
        printf("Erro ao criar matriz!\n");
        return 1;
    }

    // Preencher Matriz (Caça-Palavras)
    preencherMatriz(matriz);

    // Criar Matriz de Coordenadas
    MatrizCoordenada *matrizCoordenadas = criarMatrizCoordenadas(matriz);

    // Alocar Matriz de Ocorrencias
    MatrizOcorrencia *matrizOcorrencia = alocarMatrizOcorrencia();

    // Preencher Matriz Ocorrencia
    preencherMatrizOcorrencia(matriz, matrizCoordenadas, matrizOcorrencia);

    // Criar Palavras
    Palavra *palavras = criarPalavras();

    // Chamar Buscar Palavras
    buscarPalavras(matriz, matrizOcorrencia, palavras);

    // Imprimir Palavras e Coordenadas
    imprimirPalavrasComCoordenadas(palavras);

    //Liberar Memórias Alocadas
    desalocarMatriz(matriz);
    desalocarMatrizCoordenada(matrizCoordenadas);
    desalocarMatrizOcorrencia(matrizOcorrencia);
    desalocarPalavras(palavras);
    */