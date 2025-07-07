#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct Elemento
{
    char letra;
    int linha, coluna;
    struct Elemento *norte, *sul, *leste, *oeste; //Ponteiros Verticais e Horizontais
    struct Elemento *nordeste, *noroeste, *suldeste, *sudoeste; //Ponteiros Diagonais

}Elemento;

typedef struct
{
    int linhas, colunas;
    Elemento *inicio;
}Matriz;

//Criar Matriz Nula (Linhas, Colunas):
Matriz *criarMatrizNula();

//Preencher Matriz:
Matriz *preencherMatriz(Matriz *matriz);

//Imprimit Matriz:
void imprimirMatriz(Matriz *matriz);

//Desalocar Matriz:
void desalocarMatriz(Matriz *matriz);

#endif