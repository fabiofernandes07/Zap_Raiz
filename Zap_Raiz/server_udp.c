#include "server_udp.h"
#include "Conta.h"

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>
#include <arpa/inet.h>





void error(const char *msg) {
    perror(msg);
    exit(0);
}

int server() {


#define BUFFER_SIZE 1316

    limpartela();
    char porta[10];
    printf("\nDigite a porta\n->");
    scanf("%s",porta);
    limpartela();
    int argc = 2;
    int sock, length, n, sock2;
    socklen_t fromlen;

    // A estrutura sockaddr_in contem um endereco de internet
    struct sockaddr_in server;
    struct sockaddr_in from;
    struct sockaddr_in destiny;


    // Buffer para receber mensagens
    char buf[BUFFER_SIZE];

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(0);
    }

    // Cria um socket do tipo datagrama e retorna um descritor
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock < 0) error("Opening socket");

    length = sizeof(server);

    // Zera a estrutura "server"
    bzero(&server, length);
    // Define a familia do endereco como do tipo Internet
    server.sin_family = AF_INET;
    // Seta o endereco para localhost (127.0.0.1)
    server.sin_addr.s_addr = INADDR_ANY;
    // A funcao htons() converte o numero da porta para o padrao Little Endian.
    server.sin_port = htons(atoi(porta));


    sock2 = socket(AF_INET, SOCK_STREAM, 0);

    length = sizeof(destiny);
    // Zera a estrutura "server"
    bzero(&destiny, length);
    // Define a familia do endereco como do tipo Internet
    destiny.sin_family = AF_INET;
    // Seta o endereco para localhost (127.0.0.1)
    destiny.sin_addr.s_addr = INADDR_ANY;
    // A funcao htons() converte o numero da porta para o padrao Little Endian.
    destiny.sin_port = htons(4000);


    // Associa um socket a um endereco
    if (bind(sock, (struct sockaddr *) &server, length) < 0)
        error("binding");

    fromlen = sizeof(struct sockaddr_in);

    while (1) {
        // A funcao recvfrom() bloqueia o programa ate que um pacote seja lido.
        // Quando isso acontece, o pacote e' armazenado em um buffer passado por
        // parametro. Parametros: socket, buffer, tamanho do buffer, flags,
        // endereco da maquina que enviou o pacote, tamanho da estrutura do endereco.
        // Retorna o numero de bytes recebidos.
        n = recvfrom(sock, buf, BUFFER_SIZE, 0, (struct sockaddr *) &from, &fromlen);

        if (n < 0) error("recvfrom");

	write(1,buf,n);



	printf("Mensagem: ");
	fgets(buf, 255, stdin);
	n=strlen(buf);

  if(strcmp(buf,"xau\n")==0) {
    
    return 0;


  }


        // Envia pacotes pela rede. Os parametros sao semelhantes aos da funcao recvfrom().
        n = sendto(sock, buf, n, 0, (struct sockaddr *) &from, fromlen);
        //printf("n = %d\n", n);

        //if (n < 0) error("sendto");
    }


    return 0;
 }
