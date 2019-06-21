#include "client_udp.h"
#include "Contato.h"
#include "Conta.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256



int client() {
    int argc =3;
    int sock, n;
    unsigned int length;
    char buffer[BUFFER_SIZE];
   int i;

 //verificar contato
 limpartela();
  int cont1=0,cont2=0,rep = 0;
	FILE *arqlogin;
	char conversa[20];
	char ipcont[20];
  	char contusuario[20];
	arqlogin = fopen("Grupos.txt","r");

    tContato contato;
    if (arqlogin == NULL){
        printf("Nao abriu\n");
        fclose(arqlogin);

    }else{
      do {
        fclose(arqlogin);
        arqlogin = fopen("Grupos.txt","r");
        tContato contato;
        //printf("\nConfirme o seu Usuario: ");
        //limpabuffer();
        //scanf("%s",contusuario);
        printf("\nDigite o Grupo: ");
        limpabuffer();
        scanf("%s",&conversa);

        while(fscanf(arqlogin,"%s %s %s",&grupo.nome_grupo,&grupo.participante)!=EOF){
            if(strcmp(conversa,grupo.nome_grupo) == 0){
                cont2=1;
		strcpy(ipcont[rep],contato.ip);
                fclose(arqlogin);
		rep ++;


            }
        }


        if(cont2 != 1) {
            printf("\nContato nao encontrado\n");
            printf("Pressione ENTER para continuar");
            limpabuffer();
            pausar();

        }
      }while(cont2 == 0);
      }

    // A estrutura sockaddr_in contem um endereco de internet
    struct sockaddr_in server, from;

    // A estrutura hostent representa um host na Internet
    struct hostent *hp;

    if (argc !=  3) {
        printf("Usage: server port\n");
        exit(1);
    }

    for (i=0;i < rep ;i++) {	
  
  
    // Cria um socket do tipo datagrama e retorna um descritor
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock < 0) error("socket");

    // Define a familia do endereco como do tipo Internet
    server.sin_family = AF_INET;

    // Preenche a estrutura "hp" a partir do nome da maquina ou de seu IP
    hp = gethostbyname(ipcont[i]);

    if (hp == 0) error("Unknown host");

    // Copia o IP da estrutura "hp" para a estrutura "server"
    bcopy( (char *) hp->h_addr, (char *) &server.sin_addr, hp->h_length);

    // A funcao htons() converte o numero da porta para o padrao Little Endian.
    char portac[10];
    limpartela();
    printf("\nDigite a porta: ");
    limpabuffer();
    scanf("%s",&portac);
    limpartela();
    server.sin_port = htons(atoi(portac));
    length = sizeof(struct sockaddr_in);

    printf("mensagem: ");

    // Zera o buffer
    bzero(buffer, BUFFER_SIZE);

    fgets(buffer, 255, stdin);


    // Envia dados pela rede. Parametros: socket, buffer que contem os dados,
    // tamanho do buffer, flags, endereco da maquina destino, tamanho da estrutura do endereco.
    // Retorna o numero de bytes enviados.
    n = sendto(sock, buffer, strlen(buffer), 0, (const struct sockaddr *) &server, length);

    if(strcmp(buffer,"xau\n")== 0){
      return 0;
    }

    if (n < 0) error("Sendto");

    // A funcao recvfrom() bloqueia o programa ate que um pacote seja lido.
    // Quando isso acontece, o pacote e' armazenado em um buffer passado por
    // parametro. Parametros: socket, buffer, tamanho do buffer, flags,
    // endereco da maquina que enviou o pacote, tamanho da estrutura do endereco.
    // Retorna o numero de bytes recebidos.
    n = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &from, &length);

    if (n < 0) error("recvfrom");

    write(1, "\n",3);
    write(1, buffer, n);

    close(sock);
 }
    return 0;
}
