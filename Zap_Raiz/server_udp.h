#ifndef _server_udp_
#define _server_udp_

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>
#include <arpa/inet.h>

extern void error(const char *msg);
extern int server();

#endif


