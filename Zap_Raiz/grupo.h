#ifndef _Grupo_
#define _Grupo_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct grupo{
    char nome_grupo[40];
    char participante[40];

}tGrupo;

extern void criar_grupo();
extern void ListarGrupos();
extern void removerGrupo();
extern void AdicionarParticipante();
#endif
