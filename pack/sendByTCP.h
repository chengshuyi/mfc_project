#pragma once
class sendByTCP
{

private:
	SOCKET sock;
public:
	sendByTCP();
	virtual ~sendByTCP(void);
	int sendData(char *data, int len, int type);
	BOOL initSocket(char *dst_ip, int port);
	BOOL recvData(char *data, int len);
	//SOCKET get_sock();
};

