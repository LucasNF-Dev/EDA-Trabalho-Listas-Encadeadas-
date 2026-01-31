#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpar_tela(){
    #ifdef _WIN32
        system("cls"); // Comando para Windows
    #else
        system("clear"); // Comando para Linux/Unix
    #endif
}


void retirar_enter(char *str){
    str[strcspn(str,"\n")] = '\0';
}

void menu_principal(){
    printf("**********************\n");
    printf("*** MENU PRINCIPAL ***\n");
    printf("**********************\n");
    printf("1 - Gerenciamento de Clientes\n");
    printf("2 - Gerenciamento de Produtos\n");
    printf("3 - Modo Compra\n");
    printf("0 - Sair\n");
}

void menu_cliente(){
    printf("********************\n");
    printf("*** MENU CLIENTE ***\n");
    printf("********************\n");
    printf("1 - Cadastrar cliente\n");
    printf("2 - Listar todos os clientes\n");
    printf("3 - Buscar cliente\n");
    printf("4 - Editar dados de um cliente\n");
    printf("5 - Remover cliente\n");
    printf("0 - Voltar ao menu principal\n");
}

void menu_produto(){
    printf("********************\n");
    printf("*** MENU PRODUTO ***\n");
    printf("********************\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar todos os produtos\n");
    printf("3 - Buscar produto\n");
    printf("4 - Editar dados de um produto\n");
    printf("5 - Remover produto\n");
    printf("0 - Voltar ao menu principal\n");
}

void menu_carrinho(){
    printf("********************\n");
    printf("*** MENU CARRINHO ***\n");
    printf("********************\n");
    printf("1 - Incluir um produto no carrinho de um cliente\n");
    printf("2 - Listar todos os produtos do carrinho de um cliente\n");
    printf("3 - Retirar todos os produtos do carrinho de um cliente\n");
    printf("0 - Voltar ao menu principal\n");
}