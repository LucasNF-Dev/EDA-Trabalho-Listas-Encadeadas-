#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct Cliente {
    char cpf[20];
    char nome[100];
    char telefone[15];
    struct Cliente *prox;
} Cliente;

Cliente *criar_cliente(char *cpf, char *nome, char *telefone);
void inserir_cliente(Cliente **listaCliente, char *cpf, char *nome, char *telefone);
void imprimir_clientes(Cliente *listaCliente);
Cliente *retornar_cliente(Cliente *listaCliente, char *cpf);
void excluir_cliente(Cliente **listaCliente, char *cpf);

#endif