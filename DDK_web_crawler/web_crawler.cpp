#include <iostream>
#include <string>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib") //Winsock Library
#include "ws2tcpip.h"
#include "web_crawler.h"
using namespace std;
#pragma warning(disable:4996) 

int winsock_init(WSADATA* wsa) {

	printf("Initialising Winsock...\n");

	if (WSAStartup(MAKEWORD(2, 2), wsa) != 0)
	{
		printf("Failed. Error Code : %d\n", WSAGetLastError());
		return 0;
	}

	printf("Winsock initialised.\n");
	return 1;
}

int create_socket(SOCKET* s) {
	if ((*s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d\n", WSAGetLastError());
		return 0;
	}

	printf("Socket created.\n");
	return 1;
}

void server_init(struct sockaddr_in* server) {
	server->sin_addr.s_addr = inet_addr("74.6.136.150"); //IP 74.6.136.150 127.0.0.1
	server->sin_family = AF_INET;
	server->sin_port = htons(80); //port

	printf("Server initialised.\n");
}

int server_connect(SOCKET* s, struct sockaddr_in* server) {
	//Connect to local server
	//if (bind(*s, (struct sockaddr *)server, sizeof(*server)) < 0)
	//Connect to remote server
	if (connect(*s, (struct sockaddr *)server, sizeof(*server)) < 0)
	{
		puts("connect error\n");
		if(WSAGetLastError() == 10061)
			cout << "�s���D��ڵ��C\n�]���ت��q���D�ʩڵ��s�u�A�ҥH�L�k�i��s���C\n�o�q�`�O�]�����ճs���ܥ~���D���W�D�ϥΤ����A�ȡ]�]�N�O�S��������A�����ε{�����A�ȡ^�����G�C\n" << endl;
		return 0;
	}

	puts("Server connected.");
	return 1;
}

int send_data(SOCKET* s, const char* message) {
	//Send some data
	//message = "GET / HTTP/1.1\r\n\r\n"; //CRLF (carriage return followed by line feed)
	if (send(*s, message, strlen(message), 0) < 0)
	{
		puts("Send failed\n");
		return 0;
	}
	
	cout << "Send data: " << message << endl;

	return 1;
}

int receive_data(SOCKET* s) {
	char server_reply[200]; //If this buffer size over 1M, it will lead to overflow.
	int recv_size;

	if ((recv_size = recv(*s, server_reply, 200 -1, 0)) == SOCKET_ERROR)
	{
		puts("recv failed");
		return 0;
	}

	//cout << recv_size << endl;  //Debug
	puts("Reply received\n");

	//Add a NULL terminating character to make it a proper string before printing
	server_reply[recv_size] = '\0';
	puts(server_reply);

	return 1;
}