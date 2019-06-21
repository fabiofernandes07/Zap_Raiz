#include "Contato.h"
#include "Conta.h"

void limpartela(){
	system("clear");
}
void pausar(){
	getchar();
}
void menu_login(){

	printf("\n**************************");
    printf("\n1-> Login\n2-> Cadastro\n3-> Sair\n");
	printf("**************************\n->");
}

void limpabuffer(){

    setbuf(stdin,NULL);
}

char fusuario[20],fsenha[20];
int logado = 0;
int i = 0;

//Verificar Login
int set_login(){
	FILE *arqlogin;
	char fusuario[20],fsenha[20];
	limpabuffer();

	printf("\nDigite seu Login: ");
	scanf("%s",&fusuario);
	limpabuffer();
	printf("\nDigite sua senha: ");
	scanf("%s",&fsenha);

	arqlogin = fopen("conta.txt","r");
    tConta conta;

    if (arqlogin == NULL){
        printf("Nao abriu\n");
        fclose(arqlogin);

    }else {
        while(fscanf(arqlogin,"%s %s",&conta.usuario,&conta.senha)!=EOF) {
            if(strcmp(conta.usuario, fusuario) == 0 && strcmp(conta.senha, fsenha) == 0 ) {
                fclose(arqlogin);
                return 0;
            }
        }
    }

    limpartela();
    fclose(arqlogin);
    printf("\nLogin Invalido\n");
    printf("\nPressione ENTER para continuar");
    pausar();

	return 1;
}
//Fazer cadastro
void set_cadastro(){
	int cont1=0,cont2=0,rep = 0;
	FILE *arqlogin;
	char cadastro[20];

	arqlogin = fopen("conta.txt","r");

    tConta conta;
    if (arqlogin == NULL){
        printf("Nao abriu\n");
        fclose(arqlogin);

    }else{
        tConta conta;
        printf("\nDigite o usuario: ");
        limpabuffer();
        scanf("%s",&cadastro);

        while(fscanf(arqlogin,"%s %s\n",&conta.usuario,&conta.senha)!=EOF){
            if(strcmp(cadastro,conta.usuario) == 0){
                cont2=1;
            }
        }
        fclose(arqlogin);

        if(cont2 == 1) {
            printf("\nUsuario ja cadastrado\n");
            printf("Pressione ENTER para continuar");
            pausar();
            rep = 1;
        }

        if(rep == 0) {
            arqlogin = fopen("conta.txt","a");
            printf("\nDigite sua senha: ");
            scanf("%s",&conta.senha);
            limpabuffer();

            fprintf(arqlogin,"%s %s\n",cadastro,conta.senha);
            fclose(arqlogin);
            limpartela();
        }

    }

}

void editar_conta(){
    FILE *conta1;
    FILE *conta2;

    char editarconta[20];
    int cont1 = 0;

    conta1 = fopen("conta.txt","r");
    conta2 = fopen("conta2.txt","w");

    if(conta1 == NULL || conta2 == NULL){
        printf("\nNao abriu\n");
        fclose(conta1);

    }else{
        tConta conta;
        printf("\nDigite o nome da conta que deseja editar: ");
        scanf("%s",&editarconta);
        limpabuffer();

        while(fscanf(conta1,"%s %s",&conta.usuario,&conta.senha)!=EOF){
            if(strcmp(editarconta,conta.usuario) != 0){
				fprintf(conta2,"%s %s\n",conta.usuario,conta.senha);
            }
            else{
                cont1++;
            }

        }
        if(cont1 == 0){

            printf("\nUsuario invalido\n");

        }else{
            limpabuffer();
            printf("\nDigite o novo nome da conta: ");
            scanf("%s",conta.usuario);
            limpabuffer();
            printf("\nDigite a nova senha da conta: ");
            scanf("%s",&conta.senha);
            limpabuffer();

            fprintf(conta2,"%s %s\n",conta.usuario,conta.senha);
            printf("\nEDITADO!\n");

        }

        fclose(conta1);
        fclose(conta2);

        remove("conta.txt");
        rename("conta2.txt","conta.txt");

	}
}

void excluir_conta(){
    FILE *conta1;
    FILE *conta2;
    char removerUsuario[50];

    conta1 = fopen("conta.txt","r");
    conta2 = fopen("conta2.txt","a");

    if(conta1 == NULL || conta2 == NULL){
        printf("\nNao abriu\n");
        fclose(conta1);

    }else {
        tConta conta;
        printf("\nConfirme seu usuario: ");
        scanf("%s",&removerUsuario);
        int cont1 = 0, cont2 = 0;

        while(fscanf(conta1,"%s %s",&conta.usuario,&conta.senha)!=EOF){
            cont1++;
            if(strcmp(removerUsuario,conta.usuario) != 0){
                fprintf(conta2,"%s %s\n",conta.usuario,conta.senha);
                cont2++;
            }
        }
		fclose(conta1);
        fclose(conta2);

        if(cont1 == cont2){
            printf("\nConta nao cadastrada!\n");
        }else{
            printf("\nConta removida\n");

            remove("conta.txt");
			rename("conta2.txt","conta.txt");

    	}
	}

}


	
