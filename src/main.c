#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "clientes.h"


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

int main(){
    Cliente *listaCliente = NULL;
    int opcao_menu_principal = -1;
    while (opcao_menu_principal != 0)
    {
        menu_principal();
        scanf("%d",&opcao_menu_principal);
        switch (opcao_menu_principal)
        {

        case 1 :
            int opcao_menu_cliente = -1;
            while (opcao_menu_cliente != 0)
            {
                char cpf[20];
                char nome[100];
                char telefone[15];
                menu_cliente();
                scanf("%d",&opcao_menu_cliente);
                getchar();
                switch (opcao_menu_cliente)
                {
                case 1:
                    limpar_tela();
                    printf("Incluindo cliente...\n");
                    printf("CPF: ");
                    fgets(cpf,sizeof(cpf),stdin);
                    retirar_enter(cpf);
                    printf("Nome: ");
                    fgets(nome,sizeof(nome),stdin);
                    retirar_enter(nome);
                    printf("Telefone: ");
                    fgets(telefone,sizeof(telefone),stdin);
                    retirar_enter(telefone);
                    inserir_cliente(&listaCliente,cpf,nome,telefone);
                    break;
                
                case 2:
                    limpar_tela();
                    printf("Listando clientes...\n");
                    imprimir_clientes(listaCliente);
                    break;
                
                case 3:
                    limpar_tela();
                    printf("Buscando cliente...\n");
                    printf("CPF: ");
                    fgets(cpf,sizeof(cpf),stdin);
                    retirar_enter(cpf);
                    imprimir_cliente(listaCliente,cpf);

                    break;

                case 4:
                    limpar_tela();
                    printf("Editando cliente...\n");
                    printf("CPF: ");
                    fgets(cpf,sizeof(cpf),stdin);
                    retirar_enter(cpf);
                    if (imprimir_cliente(listaCliente,cpf) == 1)
                    {
                        printf("Novo nome: ");
                        fgets(nome,sizeof(nome),stdin);
                        retirar_enter(nome);
                        printf("Novo telefone: ");
                        fgets(telefone,sizeof(telefone),stdin);
                        retirar_enter(telefone);
                        alterar_cliente(&listaCliente,cpf,nome,telefone);
                    }
                    
                    break;

                case 5:
                    limpar_tela();
                    printf("Removendo cliente...\n");
                    printf("CPF: ");
                    fgets(cpf,sizeof(cpf),stdin);
                    retirar_enter(cpf);
                    excluir_cliente(&listaCliente,cpf);
                    break;
                
                case 0:
                    limpar_tela();
                    break;
                
                default:
                    printf("Opção inválida\n");;
                }
            }

        case 2 :
            printf("Menu produto...\n");
            break;
        case 3 :
            printf("Carrinho de compra...\n");
            break;    
        case 0 :
            printf("Encerrando...\n");
            destruir_lista_clientes(listaCliente);
            break;
        default:
            printf("Opção inválida\n");
        }
    }
   
    return 0;
}