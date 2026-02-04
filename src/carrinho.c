#include "carrinho.h"
#include "clientes.h"
#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


ItemCompra *criar_item_compra(char *cpfCliente,int codigoProduto, int quantidade){
    ItemCompra *novo = malloc(sizeof(ItemCompra));
    if (novo == NULL)
    {
        printf("Erro ao alocar memória\n");
        return NULL;
    }
    strcpy(novo->cpfCliente ,cpfCliente);
    novo->codigoProduto=codigoProduto;
    novo->quantidade=quantidade;
    novo->prox = NULL;
    return novo;
}


void inserir_item_compra(ItemCompra **listaCompras, Cliente *listaCliente, Produto *listaProduto, char *cpfCliente,int codigoProduto, int quantidade ){

    if (existe_cliente(listaCliente,cpfCliente)==0)
    {
        printf("CPF de cliente inexistente\n");
        return;
    }

    if (existe_produto(listaProduto,codigoProduto)==0)
    {
        printf("Código de produto inexistente\n");
        return;
    }
        
    
    ItemCompra *novo = criar_item_compra(cpfCliente,codigoProduto,quantidade);
    novo->prox = *listaCompras;
    *listaCompras = novo;
    printf("Item de compra inserido com sucesso\n");
}


//MELHORAR PARA TRAZER OUTROS DADOS DE CLIENTE E PRODUTO
void imprimir_itens_compra_cliente(ItemCompra *listaCompras,Cliente *listaCliente, Produto *listaProduto, char *cpfCliente){
    printf("---------------------\n");
    ItemCompra *aux = listaCompras;
    Cliente *cliente = retornar_cliente(listaCliente,cpfCliente);
    Produto *produto = NULL;
    if (cliente==NULL){
        printf("CPF inexistente\n");
        return;
    }

    if (aux==NULL){
        printf("Nenhum item de compra cadastrado\n");
    }
    while (aux != NULL )
    {
        if (strcmp(aux->cpfCliente,cpfCliente)== 0){

            produto=retornar_produto(listaProduto,aux->codigoProduto);

            printf("CPF do cliente: %s\n",aux->cpfCliente);
            printf("Nome do cliente: %s\n",cliente->nome);
            printf("Código do produto: %d\n",aux->codigoProduto);
            printf("Nome do produto: %s\n",produto->nome);
            printf("Preço do produto: %.2f\n",produto->preco);
            printf("Quantidade comprada : %d\n",aux->quantidade);
            printf("Valor total da compra : %.2f\n",(aux->quantidade)*(produto->preco));
            printf("---------------------\n");
        }
        
        aux = aux->prox;
    }
}

ItemCompra *retornar_item_compra(ItemCompra *listaCompras, char *cpfCliente, int codigoProduto){
    ItemCompra *aux = listaCompras;
    while (aux != NULL && (aux->codigoProduto!=codigoProduto || strcmp(aux->cpfCliente,cpfCliente)!= 0) )
    {
        aux = aux->prox;
    }
    return aux;
}

void excluir_item_compra(ItemCompra **listaCompras, char *cpfCliente, int codigoProduto){
    ItemCompra *aux = *listaCompras;
    ItemCompra *anterior = NULL;
    while (aux != NULL && (aux->codigoProduto!=codigoProduto || strcmp(aux->cpfCliente,cpfCliente)!= 0) )
    {
        anterior = aux;
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        printf("Item de compra não encontrado\n");
        return ;
    }
    //se é o primeiro elemento da lista
    if (anterior == NULL)
    {
        *listaCompras = aux->prox;
    }
    //se é algum elemento a partir do segundo
    else{
        anterior->prox = aux->prox;
    }
    free(aux);
    printf("Item de compra removido com sucesso\n");

}

void destruir_lista_item_compra(ItemCompra *listaCompras){
    ItemCompra *aux;
    while (listaCompras != NULL)
    {
        aux = listaCompras;
        listaCompras = aux->prox;
        free(aux);
    }
}

