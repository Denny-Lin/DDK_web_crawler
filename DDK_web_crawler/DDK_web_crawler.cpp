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

	client->socket();

	client->connect("74.6.136.150", 80);

	client->send("GET / HTTP/1.1\r\n\r\n");

	client->receive();

	client->close();
}
