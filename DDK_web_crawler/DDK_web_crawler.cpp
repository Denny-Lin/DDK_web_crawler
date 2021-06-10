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
	web_crawler_t* client = new struct web_crawler;

	web_crawler_init(client);

	client->socket();

	client->connect();

	client->send("GET / HTTP/1.1\r\n\r\n");

	client->receive();
}
