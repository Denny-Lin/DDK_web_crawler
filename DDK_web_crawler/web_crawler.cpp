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
	server->sin_addr.s_addr = inet_addr("127.0.0.1");
	server->sin_family = AF_INET;
	server->sin_port = htons(27015);

	printf("Server initialised.\n");
}

int server_connect(SOCKET* s, struct sockaddr_in* server) {
	//Connect to remote server
	if (connect(*s, (struct sockaddr *)server, sizeof(*server)) < 0)
	{
		puts("connect error\n");
		if(WSAGetLastError() == 10061)
			cout << "連接遭到拒絕。\n因為目的電腦主動拒絕連線，所以無法進行連接。\n這通常是因為嘗試連接至外部主機上非使用中的服務（也就是沒有執行伺服器應用程式的服務）的結果。\n" << endl;
		return 0;
	}

	puts("Connected");
	return 1;
}

int send_data(SOCKET* s, const char* message) {
	//Send some data
	message = "GET / HTTP/1.1\r\n\r\n";
	if (send(*s, message, strlen(message), 0) < 0)
	{
		puts("Send failed\n");
		return 0;
	}
	
	puts("Data Send\n");
	puts(message);
	puts("\n");
	return 1;
}