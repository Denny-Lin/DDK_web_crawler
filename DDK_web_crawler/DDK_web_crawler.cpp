// DDK_web_crawler.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>
#include<winsock2.h>
#include "web_crawler.h"
#pragma comment(lib,"ws2_32.lib") //Winsock Library
using namespace std;
#pragma warning(disable : 4996)

int main(int argc, char* argv[])
{
	const char *message;

	web_crawler_t* client = new struct web_crawler;

	client->socket();

	//download the pdf from https://www.axmag.com/download/UserGuide.pdf
	client->connect( DNStoIP("www.axmag.com"), 80); //47.88.2.145
	message = "GET /download/UserGuide.pdf HTTP/1.1\r\nHost: www.axmag.com\r\n\r\n Connection: keep-alive\r\n\r\n Keep-Alive: 300\r\n";
	
	//download the png from https://www.google.com/images/branding/googlelogo/1x/googlelogo_color_272x92dp.png
	//client->connect( DNStoIP("www.google.com"), 80); //172.217.160.100
	//message = "GET /images/branding/googlelogo/1x/googlelogo_color_272x92dp.png HTTP/1.1\r\nHost: www.google.com\r\n\r\n Connection: keep-alive\r\n\r\n Keep-Alive: 300\r\n";

	client->send(message);

	client->receive();

	client->close();
}
