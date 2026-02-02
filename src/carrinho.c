#include "carrinho.h"
#include "clientes.h"
#include "produtos.h"
#include "util.h" 
#include <stdio.h>
#include <stdlib.h>

void adicionar_ao_carrinho(Cliente *cliente, int codigoProduto, int quantidade){
    ItemCarrinho *novo = (ItemCarrinho *) malloc(sizeof(ItemCarrinho));
    if(novo == NULL) {
        printf("Erro ao alocar memória\n");
        return;
    }
    novo->codigoProduto = codigoProduto;
    novo->quantidade = quantidade;
    novo->prox = cliente->carrinho;
    cliente->carrinho = novo;
    printf("Item adicionado com sucesso!\n");
}
void listar_carrinho(Cliente *cliente, Produto *listaProdutos){
    ItemCarrinho *aux = cliente->carrinho; 
    
    if (aux == NULL) {
        printf("Carrinho vazio!\n");
        return;
    }

    printf("--- Carrinho do Cliente ---\n");

    while(aux != NULL){ 

        Produto *prod = buscarProduto(listaProdutos, aux->codigoProduto);
        
        if (prod != NULL) {
            printf("Produto: %s\n", prod->nome);
            printf("Qtd: %d\n", aux->quantidade);
            printf("Preço Unit: %.2f\n", prod->preco);
            printf("-------------------\n");
        } else {
            printf("Produto código %d não encontrado no cadastro.\n", aux->codigoProduto);
        }
        
        aux = aux->prox; 
    }
}