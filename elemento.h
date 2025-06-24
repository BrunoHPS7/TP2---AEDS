#ifndef ELEMENTO_H
#define ELEMENTO_H

typedef struct Elemento
{
    char letra;
    int linha, coluna;
    struct Elemento *norte, *sul, *leste, *oeste; //Ponteiros Verticais e Horizontais
    struct Elemento *nordeste, *noroeste, *suldeste, *sudoeste; //Ponteiros Diagonais

}Elemento;

#endif