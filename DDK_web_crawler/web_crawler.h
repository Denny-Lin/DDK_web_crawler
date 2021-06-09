//#pragma once
#ifndef _WEB_CRAWLER_
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib") //Winsock Library

int winsock_init(WSADATA*); //Winsock startup.

int create_socket(SOCKET*);

void server_init(struct sockaddr_in*); //Initialize the server you want to connect

int server_connect(SOCKET*, struct sockaddr_in*); //Connected to server by socket.

int send_data(SOCKET*, const char*); //Send data to server.

int receive_data(SOCKET*); //Receive data from server.

#endif // !_WEB_CRAWLER_