#include <stdio.h>
#include <stdlib.h>

#include "elemento.h"
#include "matriz.h"

//Criar Matriz Nula (I,J):
Matriz *criarMatrizNula()
{
    //Alocar memória para a Matriz:
    Matriz *matriz = malloc(sizeof(Matriz));
    if (!matriz) return NULL;

    //Pegar Dimensoes:
    int linhas, colunas;
    printf("Digite a quantidade de Linhas e Colunas de seu Caça-Palavras:");
    scanf("%d%d", &linhas, &colunas);

    //Definir dimensões:
    matriz->linhas = linhas;
    matriz->colunas = colunas;

    //Instanciar Elemento Inicial:
    Elemento *elementoInicial = malloc(sizeof(Elemento));
    if(!elementoInicial)
    {
        free(matriz);
        return NULL;
    }
    
    //Definir Elemento Inicial:
    elementoInicial->linha = 0;
    elementoInicial->coluna = 0;
    elementoInicial->letra = '-'; //Irei usar "-" para simular o elemento vazio

    //Apontadores NULL:
    elementoInicial->norte = NULL;
    elementoInicial->sul = NULL;
    elementoInicial->leste = NULL;
    elementoInicial->oeste = NULL;
    elementoInicial->nordeste = NULL;
    elementoInicial->noroeste = NULL;
    elementoInicial->suldeste = NULL;
    elementoInicial->sudoeste = NULL;

    //Primeiro Elemeto de Matriz é o Elemento Inicial:
    matriz->inicio = elementoInicial;

    //Retorna Matriz com primeiro Elemento criado e vazio, além de definir suas dimensões
    return matriz;
}


//Preencher Matriz:
Matriz *preencherMatriz(Matriz *matriz)
{
    //Verifica se a matriz recebida possui o primeiro elemento:
    if (!matriz || !matriz->inicio) return NULL;

    //Capturar Dimensões dessa Matriz:
    int linhas = matriz->linhas;
    int colunas = matriz->colunas;

    //Criar vetor auxiliar para armazenar os elementos
    Elemento **elementos = malloc(linhas * colunas * sizeof(Elemento *));
    if (!elementos) return NULL;

    //Pegar Primeiro Elemento:
    char inserirElemento;
    scanf(" %c", &inserirElemento);
    
    elementos[0] = matriz->inicio;
    elementos[0]->letra = inserirElemento;

    //Criar os demais elementos da matriz
    for (int i = 0; i < linhas; i++) 
    {
        for (int j = 0; j < colunas; j++) 
        {
            //Se for (0,0), já foi criado
            if (i == 0 && j == 0) continue;

            //Pegar Elemento:
            scanf(" %c", &inserirElemento);

            Elemento *elementoNovo = malloc(sizeof(Elemento));
            if (!elementoNovo) 
            {
                //liberar elementos já criados
                for (int k = 0; k < i * colunas + j; k++)
                    if (elementos[k]) free(elementos[k]);
                free(elementos);
                return NULL;
            }

            elementoNovo->linha = i;
            elementoNovo->coluna = j;
            elementoNovo->letra = inserirElemento;

            //Inicializa os ponteiros com NULL
            elementoNovo->norte = NULL;
            elementoNovo->sul = NULL;
            elementoNovo->leste = NULL;
            elementoNovo->oeste = NULL;
            elementoNovo->nordeste = NULL;
            elementoNovo->noroeste = NULL;
            elementoNovo->suldeste = NULL;
            elementoNovo->sudoeste = NULL;

            elementos[i * colunas + j] = elementoNovo;
        }
    }

    //Conectar todos os ponteiros:
    for (int i = 0; i < linhas; i++) 
    {
        for (int j = 0; j < colunas; j++) 
        {
            // elementos é um vetor de ponteiros
            Elemento *elementoNovo = elementos[i * colunas + j];

            //Se o vizinho ao sentido desejado não for Null, o apontador recebe o ponteiro do vizinho que está em elementos(vetor de ponteiro)
            elementoNovo->norte = (i > 0) ? elementos[(i - 1) * colunas + j] : NULL;
            elementoNovo->sul = (i < linhas - 1) ? elementos[(i + 1) * colunas + j] : NULL;
            elementoNovo->oeste = (j > 0) ? elementos[i * colunas + (j - 1)] : NULL;
            elementoNovo->leste = (j < colunas - 1) ? elementos[i * colunas + (j + 1)] : NULL;

            elementoNovo->noroeste = (i > 0 && j > 0) ? elementos[(i - 1) * colunas + (j - 1)] : NULL;
            elementoNovo->nordeste = (i > 0 && j < colunas - 1) ? elementos[(i - 1) * colunas + (j + 1)] : NULL;
            elementoNovo->sudoeste = (i < linhas - 1 && j > 0) ? elementos[(i + 1) * colunas + (j - 1)] : NULL;
            elementoNovo->suldeste = (i < linhas - 1 && j < colunas - 1) ? elementos[(i + 1) * colunas + (j + 1)] : NULL;
        }
    }

    //Definir o início da matriz (elemento 0,0 já está)
    matriz->inicio = elementos[0];

    //Liberar vetor auxiliar:
    free(elementos);

    return matriz;
}


//Imprimit Matriz:
void imprimirMatriz(Matriz *matriz)
{
    //Testa se Matriz está Vazia:
    if (!matriz || !matriz->inicio) 
    {
        printf("Matriz vazia.\n");
        return;
    }

    //Pega o Elemento atual, que no caso é inciado com o primeiro elemento:
    Elemento *linhaAtual = matriz->inicio;
    printf("Começando Impressão:\n");

    while (linhaAtual) 
    {
        //A cada linha nova, começamos no primeiro elemento da linha:
        Elemento *colunaAtual = linhaAtual;

        while (colunaAtual) 
        {
            printf("%c ", colunaAtual->letra); //Print do elemento na Linha
            colunaAtual = colunaAtual->leste; //Percorremos a linha
        }

        printf("\n");
        linhaAtual = linhaAtual->sul; //Linha Atual se movimenta para baixo (Proxima linha)
    }
}


//Desalocar Matriz:
void desalocarMatriz(Matriz *matriz)
{
    //Verifica se Matriz está Vazia:
    if (!matriz || !matriz->inicio) return;

    //Pegar Primeiro Elemento:
    Elemento *linhaAtual = matriz->inicio;

    //Desalocamento:   
    while (linhaAtual != NULL)
    {
        Elemento *colunaAtual = linhaAtual;
        Elemento *proximaLinha = linhaAtual->sul;

        while (colunaAtual != NULL)
        {
            Elemento *proximaColuna = colunaAtual->leste;
            free(colunaAtual);
            colunaAtual = proximaColuna;
        }

        linhaAtual = proximaLinha;
    }
    matriz->inicio = NULL;
}