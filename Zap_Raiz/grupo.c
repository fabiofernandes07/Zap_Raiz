#include "grupo.h"

void criar_grupo() {
    FILE *arquivo;
		int cont0 = 0;
    tGrupo grupo;
		char grupnome[20];

    arquivo = fopen("Grupos.txt","r");

    if (arquivo == NULL){
    	arquivo = fopen("Grupos.txt","a");
        printf("Nao abriu\n");
        fclose(arquivo);

    }else{
	tGrupo grupo;
        printf("\nDigite nome do grupo: ");
        limpabuffer();
        scanf("%s",&grupnome);

	while(fscanf(arquivo,"%s %s\n",&grupo.nome_grupo,&grupo.participante)!=EOF){
            if(strcmp(grupnome,grupo.nome_grupo) == 0){
            	cont0 = 1;
            }
        }
        fclose(arquivo);

        if(cont0 == 1){
        	printf("\nGrupo ja existe");
	}else{
            arquivo = fopen("Grupo.txt","a");
            printf("\nDigite seu usuario: ");
            scanf("%s",&grupo.participante);


            fprintf(arquivo,"%s %s\n",grupnome,grupo.participante);
            fclose(arquivo);
	}
  }


}

void ListarGrupos(){
    FILE *arquivo;

    arquivo = fopen("Grupo.txt","r");
    if(arquivo == NULL){
        printf("\nNao abriu\n");
        fclose(arquivo);

    }else{
        tGrupo grupo;
        int cont0 = 0;

        while(fscanf(arquivo,"%s %s",&grupo.nome_grupo,&grupo.participante)!=EOF){
            printf("%s %s\n",grupo.nome_grupo,grupo.participante);
                cont0++;
            }
        if(cont0 == 0)
            printf("\nNao ha grupos cadastrados!\n");

         }

        fclose(arquivo);
}

void removerGrupo() {
    FILE *arquivo,*arquivo2;
    char remover[50];

    arquivo = fopen("Grupo.txt","r");
    arquivo2 = fopen("Grupo2.txt","a");

    if(arquivo == NULL || arquivo2 == NULL){
        printf("\nNao abriu\n");
        fclose(arquivo);

    }else {
        tGrupo grupo;
        printf("\nQual grupo excluir: ");
        scanf("%s",&remover);
        int cont1 = 0, cont2 = 0;

        while(fscanf(arquivo,"%s %s",&grupo.nome_grupo,&grupo.participante)!=EOF){
            cont1++;
            if(strcmp(remover,grupo.nome_grupo) != 0){
                fprintf(arquivo2,"%s %s\n",grupo.nome_grupo,grupo.participante);
                cont2++;
            }
        }
		fclose(arquivo);
        fclose(arquivo2);

        if(cont1 == cont2){
            printf("\nGRUPO nao existe!\n");
        }else{
            printf("\nGRUPO removido\n");

            remove("Grupo.txt");
			rename("Grupo2.txt","Grupo.txt");
    	}
	}

}

void AdicionarParticipante() {
  FILE *arquivo;
  int cont0 = 0;
  tGrupo grupo;
  char grupnome[20];

  arquivo = fopen("Grupos.txt","r");

  if (arquivo == NULL){
    arquivo = fopen("Grupos.txt","a");
      printf("Nao abriu\n");
      fclose(arquivo);

  }else{
tGrupo grupo;
      printf("\nDigite nome do grupo: ");
      limpabuffer();
      scanf("%s",&grupnome);

while(fscanf(arquivo,"%s %s\n",&grupo.nome_grupo,&grupo.participante)!=EOF){
          if(strcmp(grupnome,grupo.nome_grupo) == 0){
            cont0 = 1;
          }
      }
      fclose(arquivo);


          arquivo = fopen("Grupo.txt","a");
          printf("\nDigite seu usuario: ");
          scanf("%s",&grupo.participante);


          fprintf(arquivo,"%s %s\n",grupnome,grupo.participante);
          fclose(arquivo);

}


}
