#include "clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ================================
   1) PRIMEIRO: CRIAR UM CLIENTE
   (base de tudo)
================================ */

Cliente *criar_cliente(char *cpf, char *nome, char *telefone) {
    Cliente *novo = (Cliente *) malloc(sizeof(Cliente));

    if (novo == NULL) {
        printf("Erro ao alocar memória\n");
        return NULL;
    }

    strcpy(novo->cpf, cpf);
    strcpy(novo->nome, nome);
    strcpy(novo->telefone, telefone);
    novo->prox = NULL;
    novo->carrinho = NULL;

    return novo;
}

/* ================================
   2) VERIFICAR SE JÁ EXISTE
   (usado antes de inserir)
================================ */

int existe_cliente(Cliente *listaCliente, char *cpf) {
    Cliente *aux = listaCliente;

    while (aux != NULL && strcmp(aux->cpf, cpf) != 0) {
        aux = aux->prox;
    }

    if (aux == NULL)
        return 0;   // não existe

    return 1;       // existe
}

/* ================================
   3) INSERIR NA LISTA
================================ */

void inserir_cliente(Cliente **listaCliente, char *cpf, char *nome, char *telefone) {

    if (existe_cliente(*listaCliente, cpf) == 1) {
        printf("CPF ja utilizado\n");
        return;
    }

    Cliente *novo = criar_cliente(cpf, nome, telefone);

    novo->prox = *listaCliente;
    *listaCliente = novo;

    printf("Cliente inserido com sucesso\n");
}

/* ================================
   4) PERCORRER E IMPRIMIR TODOS
================================ */

void imprimir_clientes(Cliente *listaCliente) {
    printf("---------------------\n");

    Cliente *aux = listaCliente;

    if (aux == NULL) {
        printf("Nenhum cliente cadastrado\n");
    }

    while (aux != NULL) {
        printf("CPF : %s\n", aux->cpf);
        printf("Nome : %s\n", aux->nome);
        printf("Telefone : %s\n", aux->telefone);
        printf("---------------------\n");

        aux = aux->prox;
    }
}

/* ================================
   5) BUSCAR (RETORNAR) UM CLIENTE
================================ */

Cliente *retornar_cliente(Cliente *listaCliente, char *cpf) {
    Cliente *aux = listaCliente;

    while (aux != NULL && strcmp(aux->cpf, cpf) != 0) {
        aux = aux->prox;
    }

    return aux; // retorna NULL se não achar
}

/* ================================
   6) IMPRIMIR UM CLIENTE ESPECÍFICO
================================ */

int imprimir_cliente(Cliente *listaCliente, char *cpf) {
    Cliente *cliente = retornar_cliente(listaCliente, cpf);

    if (cliente != NULL) {
        printf("---------------------\n");
        printf("CPF : %s\n", cliente->cpf);
        printf("Nome : %s\n", cliente->nome);
        printf("Telefone : %s\n", cliente->telefone);
        printf("---------------------\n");
        return 1;
    } else {
        printf("CPF não encontrado\n");
        return 0;
    }
}

/* ================================
   7) ALTERAR CLIENTE EXISTENTE
================================ */

void alterar_cliente(Cliente **listaCliente, char *cpf, char *nome, char *telefone) {

    Cliente *cliente = retornar_cliente(*listaCliente, cpf);

    if (cliente == NULL) {
        printf("CPF não encontrado\n");
        return;
    }

    strcpy(cliente->nome, nome);
    strcpy(cliente->telefone, telefone);

    printf("Cliente alterado com sucesso\n");
}

/* ================================
   8) EXCLUIR CLIENTE DA LISTA
================================ */

void excluir_cliente(Cliente **listaCliente, char *cpf) {

    Cliente *aux = *listaCliente;
    Cliente *anterior = NULL;

    while (aux != NULL && strcmp(aux->cpf, cpf) != 0) {
        anterior = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("CPF não encontrado\n");
        return;
    }

    // Se é o primeiro elemento
    if (anterior == NULL) {
        *listaCliente = aux->prox;
    }
    // Se é do segundo em diante
    else {
        anterior->prox = aux->prox;
    }

    free(aux);
    printf("Cliente removido com sucesso\n");
}

/* ================================
   9) DESTRUIR A LISTA TODA
================================ */

void destruir_lista_clientes(Cliente *listaCliente) {
    Cliente *aux;

    while (listaCliente != NULL) {
        aux = listaCliente;
        listaCliente = aux->prox;
        free(aux);
    }
}
