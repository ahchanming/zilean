#ifndef _MY_SOCKET_H
#define _MY_SOCKET_H

#include "my_sockaddr.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/socket.h"
#include <cstring>
#include <iostream>

class MySocket{
private:
	int m_fd;
	MySockAddr*  m_addr;
public:
	MySocket();
	MySocket(const char *host, int port);
	MySocket(int fd, MySockAddr *ptAddr);
	MySocket(MySockAddr* ptAddr);
	int Init();
	int Connect();
	int Send(const void* buff, int length);
	int Recv(void* buff, int length);
	void Close();
	struct sockaddr* GetScokAddr();
	std::string ToString();
};
#endif
