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
void listarProdutos(Produto *lista);
Produto* buscarProduto(Produto *lista, int codigo);
void editarProduto(Produto *lista);
void removerProduto(Produto **lista);
#endif 
