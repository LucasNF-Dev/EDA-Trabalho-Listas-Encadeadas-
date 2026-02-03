#ifndef CARRINHO_H
#define CARRINHO_H
#include "clientes.h"
#include "produtos.h"

typedef struct ItemCarrinho {
    int codigoProduto;
    int quantidade;
    struct ItemCarrinho *prox;
} ItemCarrinho;
//adiciona um produto ao carrinho do cliente
void adicionar_ao_carrinho(Cliente *cliente, int codigoProduto, int quantidade);    
//lista os produtos no carrinho do cliente
void listar_carrinho(Cliente *cliente, Produto *listaProdutos);
//remove um produto do carrinho do cliente
void remover_do_carrinho(Cliente *cliente, int codigoProduto, int qtdParaRemover);
#endif