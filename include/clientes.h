#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct Cliente
{
    char cpf[20];
    char nome[100];
    char telefone[15];
    struct Cliente *prox;
    
}Cliente;

//cria um novo cliente
Cliente *criar_cliente(char *cpf,char *nome, char *telefone);

//insere um cliente na primeira posicao da lista
void inserir_cliente(Cliente **listaCliente, char *cpf,char *nome, char *telefone );

//imprimir a lista de clientes
void imprimir_clientes(Cliente *listaCliente);

//retorna o cliente do cpf informado
Cliente *retornar_cliente(Cliente *listaCliente, char *cpf);

//exclui o cliente do cpf informado
void *excluir_cliente(Cliente **listaCliente, char *cpf);

#endif