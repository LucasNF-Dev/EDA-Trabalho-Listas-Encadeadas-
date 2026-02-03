#ifndef CARRINHO_H
#define CARRINHO_H


typedef struct Cliente Cliente;
typedef struct Produto Produto;

typedef struct ItemCompra
{
    char cpfCliente[20];
    int codigoProduto;
    int quantidade;
    struct ItemCompra *prox;
    
}ItemCompra;



//cria um novo item de compra
ItemCompra *criar_item_compra(char *cpfCliente,int codigoProduto, int quantidade);

//insere um item de compra na primeira posicao da lista
void inserir_item_compra(ItemCompra **listaCompras, Cliente *listaCliente, Produto *listaProduto,char *cpfCliente,int codigoProduto, int quantidade );

//imprimir a lista de compras de um determinado cliente (informando o cpf)
void imprimir_itens_compra_cliente(ItemCompra *listaCompras,Cliente *listaCliente, Produto *listaProduto, char *cpfCliente);

//retorna um item de compra a partir de um cliente e produto
ItemCompra *retornar_item_compra(ItemCompra *listaCompras, char *cpfCliente, int codigoProduto);

//exclui um item de compra a partir de um cliente e produto
void excluir_item_compra(ItemCompra **listaCompras, char *cpfCliente, int codigoProduto);

//libera a area de memoria da lista de compras
void destruir_lista_item_compra(ItemCompra *listaCompras);


#endif