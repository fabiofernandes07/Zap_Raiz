#include "Contato.h"

void menu(){

    printf("1 -> Adcionar contato\n2 -> Listar contatos\n3 -> Remover contatos\n4 -> Editar contatos\n5 -> Voltar\n");
    printf("-> ");
}

void adcionarContato() {
    FILE *arquivo;
	int cont0 = 0;
    tContato contato;
	char contnome[20];



    arquivo = fopen("Listadepessoas.txt","r");

    if (arquivo == NULL){
    	arquivo = fopen("Listadepessoas.txt","a");
        printf("Nao abriu\n");
        fclose(arquivo);

    }else{
	tContato contato;
        printf("\nDigite nome do contato: ");
        limpabuffer();
        scanf("%s",&contnome);

	while(fscanf(arquivo,"%s %s\n",&contato.nome,&contato.ip)!=EOF){
            if(strcmp(contnome,contato.nome) == 0){
            	cont0 = 1;
            }
        }
        fclose(arquivo);

        if(cont0 == 1){
        	printf("\nContato ja existe");
	}else{
            arquivo = fopen("Listadepessoas.txt","a");
            printf("\nDigite o ip do contato: ");
            scanf("%s",&contato.ip);


            fprintf(arquivo,"%s %s\n",contnome,contato.ip);
            fclose(arquivo);
	}
    }

}

void ListarContatos(){
    FILE *arquivo;

    arquivo = fopen("Listadepessoas.txt","r");
    if(arquivo == NULL){
        printf("\nNao abriu\n");
        fclose(arquivo);

    }else{
        tContato contato;
        int cont0 = 0;

        while(fscanf(arquivo,"%s %s",&contato.nome,&contato.ip)!=EOF){
            printf("\nNOME: %s\nIP: %s\n\n",contato.nome,contato.ip);
                cont0++;
            }
        if(cont0 == 0)
            printf("\nNao ha pessoas cadastradas!\n");

         }

        fclose(arquivo);
}

void removerContato(){
    FILE *arquivo,*arquivo2;
    char remover[50];

    arquivo = fopen("Listadepessoas.txt","r");
    arquivo2 = fopen("Listadepessoas2.txt","a");

    if(arquivo == NULL || arquivo2 == NULL){
        printf("\nNao abriu\n");
        fclose(arquivo);

    }else {
        tContato contato;
        printf("\nQuem deseja remover: ");
        scanf("%s",&remover);
        int cont1 = 0, cont2 = 0;

        while(fscanf(arquivo,"%s %s",&contato.nome,&contato.ip)!=EOF){
            cont1++;
            if(strcmp(remover,contato.nome) != 0){
                fprintf(arquivo2,"%s %s\n",contato.nome,contato.ip);
                cont2++;
            }
        }
		fclose(arquivo);
        fclose(arquivo2);

        if(cont1 == cont2){
            printf("\nContato nao adicionado!\n");
        }else{
            printf("\nContato removido\n");

            remove("Listadepessoas.txt");
			rename("Listadepessoas2.txt","Listadepessoas.txt");
    	}
	}

}

void editarContato() {
	FILE *arquivo,*arquivo2;
    char editar[20];
    int cont1 = 0,cont2 = 0;

    arquivo = fopen("Listadepessoas.txt","r");
    arquivo2 = fopen("Listadepessoas2.txt","w");

    if(arquivo == NULL || arquivo2 == NULL){
        printf("\nNao abriu\n");
        fclose(arquivo);

    }else{
        tContato contato;
        printf("\nDigite o nome do contato que deseja editar: ");
        scanf("%s",&editar);
        limpabuffer();


        while(fscanf(arquivo,"%s %s\n",&contato.nome,&contato.ip)!=EOF){
            if(strcmp(editar,contato.nome) != 0){
				fprintf(arquivo2,"%s %s\n",contato.nome,contato.ip);
            }
            else{
                cont1++;
            }

        }
        if(cont1 == 0){
            printf("\nContato nao encontrado\n");

        }else{
            limpabuffer();
            printf("\nDigite o novo nome do contato: ");
            scanf("%s",contato.nome);
            limpabuffer();
            printf("\nDigite o novo ip do contato: ");
            scanf("%s",&contato.ip);
            limpabuffer();

            fprintf(arquivo2,"%s %s\n",contato.nome,contato.ip);
            printf("\nEDITADO!\n");

        }

        fclose(arquivo);
        fclose(arquivo2);

        remove("Listadepessoas.txt");
        rename("Listadepessoas2.txt","Listadepessoas.txt");

	}
}
