#include "stdafx.h"
#include "sendByTCP.h"
#include "protocol.h"

#include <winsock2.h>
#include <windows.h>
#include <stdio.h>


#pragma comment(lib, "WS2_32.lib")

sendByTCP::sendByTCP(void)
{
}


sendByTCP::~sendByTCP(void)
{
	if(sock){
		closesocket(sock);
	}
}


int sendByTCP::sendData(char *data, int len, int type){
	struct protocol p;
	p.type = type;
	p.data_len = len;

	if (send(sock, (char*)&p, sizeof(p), 0) == SOCKET_ERROR){
		TRACE("send protocol data failed!\n");
		return 0;
	}
	
	if (send(sock, data, len, 0) == SOCKET_ERROR){
		TRACE("send data failed!\n");
		return 0;
	}
	return 1;
}

BOOL sendByTCP::initSocket(char *dst_ip, int port){
	WSADATA wsaData;
	SOCKADDR_IN server_addr;
	WORD wVersion;
	wVersion = MAKEWORD(2, 2);
	WSAStartup(wVersion, &wsaData);
	server_addr.sin_addr.s_addr = inet_addr(dst_ip);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
	{
		return FALSE;
	}
	if (connect(sock, (struct sockaddr *) &server_addr, sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
	{
		return FALSE;
	}
	return TRUE;
}

BOOL sendByTCP::recvData(char *data, int len){
	int res;
	int s,e;
	struct protocol p;
	res = recv(sock, (char*)&p,sizeof(p), 0);
	if(res == -1 || p.data_len != len){
		TRACE("fault during receive data OR accept data length = %d not equal real data length = %d.\n",p.data_len,len);
		return FALSE;
	}
	s= 0;
	e = len;
	while(e>0){
		res = recv(sock, data+s,e, 0);
		if(res == -1){
			TRACE("fault during receive data.\n");
			return FALSE;
		}
		s+=res;
		e-=res;
	}
	return TRUE;
}
