#include "clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"


Cliente *criar_cliente(char *cpf,char *nome, char *telefone){
    Cliente *novo = malloc(sizeof(Cliente));
    if (novo == NULL)
    {
        printf("erro ao alocar memória\n");
        return NULL;
    }
    strcpy(novo->cpf ,cpf);
    strcpy(novo->nome ,nome);
    strcpy(novo->telefone ,telefone);
    novo->prox = NULL;
    return novo;
}


void inserir_cliente(Cliente **listaCliente, char *cpf,char *nome, char *telefone ){
    Cliente *novo = criar_cliente(cpf,nome,telefone);
    novo->prox = *listaCliente;
    *listaCliente = novo;
}

void imprimir_clientes(Cliente *listaCliente){
    printf("---------------------\n");
    Cliente *aux = listaCliente;
    while (aux != NULL )
    {
        printf("CPF : %s\n",aux->cpf);
        printf("Nome : %s\n",aux->nome);
        printf("Telefone : %s\n",aux->telefone);
        printf("---------------------\n");
        aux = aux->prox;
    }
    
    
}

Cliente *retornar_cliente(Cliente *listaCliente, char *cpf){
    Cliente *aux = listaCliente;
    while (aux != NULL && strcmp(aux->cpf,cpf)!= 0 )
    {
        aux = aux->prox;
    }
    return aux;
}

void *excluir_cliente(Cliente **listaCliente, char *cpf){
    Cliente *aux = *listaCliente;
    Cliente *anterior = NULL;
    while (aux != NULL && strcmp(aux->cpf,cpf)!= 0 )
    {
        anterior = aux;
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        printf("cpf não encotrado\n");
        exit(1);
    }
    //se é o primeiro elemento da lista
    if (anterior == NULL)
    {
        *listaCliente == aux->prox;
    }
    //se é algum elemento a partir do segundo
    else{
        anterior->prox = aux->prox;
    }
    free(aux);

}