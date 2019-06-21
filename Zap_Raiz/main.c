#include "client_udp.h"
#include "server_udp.h"
#include "Conta.h"
#include "Contato.h"
#include "grupo.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int op=0,op1=0,op2=0,op3=0,op4=0,op5=0;
    int gerenciamento;

    do {

        limpabuffer();
        menu_login();
        scanf("%d",&op);
        limpabuffer();


        //op�oes de login
        switch(op) {
            limpabuffer();

            case 1:
                limpabuffer();
                limpartela();

                if(set_login() == 0) {
                    limpartela();

                    do {//conversa e gerenciamento de contato
			printf("*******Bem-vindo ao zap raiz*******");
                        printf("\n1 -> Conversar\n2 -> Gerenciar Contatos\n3 -> Gerenciar Conta\n4 -> Gerenciar Grupos\n5 -> Voltar\n-> ");
                        limpabuffer();
                        scanf("%d",&op1);
                        limpartela();

                            switch(op1) {

                            case 1:


                                do {
                                  limpartela();
                                  printf("1 -> Cliente\n2 -> Servidor\n3 -> Grupo\n4 -> Voltar\n-> ");
                                  scanf("%d",&op2);
                                  limpabuffer();

                                    switch(op2) {

                                    case 1:
					                               client();

                                        break;

                                    case 2:
                                        server();

                                        break;


                                    case 3:

                                      break;


                                    }

                                }while(op2 != 4);

                                break;

                            case 2:
                                limpartela();

                                do {
                                    menu();
                                    scanf("%d",&op3);
                                    limpabuffer();
                                    switch(op3) {

                                        case 1:
                                            limpartela();
                                            adcionarContato();

                                            break;
                                        case 2:
                                            limpartela();
                                            ListarContatos();
                                            printf("\nPressione ENTER para continuar");
                                            pausar();
                                            break;
                                        case 3:
                                            limpartela();
                                            removerContato();
                                            printf("\nPressione ENTER para continuar");
                                            pausar();
                                            break;
                                        case 4:
                                            limpartela();
                                            editarContato();
                                            printf("\nPressione ENTER para continuar");
                                            pausar();
                                            break;
                                    }


				limpartela();
                                }while(op3 != 5);

                                break;

                             case 3:
                                 limpartela();

                                 do {
                                    printf("1 -> Editar Conta\n2 -> Excluir Conta\n3 -> Voltar\n");
                                    printf("-> ");
                                    limpabuffer();
                                    scanf("%d",&gerenciamento);

                                    switch(gerenciamento) {

                                        case 1:
                                            limpartela();
                                            editar_conta();

                                            printf("\nPressione ENTER para continuar");
					                                  limpabuffer();
                                            pausar();
                                            break;

                                        case 2:
                                            limpartela();
                                            excluir_conta();
                                            printf("\nPressione ENTER para continuar");
					                                  limpabuffer();
                                            pausar();
                                            break;
                                    }

                                 limpartela();
                                 }while (gerenciamento != 3);

                          case 4:


                          do{
                            printf("1 -> Criar grupo\n2 -> Adicionar contato no grupo\n3 -> Excluir grupo\n4 -> Listar Grupos\n5 -> Voltar\n");
                            printf("-> ");
                            limpabuffer();
                            scanf("%d",&op5);
                            switch (op5) {
                                case 1:

                                  limpartela();
                                  criar_grupo();
                                  printf("\nPressione ENTER para continuar");
                                  limpabuffer();
                                  pausar();
                                  limpartela();
                                  break;

                                case 2:

                                  limpartela();
                                  AdicionarParticipante();
                                  printf("\nPressione ENTER para continuar");
                                  limpabuffer();
                                  pausar();
                                  limpartela();

                                  break;

                                case 3:

                                  limpartela();
                                  removerGrupo();
                                  printf("\nPressione ENTER para continuar");
                                  limpabuffer();
                                  pausar();
                                  limpartela();

                                  break;

                                case 4:

                                  limpartela();
                                  ListarGrupos();
                                  printf("\nPressione ENTER para continuar");
                                  limpabuffer();
                                  pausar();
                                  limpartela();

                                  break;
                            }

                          }while(op5 != 5);

                          }

                    limpartela();
                  }while(op1 != 5);

                }

		pausar();
                break;
            case 2:
                limpartela();
                set_cadastro();

                limpabuffer();
                pausar();
                break;

        }

    limpartela();
    }while(op != 3);

	return 0;
}
