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
	const char *message;

	web_crawler_t* client = new struct web_crawler;

	client->socket();

	//client->connect("74.6.136.150", 80);

	//client->send("GET / HTTP/1.1\r\n\r\n");

	//GET /file.pdf HTTP/1.1\r\nHost: www.site.com\r\n\r\n

	//1.pdf
	//ping www.axmag.com
	//https://www.axmag.com/download/UserGuide.pdf
	client->connect("47.88.2.145", 80); 
	message = "GET /download/UserGuide.pdf HTTP/1.1\r\nHost: www.axmag.com\r\n\r\n Connection: keep-alive\r\n\r\n Keep-Alive: 300\r\n";
	
	//2.png
	//https://www.google.com/images/branding/googlelogo/1x/googlelogo_color_272x92dp.png
	//ping www.google.com
	//client->connect("172.217.160.100", 80);
	//message = "GET /images/branding/googlelogo/1x/googlelogo_color_272x92dp.png HTTP/1.1\r\nHost: www.google.com\r\n\r\n Connection: keep-alive\r\n\r\n Keep-Alive: 300\r\n";

	client->send(message);

	client->receive();

	client->close();
}
