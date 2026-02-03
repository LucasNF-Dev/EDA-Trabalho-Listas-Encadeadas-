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
void remover_do_carrinho(Cliente *cliente, int codigoProduto, int qtdParaRemover){
    ItemCarrinho *atual = cliente->carrinho;
    ItemCarrinho *anterior = NULL;

    while(atual != NULL && atual->codigoProduto != codigoProduto){        
        anterior = atual;
        atual = atual->prox;
    }
    if(atual == NULL){
        printf("Produto nao encontrado no carrinho!\n");
        return;
    }
    if(atual->quantidade > qtdParaRemover){
        atual->quantidade = atual->quantidade - qtdParaRemover;
        return;
    }

    if (anterior == NULL) {
        cliente->carrinho = atual->prox; //PULA A CABECA E VAI PRO PROXIMO( ISSO NESSE CASO SERIA PQ O PRIMEIRO ELEMENTO SERIA O PRODUTO A SER REMOVIDO)
    }
    else{
        anterior->prox = atual->prox;
    }
    free(atual);    
    printf("Produto removido do carrinho!\n");  
}