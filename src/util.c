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