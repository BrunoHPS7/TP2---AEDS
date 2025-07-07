#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "ocorrencia.h"
#include "palavra.h"

//Preencher Lista de Ocorrencias:
Ocorrencia *criarListaOcorrencia(Matriz *matriz) 
{
    if (!matriz || !matriz->inicio) return NULL;

    //Inicializa a lista de ocorrências como vazia:
    Ocorrencia *listaOcorrencia = NULL; 

    Elemento *linhaAtual = matriz->inicio;
    while (linhaAtual) 
    {
        Elemento *colunaAtual = linhaAtual;
        while (colunaAtual) 
        {
            //Converte letra para minúscula:
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

                //Criar nova ocorrência se necessário:
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
                    //Primeira coordenada:
                    ocorrencia->coordenadas = nova; 
                } 
                else 
                {
                    Coordenada *aux = ocorrencia->coordenadas;
                    while (aux->proxima)
                    {
                        aux = aux->proxima; //Avança até o final da lista
                    } 
                    aux->proxima = nova; 
                }
            }
            //Avança para a próxima coluna:
            colunaAtual = colunaAtual->leste; 
        }
        //Avança para a próxima linha:
        linhaAtual = linhaAtual->sul; 
    }
    return listaOcorrencia;
}

//Imprimir Ocorrencias:
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

//Seguir Direção:
Elemento *seguirDirecao(Elemento *atual, int direcao) 
{
    //Verifica se o elemento é válido:
    if (!atual) return NULL;

    switch (direcao) 
    {
        case 0: return atual->norte;    
        case 1: return atual->sul;       
        case 2: return atual->leste;    
        case 3: return atual->oeste;  
        case 4: return atual->nordeste;  
        case 5: return atual->noroeste; 
        case 6: return atual->suldeste;  
        case 7: return atual->sudoeste;  
        default: return NULL;           
    }
}

//Buscar Palavras:
void buscarPalavras(Matriz *matriz, Lista *listaPalavras) 
{
    Palavra *palavraAtual = listaPalavras->primeiro;

    while (palavraAtual) 
    {
        palavraAtual->encontrada = false; //Inicializa como não encontrada
        char letraInicial = palavraAtual->palavra[0]; //Captura primeira letra

        Elemento *linha = matriz->inicio;
        while (linha && !palavraAtual->encontrada) 
        {
            Elemento *coluna = linha;

            while (coluna && !palavraAtual->encontrada) 
            {
                if (coluna->letra == letraInicial) 
                {
                    for (int direcao = 0; direcao < 8 && !palavraAtual->encontrada; direcao++) 
                    {
                        Elemento *atual = coluna;
                        int i;
                        for (i = 1; palavraAtual->palavra[i] != '\0'; i++) 
                        {
                            atual = seguirDirecao(atual, direcao); 
                            if (!atual || atual->letra != palavraAtual->palavra[i])
                                break;
                        }
                        
                        if (palavraAtual->palavra[i] == '\0') 
                        {
                            //Palavra encontrada nas posições:
                            palavraAtual->xi = coluna->linha; 
                            palavraAtual->yi = coluna->coluna; 
                            palavraAtual->xf = atual->linha; 
                            palavraAtual->yf = atual->coluna; 
                            palavraAtual->encontrada = true;
                            break;
                        }
                    }
                }
                coluna = coluna->leste; //Próximo elemento da linha
            }
            linha = linha->sul; //Próxima linha
        }
        palavraAtual = palavraAtual->proxima; //Próxima palavra
    }
}
