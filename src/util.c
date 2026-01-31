#include "util.h"
#include <stdio.h>
#include <string.h>

void retirar_enter(char *str){
    str[strcspn(str,"\n")] = '\0';
}