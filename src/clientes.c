#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/clientes.h"

Cliente *criar_cliente(char *cpf, char *nome, char *telefone) {
    Cliente *novo = malloc(sizeof(Cliente));
    if (novo == NULL) return NULL;
    
    strcpy(novo->cpf, cpf);
    strcpy(novo->nome, nome);
    strcpy(novo->telefone, telefone);
    novo->prox = NULL;
    return novo;
}

void inserir_cliente(Cliente **listaCliente, char *cpf, char *nome, char *telefone) {
    Cliente *novo = criar_cliente(cpf, nome, telefone);
    if (novo != NULL) {
        novo->prox = *listaCliente;
        *listaCliente = novo;
    }
}

void imprimir_clientes(Cliente *listaCliente) {
    Cliente *aux = listaCliente;
    while (aux != NULL) {
        printf("CPF: %s | Nome: %s | Tel: %s\n", aux->cpf, aux->nome, aux->telefone);
        aux = aux->prox;
    }
}

Cliente *retornar_cliente(Cliente *listaCliente, char *cpf) {
    Cliente *aux = listaCliente;
    while (aux != NULL) {
        if (strcmp(aux->cpf, cpf) == 0) return aux;
        aux = aux->prox;
    }
    return NULL;
}

void excluir_cliente(Cliente **listaCliente, char *cpf) {
    Cliente *aux = *listaCliente;
    Cliente *anterior = NULL;

    while (aux != NULL && strcmp(aux->cpf, cpf) != 0) {
        anterior = aux;
        aux = aux->prox;
    }

    if (aux == NULL) return;

    if (anterior == NULL) {
        *listaCliente = aux->prox;
    } else {
        anterior->prox = aux->prox;
    }
    free(aux);
}