#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "clientes.h"

int main(){

    char opcao;

    printf("===== MENU =====\n");
    printf("A - Cadastrar Cliente\n");
    printf("B - Listar Produtos\n");
    printf("C - Buscar produto\n");
    printf("D - Editar dados do produto\n");
    printf("E - Remover produto\n");
    printf("Escolha uma opcao: ");

    scanf(" %c", &opcao); 

    switch (opcao) {
        case 'A':
            printf("Opcao Cadastrar selecionada\n");
            break;

        case 'B':
            printf("Opcao Listar selecionada\n");
            break;

        case 'C':
            printf("Opcao Buscar produto selecionada\n");
            break;

        case 'D':
            printf("Opcao Editar dados selecionada\n");
            break;

        case 'E':
            printf("opcao Remover produto selecionado\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    imprimeOi();
    Cliente *listaCliente = NULL;
    inserir_cliente(&listaCliente,"0310204124","Tomas","992343842");
    inserir_cliente(&listaCliente,"0310223124","Lucas","992343879");
    inserir_cliente(&listaCliente,"0310204181","Mateus","99788842");
    imprimir_clientes(listaCliente);
    Cliente *p_cliente = retornar_cliente(listaCliente,"097");
    //printf("Nome: %s",p_cliente->nome);
    excluir_cliente(&listaCliente,"0310223124");
    imprimir_clientes(listaCliente);
    return 0;
}