// DDK_web_crawler.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>
#include<winsock2.h>
#include "web_crawler.h"
#pragma comment(lib,"ws2_32.lib") //Winsock Library
using namespace std;
#pragma warning(disable : 4996)


int main()
{
	WSADATA* wsa = new WSADATA;
	SOCKET* s = new SOCKET;
	struct sockaddr_in* server = new struct sockaddr_in;

	winsock_init(wsa);
	create_socket(s);
	server_init(server);
	server_connect(s,server);

	/*const char* url= (char*)malloc(15*sizeof(char));
	url = "Hello World!";
	url = "Hello";
	cout << url << endl;*/

	send_data(s,"Hello World!");

}
