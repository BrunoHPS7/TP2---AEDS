#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"
//#include "coordenada.h"
//#include "ocorrencia.h"
//#include "palavra.h"

int main() 
{
    //Criar Matriz de Caça-Palvras
    Matriz* matriz = criarMatrizNula();
    if (!matriz) 
    {
        printf("Erro ao criar matriz!\n");
        return 1;
    }
    printf("Matriz criada com %d linhas e %d colunas\n", matriz->linhas, matriz->colunas);

    //Preencher Matriz:
    preencherMatriz(matriz);

    //Imprimir Matriz:
    imprimirMatriz(matriz);

    //Liberações de Memória
    free(matriz);

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