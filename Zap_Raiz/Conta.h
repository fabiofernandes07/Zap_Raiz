#ifndef _CONTA_
#define _CONTA_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct conta{
    char usuario[20];
    char senha[20];

}tConta;
 extern char *verif_conta();
 extern int set_login();
 extern void menu_login();
 extern void limpabuffer();
 extern void set_cadastro();
 extern void editar_conta();
 extern void excluir_conta();
 extern void limpartela();
 extern void pausar();
#endif
