// DDK_web_crawler.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>
#include<winsock2.h>
#include "web_crawler.h"
#pragma comment(lib,"ws2_32.lib") //Winsock Library
using namespace std;
#pragma warning(disable : 4996)

typedef struct web_crawler {
	WSADATA* wsa;
	SOCKET* s;
	struct sockaddr_in* server;
}web_crawler;

int main()
{
	WSADATA* wsa = new WSADATA;
	SOCKET* s = new SOCKET;
	struct sockaddr_in* server = new struct sockaddr_in;

	winsock_init(wsa);
	create_socket(s);
	server_init(server, "74.6.136.150", 80);// yahoo.com.tw
	server_connect(s, server);

	send_data(s,"GET / HTTP/1.1\r\n\r\n");//send request

	receive_data(s);//sever response
	
}
