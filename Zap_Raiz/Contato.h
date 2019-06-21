#ifndef _Contato_
#define _Contato_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contato{
  
    char nome[40];
    char ip[40];
    char usuario[20];

}tContato;

extern void adcionarContato();
extern void limpabuffer();
extern void menu();
extern void ListarContatos();
extern void removerContato();
extern void editarContato();
#endif
