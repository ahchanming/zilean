#include "cstdio"
#include "lib/my_sockaddr.h"
#include "lib/my_socket.h"
#include "lib/my_server_socket.h"
#include "service/census_service.h"
#include "pb/touch_message.pb.h"
#include "pb/resp_touch_message.pb.h"
#include "service/touch_service.h"
#include "util/zilean_util.h"
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include "google/protobuf/message.h"
#include "service/dispatch_service.h"

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

void sendMessage(MySocket *ms, ::google::protobuf::Message* message){
	int length = message->ByteSize();
	char* byte = (char*)malloc(sizeof(char) * length);
	message->SerializeToArray(byte, length);
	char* writeMessage = ZileanUtil::Format2Message(length, 2000, byte);
	puts("Main::SendMessage");
	ms->Send(writeMessage, length + 16);
}

void *execute(void *args);

void work(){
	MyServerSocket mss(9292);
	mss.Init();
	char buff[4096];
	while (true){
		MySocket *ms = mss.Accept();
		pthread_t tid;
		int ret;
		if ((ret = pthread_create(&tid, NULL, execute, (void*)ms)) < 0){
			puts("pthread_create Error");
		}
	}
}

void *execute(void *args){
	puts("thread create");
	char buff[4096];
	MySocket* ms = (MySocket*)args;
	while (true){
		memset(buff, 0, sizeof(buff));
		int recvRet;
		if ((recvRet = ms->Recv(buff, 4096)) < 0){
			printf("recieve from client, error code is %d\n", errno);
			break;
		}
		DispatchService ds = DispatchService::Instance();
		::google::protobuf::Message* message = ds.Dispatch(recvRet, buff);
		sendMessage(ms, message);
	}
	delete ms;
}


void test(){
	std::cout << "main Test" << std::endl;
	TouchService& touchService = TouchService::Instance();
	std::cout << "get touchService" << std::endl;
	TouchMessage tm;
	tm.set_uid("opq.chen");
	::google::protobuf::Message* message = touchService.Touch(&tm);
	std::cout << message->ByteSize() << std::endl;
	char* byte = (char*)malloc(sizeof(char) * (message->ByteSize()));
	memset(byte, 0, sizeof(byte));
	message->SerializeToArray(byte, message->ByteSize());
	RespTouchMessage rtm;
	rtm.ParseFromArray(byte, message->ByteSize());
	std::cout << "code :" << rtm.code() << std::endl;
	std::cout << "msg :" << rtm.msg() << std::endl;
	std::cout << "uv :" << rtm.uv() << std::endl;
}

int main(){
	puts("Zilean backend start up!");
	int pid;
	pid = fork();
	if (pid < 0){
		printf("Fork Error, Error Number is %d\n", errno);
	}else if (pid == 0){
		//test();
	}else{
		puts("Sub Process Start!");
		work();
	}
}

