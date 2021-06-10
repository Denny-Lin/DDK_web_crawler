//#pragma once
#ifndef _WEB_CRAWLER_
#define _WEB_CRAWLER_
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib") //Winsock Library

typedef struct web_crawler {
	WSADATA* wsa;
	SOCKET* s;
	struct sockaddr_in* server;

	int socket();
	int connect();
	int send(const char*);
	int receive();
}web_crawler_t;

int web_crawler_init(web_crawler_t*);

int winsock_init(WSADATA*); //Winsock startup.

int create_socket(SOCKET*); //Create a local socket and use this socket to connect a remote machine.

void server_init(struct sockaddr_in*, const char* , const int); //Initialize the server you want to connect

int connect_server(SOCKET*, struct sockaddr_in*); //Connected to server by socket.

int send_data(SOCKET*, const char*); //Send data to server.

int receive_data(SOCKET*); //Receive data from server.

#endif // !_WEB_CRAWLER_