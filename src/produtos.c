#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"

void cadastrarProduto(Produto **lista) {
    Produto *novo = malloc(sizeof(Produto));
    if (!novo) {
        printf("Erro de memoria!\n");
        return;
    }

    printf("Codigo: ");
    scanf("%d", &novo->codigo);

    printf("Nome: ");
    scanf(" %[^\n]", novo->nome);

    printf("Preco: ");
    scanf("%f", &novo->preco);

    printf("Quantidade: ");
    scanf("%d", &novo->quantidade);

    novo->prox = *lista;
    *lista = novo;

    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos(Produto *lista) {
    if (!lista) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    while (lista) {
        printf("\nCodigo: %d", lista->codigo);
        printf("\nNome: %s", lista->nome);
        printf("\nPreco: %.2f", lista->preco);
        printf("\nQuantidade: %d\n", lista->quantidade);
        lista = lista->prox;
    }
}
Produto* buscarProduto(Produto *lista, int codigo) {
    while (lista) {
        if (lista->codigo == codigo)
            return lista;
        lista = lista->prox;
    }
    return NULL;
}
void editarProduto(Produto *lista) {
    int codigo;
    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);

    Produto *p = buscarProduto(lista, codigo);

    if (!p) {
        printf("Produto nao encontrado.\n");
        return;
    }

    printf("Novo nome: ");
    scanf(" %[^\n]", p->nome);

    printf("Novo preco: ");
    scanf("%f", &p->preco);

    printf("Nova quantidade: ");
    scanf("%d", &p->quantidade);

    printf("Produto atualizado!\n");
}
void removerProduto(Produto **lista) {
    int codigo;
    printf("Codigo do produto a remover: ");
    scanf("%d", &codigo);

    Produto *atual = *lista;
    Produto *anterior = NULL;

    while (atual && atual->codigo != codigo) {
        anterior = atual;
        atual = atual->prox;
    }

    if (!atual) {
        printf("Produto nao encontrado.\n");
        return;
    }

    if (!anterior)
        *lista = atual->prox;
    else
        anterior->prox = atual->prox;

    free(atual);
    printf("Produto removido!\n");
}