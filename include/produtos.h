#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct Produto {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
    struct Produto *prox;
} Produto;
void cadastrarProduto(Produto **lista);
#endif 