#include <stdio.h>
#include "util.h"
#include "clientes.h"

int main(){
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