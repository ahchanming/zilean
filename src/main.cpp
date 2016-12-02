#include "cstdio"
#include "lib/my_sockaddr.h"
#include "lib/my_socket.h"
#include "lib/my_server_socket.h"
#include "service/census_service.h"
#include "pb/touch_message.pb.h"
#include "pb/resp_touch_message.pb.h"
#include "util/zilean_util.h"
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>



void recieveMessage(char* message){
	int length;
	int byte;
	char* buff;
	ZileanUtil::ParseFromMessage(message, length, byte, buff);
	TouchMessage tm;
	tm.ParseFromArray(buff, length);
	puts("Recieve From Client");
	std::cout << tm.uid() << std::endl;
	std::cout << tm.dataversion() << std::endl;
	std::cout << tm.timestamp() << std::endl;
	std::cout << tm.appversion() << std::endl;
}

void outputRTM(char* bu, int length){
	RespTouchMessage rtm2;
	rtm2.ParseFromArray(bu, length);
	std::cout << "code is" << rtm2.code() << std::endl;
	std::cout << "msg is " << rtm2.msg() << std::endl;
}

void sendMessage(MySocket *ms){
	RespTouchMessage rtm;
	rtm.set_code(0);
	rtm.set_msg("success");
	int length = rtm.ByteSize();
	char* byte = (char*)malloc(sizeof(char) * length);
	rtm.SerializeToArray(byte, length);
	char* message = ZileanUtil::Format2Message(length, 1, byte);
	puts("Ready Send To Client");
	ms->Send(message, length + 16);
}

void work(){
	MyServerSocket mss(9292);
	mss.Init();
	char buff[4096];
	while (true){
		MySocket *ms = mss.Accept();
		puts("A socket Accept");
		memset(buff, 0, sizeof(buff));
		int recvRet;
		recvRet = ms->Recv(buff, 4096);
		printf("recieve from client, error is %d\n", errno);
		recieveMessage(buff);
		sendMessage(ms);
		ms->Close();
	}
}


int main(){
	puts("Zilean backend start up!");
	int pid;
	pid = fork();
	if (pid < 0){
		printf("Fork Error, Error Number is %d\n", errno);
	}else if (pid == 0){
	}else{
		puts("Sub Process Start!");
		work();
	}
}

