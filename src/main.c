#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "clientes.h"
#include "produtos.h"
#include "carrinho.h"


int main(){
    Cliente *listaCliente = NULL;
    Produto *listaProduto = NULL;
    ItemCompra *listaItemCompra = NULL;
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
            break;

        case 2 :
            int opcao_menu_produto = -1;
            while (opcao_menu_produto != 0)
            {
                int codigo;
                char nome[100];
                float preco;
                menu_produto();
                scanf("%d",&opcao_menu_produto);
                getchar();
                switch (opcao_menu_produto)
                {
                case 1:
                    limpar_tela();
                    printf("Incluindo produto...\n");
                    printf("Código: ");
                    scanf("%d",&codigo);
                    getchar();
                    printf("Nome: ");
                    fgets(nome,sizeof(nome),stdin);
                    retirar_enter(nome);
                    printf("Preço: ");
                    scanf("%f",&preco);
                    getchar();
                    inserir_produto(&listaProduto,codigo,nome,preco);
                    break;

                case 2:
                    limpar_tela();
                    printf("Listando produtos...\n");
                    imprimir_produtos(listaProduto);
                    break;
                
                case 3:
                    limpar_tela();
                    printf("Buscando produto...\n");
                    printf("Código: ");
                    scanf("%d",&codigo);
                    getchar();
                    imprimir_produto(listaProduto,codigo);
                    break;

                case 4:
                    limpar_tela();
                    printf("Editando produto...\n");
                    printf("Código: ");
                    scanf("%d",&codigo);
                    getchar();
                    if (imprimir_produto(listaProduto,codigo) == 1)
                    {
                        printf("Novo nome: ");
                        fgets(nome,sizeof(nome),stdin);
                        retirar_enter(nome);
                        printf("Novo preço: ");
                        scanf("%f",&preco);
                        getchar();
                        alterar_produto(&listaProduto,codigo,nome,preco);
                    }
                    break;

                case 5:
                    limpar_tela();
                    printf("Removendo produto...\n");
                    printf("Código: ");
                    scanf("%d",&codigo);
                    getchar();
                    excluir_produto(&listaProduto,codigo);
                    break;
                
                case 0:
                    limpar_tela();
                    break;
                
                default:
                    printf("Opção inválida\n");;
                }
            }
            break;

        case 3 :
            int opcao_menu_carrinho = -1;
            while (opcao_menu_carrinho != 0)
            {
                char cpfCliente[20];
                int codigoProduto;
                int quantidade;
                menu_carrinho();
                scanf("%d",&opcao_menu_carrinho);
                getchar();
                switch (opcao_menu_carrinho)
                {
                case 1:
                    limpar_tela();
                    printf("Incluindo um produto no carrinho de um cliente...\n");
                    printf("CPF do Cliente: ");
                    fgets(cpfCliente,sizeof(cpfCliente),stdin);
                    retirar_enter(cpfCliente);
                    printf("Código do produto: ");
                    scanf("%d",&codigoProduto);
                    getchar();
                    printf("Quantidade: ");
                    scanf("%d",&quantidade);
                    getchar();
                    inserir_item_compra(&listaItemCompra,listaCliente,listaProduto,cpfCliente,codigoProduto,quantidade);
                    break;

                case 2:

                    limpar_tela();
                    printf("Listando todos os produtos do carrinho de um cliente...\n");
                    printf("CPF do Cliente: ");
                    fgets(cpfCliente,sizeof(cpfCliente),stdin);
                    retirar_enter(cpfCliente);
                    imprimir_itens_compra_cliente(listaItemCompra,listaCliente,listaProduto,cpfCliente);
                    break;

                case 3:
                    limpar_tela();
                    printf("Retirando um produto do carrinho de um cliente...\n");
                    printf("CPF do Cliente: ");
                    fgets(cpfCliente,sizeof(cpfCliente),stdin);
                    retirar_enter(cpfCliente);
                    printf("Código do produto: ");
                    scanf("%d",&codigoProduto);
                    getchar();
                    excluir_item_compra(&listaItemCompra,cpfCliente,codigoProduto);
                    break;

                case 0:
                    limpar_tela();
                    break;
                
                default:
                    printf("Opção inválida\n");;
                }   
            }
            break;

        case 0 :
            printf("Encerrando...\n");
            destruir_lista_clientes(listaCliente);
            destruir_lista_produtos(listaProduto);
            destruir_lista_item_compra(listaItemCompra);
            break;

        default:
            printf("Opção inválida\n");
        }
    }
   
    return 0;
}