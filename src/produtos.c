#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Produto *criar_produto(int codigo,char *nome, float preco){
    Produto *novo = malloc(sizeof(Produto));
    if (novo == NULL)
    {
        printf("Erro ao alocar memória\n");
        return NULL;
    }
    novo->codigo=codigo;
    strcpy(novo->nome ,nome);
    novo->preco=preco;
    novo->prox = NULL;
    return novo;
}


void inserir_produto(Produto **listaProduto, int codigo,char *nome, float preco){
    
    if (existe_produto(*listaProduto,codigo)==1)
    {
        printf("Código de produto já utilizado\n");
        return;
    }
        
    
    Produto *novo = criar_produto(codigo,nome,preco);
    novo->prox = *listaProduto;
    *listaProduto = novo;
    printf("Produto inserido com sucesso\n");
}

void imprimir_produtos(Produto *listaProduto){
    printf("---------------------\n");
    Produto *aux = listaProduto;
    if (aux==NULL){
        printf("Nenhum produto cadastrado\n");
    }
    while (aux != NULL )
    {
        printf("Código : %d\n",aux->codigo);
        printf("Nome : %s\n",aux->nome);
        printf("Preço : %.2f\n",aux->preco);
        printf("---------------------\n");
        aux = aux->prox;
    }
    
    
}

Produto *retornar_produto(Produto *listaProduto, int codigo){
    Produto *aux = listaProduto;
    while (aux != NULL && aux->codigo!=codigo )
    {
        aux = aux->prox;
    }
    return aux;
}

void excluir_produto(Produto **listaProduto, int codigo){
    Produto *aux = *listaProduto;
    Produto *anterior = NULL;
    while (aux != NULL && aux->codigo!=codigo)
    {
        anterior = aux;
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        printf("Código de produto não encontrado\n");
        return ;
    }
    //se é o primeiro elemento da lista
    if (anterior == NULL)
    {
        *listaProduto = aux->prox;
    }
    //se é algum elemento a partir do segundo
    else{
        anterior->prox = aux->prox;
    }
    free(aux);
    printf("Produto removido com sucesso\n");

}

int existe_produto(Produto *listaProduto, int codigo){
    Produto *aux = listaProduto;
    while (aux != NULL && aux->codigo!=codigo )
    {
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        return 0;
    }
    return 1;
}

void alterar_produto(Produto **listaProduto, int codigo,char *nome, float preco ){
    Produto *produto=retornar_produto(*listaProduto,codigo);
    if (produto==NULL)
    {
        printf("Código de produto não encontrado\n");
        return;
    }
    strcpy(produto->nome ,nome);
    produto->preco=preco;
    printf("Produto alterado com sucesso\n");
}

void destruir_lista_produtos(Produto *listaProduto){
    Produto *aux;
    while (listaProduto != NULL)
    {
        aux = listaProduto;
        listaProduto = aux->prox;
        free(aux);
    }
}

int imprimir_produto(Produto *listaProduto,int codigo){
    Produto *produto = retornar_produto(listaProduto,codigo);
    if (produto != NULL)
    {
        printf("---------------------\n");
        printf("Código : %d\n",produto->codigo);
        printf("Nome : %s\n",produto->nome);
        printf("Preço : %.2f\n",produto->preco);
        printf("---------------------\n");
        return 1;
    }
    else{
        printf("Código de produto não encontrado\n");
        return 0;
    }
}