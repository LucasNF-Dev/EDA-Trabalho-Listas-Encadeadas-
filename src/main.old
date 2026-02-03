#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "clientes.h"
#include "produtos.h"
#include "carrinho.h" // Importante incluir isso

int main(){
    // Inicializa as duas listas principais
    Cliente *listaCliente = NULL;
    Produto *listaProduto = NULL; 

    int opcao_menu_principal = -1;
    
    // Variáveis auxiliares para leitura de dados
    char cpf[20];
    char nome[100];
    char telefone[15];
    int codigo, qtd;

    while (opcao_menu_principal != 0)
    {
        menu_principal();
        scanf("%d",&opcao_menu_principal);
        
        switch (opcao_menu_principal)
        {
        // ------------------------------------------------
        // MENU 1: CLIENTES
        // ------------------------------------------------
        case 1 :
            int opcao_menu_cliente = -1;
            while (opcao_menu_cliente != 0)
            {
                menu_cliente();
                scanf("%d",&opcao_menu_cliente);
                getchar(); // Limpar buffer do enter
                
                switch (opcao_menu_cliente)
                {
                case 1: // Cadastrar
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
                
                case 2: // Listar
                    limpar_tela();
                    printf("Listando clientes...\n");
                    imprimir_clientes(listaCliente);
                    break;
                
                case 3: // Buscar
                    limpar_tela();
                    printf("Buscando cliente...\n");
                    printf("CPF: ");
                    fgets(cpf,sizeof(cpf),stdin);
                    retirar_enter(cpf);
                    imprimir_cliente(listaCliente,cpf);
                    break;

                case 4: // Editar
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

                case 5: // Remover
                    limpar_tela();
                    printf("Removendo cliente...\n");
                    printf("CPF: ");
                    fgets(cpf,sizeof(cpf),stdin);
                    retirar_enter(cpf);
                    // Dica: Se quiser ser perfeito, deveria limpar o carrinho antes de excluir o cliente
                    // mas pro trabalho básico, excluir o cliente funciona.
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

        // ------------------------------------------------
        // MENU 2: PRODUTOS
        // ------------------------------------------------
        case 2 :
            int opcao_menu_produto = -1;
            while (opcao_menu_produto != 0)
            {
                menu_produto();
                scanf("%d",&opcao_menu_produto);
                getchar(); // Limpar buffer
                
                switch (opcao_menu_produto)
                {
                case 1: // Cadastrar
                    limpar_tela();
                    printf("Incluindo produto...\n");
                    cadastrarProduto(&listaProduto); // Passa o endereço da lista
                    break;

                case 2: // Listar
                    limpar_tela();
                    printf("Listando produtos...\n");
                    listarProdutos(listaProduto);
                    break;
                
                case 3: // Buscar
                    limpar_tela();
                    printf("Digite o codigo para buscar: ");
                    scanf("%d", &codigo);
                    Produto *p = buscarProduto(listaProduto, codigo);
                    if(p){
                        printf("Produto encontrado: %s | R$ %.2f\n", p->nome, p->preco);
                    } else {
                        printf("Produto nao encontrado.\n");
                    }
                    break;

                case 4: // Editar
                    limpar_tela();
                    printf("Editando produto...\n");
                    editarProduto(listaProduto); // Sua função pede o código internamente
                    break;

                case 5: // Remover
                    limpar_tela();
                    printf("Removendo produto...\n");
                    removerProduto(&listaProduto); // Sua função pede o código internamente
                    break;
                
                case 0:
                    limpar_tela();
                    break;
                
                default:
                    printf("Opção inválida\n");;
                }
            }
            break;

        // ------------------------------------------------
        // MENU 3: CARRINHO (MODO COMPRA)
        // ------------------------------------------------
        case 3 :
            int opcao_menu_carrinho = -1;
            while (opcao_menu_carrinho != 0)
            {
                menu_carrinho();
                scanf("%d",&opcao_menu_carrinho);
                getchar();
                
                // Variável local para encontrar o cliente neste switch
                Cliente *clienteEncontrado = NULL;

                switch (opcao_menu_carrinho)
                {
                case 1: // ADICIONAR AO CARRINHO
                    limpar_tela();
                    printf("--- Incluir produto no carrinho ---\n");
                    
                    // 1. Achar o cliente
                    printf("CPF do Cliente: ");
                    fgets(cpf, sizeof(cpf), stdin);
                    retirar_enter(cpf);
                    clienteEncontrado = retornar_cliente(listaCliente, cpf);

                    if(clienteEncontrado == NULL){
                        printf("Cliente nao encontrado!\n");
                    } else {
                        // 2. Mostrar produtos disponíveis pra ajudar
                        printf("\n--- Produtos Disponiveis ---\n");
                        listarProdutos(listaProduto);
                        printf("----------------------------\n");

                        // 3. Pedir dados da compra
                        printf("Digite o Codigo do Produto: ");
                        scanf("%d", &codigo);
                        
                        // Verifica se produto existe
                        Produto *prod = buscarProduto(listaProduto, codigo);
                        if(prod == NULL){
                            printf("Produto nao existe!\n");
                        } else {
                            printf("Digite a Quantidade: ");
                            scanf("%d", &qtd);
                            // Chama a função do carrinho.c
                            adicionar_ao_carrinho(clienteEncontrado, codigo, qtd);
                        }
                    }
                    break;

                case 2: // LISTAR CARRINHO
                    limpar_tela();
                    printf("--- Listar carrinho ---\n");
                    printf("CPF do Cliente: ");
                    fgets(cpf, sizeof(cpf), stdin);
                    retirar_enter(cpf);
                    
                    clienteEncontrado = retornar_cliente(listaCliente, cpf);
                    if(clienteEncontrado != NULL){
                        // Chama a função passando a lista de produtos (para pegar o nome/preço)
                        listar_carrinho(clienteEncontrado, listaProduto);
                    } else {
                        printf("Cliente nao encontrado.\n");
                    }
                    break;

                case 3: // REMOVER DO CARRINHO
                    limpar_tela();
                    printf("--- Retirar produto do carrinho ---\n");
                    printf("CPF do Cliente: ");
                    fgets(cpf, sizeof(cpf), stdin);
                    retirar_enter(cpf);
                    
                    clienteEncontrado = retornar_cliente(listaCliente, cpf);
                    if(clienteEncontrado != NULL){
                        // Mostra o que tem antes de pedir pra remover
                        listar_carrinho(clienteEncontrado, listaProduto);
                        
                        if(clienteEncontrado->carrinho != NULL) {
                            printf("\nCodigo do produto a remover: ");
                            scanf("%d", &codigo);
                            printf("Quantidade a remover: ");
                            scanf("%d", &qtd);
                            remover_do_carrinho(clienteEncontrado, codigo, qtd);
                        }
                    } else {
                        printf("Cliente nao encontrado.\n");
                    }
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
            // Idealmente deveria ter destruir_lista_produtos(listaProduto) também
            break;

        default:
            printf("Opção inválida\n");
        }
    }
   
    return 0;
}