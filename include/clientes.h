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

//alterar nome e telefone de um cliente a partir de seu cpf
void alterar_cliente(Cliente **listaCliente, char *cpf,char *nome, char *telefone );

//imprimir a lista de clientes
void imprimir_clientes(Cliente *listaCliente);

//imprimir um cliente de acordo com o cpf informado, retorna 0 se não encontrar
int imprimir_cliente(Cliente *listaCliente,char *cpf);

//indica se o cliente existe, buscando por cpf
int existe_cliente(Cliente *listaCliente, char *cpf);

//retorna o cliente do cpf informado
Cliente *retornar_cliente(Cliente *listaCliente, char *cpf);

//exclui o cliente do cpf informado
void excluir_cliente(Cliente **listaCliente, char *cpf);

//libera a area de memoria da lista de clientes
void destruir_lista_clientes(Cliente *listaCliente);

#endif