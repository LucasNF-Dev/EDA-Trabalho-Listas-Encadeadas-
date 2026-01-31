#include "clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Cliente *criar_cliente(char *cpf,char *nome, char *telefone){
    Cliente *novo = malloc(sizeof(Cliente));
    if (novo == NULL)
    {
        printf("Erro ao alocar memória\n");
        return NULL;
    }
    strcpy(novo->cpf ,cpf);
    strcpy(novo->nome ,nome);
    strcpy(novo->telefone ,telefone);
    novo->prox = NULL;
    return novo;
}


void inserir_cliente(Cliente **listaCliente, char *cpf,char *nome, char *telefone ){
    
    if (existe_cliente(*listaCliente,cpf)==1)
    {
        printf("CPF ja utilizado\n");
        return;
    }
        
    
    Cliente *novo = criar_cliente(cpf,nome,telefone);
    novo->prox = *listaCliente;
    *listaCliente = novo;
    printf("Cliente inserido com sucesso\n");
}

void imprimir_clientes(Cliente *listaCliente){
    printf("---------------------\n");
    Cliente *aux = listaCliente;
    if (aux==NULL){
        printf("Nenhum cliente cadastrado\n");
    }
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

void excluir_cliente(Cliente **listaCliente, char *cpf){
    Cliente *aux = *listaCliente;
    Cliente *anterior = NULL;
    while (aux != NULL && strcmp(aux->cpf,cpf)!= 0 )
    {
        anterior = aux;
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        printf("CPF não encontrado\n");
        return ;
    }
    //se é o primeiro elemento da lista
    if (anterior == NULL)
    {
        *listaCliente = aux->prox;
    }
    //se é algum elemento a partir do segundo
    else{
        anterior->prox = aux->prox;
    }
    free(aux);
    printf("Cliente removido com sucesso\n");

}

int existe_cliente(Cliente *listaCliente, char *cpf){
    Cliente *aux = listaCliente;
    while (aux != NULL && strcmp(aux->cpf,cpf)!= 0 )
    {
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        return 0;
    }
    return 1;
}

void alterar_cliente(Cliente **listaCliente, char *cpf,char *nome, char *telefone ){
    Cliente *cliente=retornar_cliente(*listaCliente,cpf);
    if (cliente==NULL)
    {
        printf("CPF não encontrado\n");
        return;
    }
    strcpy(cliente->nome ,nome);
    strcpy(cliente->telefone ,telefone);
    printf("Cliente alterado com sucesso\n");
}

void destruir_lista_clientes(Cliente *listaCliente){
    Cliente *aux;
    while (listaCliente != NULL)
    {
        aux = listaCliente;
        listaCliente = aux->prox;
        free(aux);
    }
}

int imprimir_cliente(Cliente *listaCliente,char *cpf){
    Cliente *cliente = retornar_cliente(listaCliente,cpf);
    if (cliente != NULL)
    {
        printf("---------------------\n");
        printf("CPF : %s\n",cliente->cpf);
        printf("Nome : %s\n",cliente->nome);
        printf("Telefone : %s\n",cliente->telefone);
        printf("---------------------\n");
        return 1;
    }
    else{
        printf("CPF não encontrado\n");
        return 0;
    }
}