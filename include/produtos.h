#ifndef PRODUTOS_h
#define PRODUTOS_H
typedef struct Produto
{
    int codigo;
    char nome[100];
    float preco;
    struct Produto *prox;
    
}Produto;

//cria um novo produto
Produto *criar_produto(int codigo,char *nome, float preco);

//insere um produto na primeira posicao da lista
void inserir_produto(Produto **listaProduto, int codigo,char *nome, float preco);

//alterar nome e preco de um produto a partir de seu codigo
void alterar_produto(Produto **listaProduto, int codigo,char *nome, float preco );

//imprimir a lista de produtos
void imprimir_produtos(Produto *listaProduto);

//imprimir um produto de acordo com o codigo informado, retorna 0 se não encontrar, 1 se encontrar
int imprimir_produto(Produto *listaProduto,int codigo);

//indica se o produto existe, buscando por codigo, 1 existe, 0 nao existe
int existe_produto(Produto *listaProduto, int codigo);

//retorna o produto do codigo informado
Produto *retornar_produto(Produto *listaProduto, int codigo);

//exclui o produto do codigo informado
void excluir_produto(Produto **listaProduto, int codigo);

//libera a area de memoria da lista de produtos
void destruir_lista_produtos(Produto *listaProduto);



#endif