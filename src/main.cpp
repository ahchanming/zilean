#include "cstdio"
//#include "lib/myserversocket.h"
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


void TestSocket(){
	MySockAddr sockaddr;
	sockaddr.Output();
	MySocket mysocket(&sockaddr);
	std::cout << mysocket.ToString() << std::endl;	
	MyServerSocket myserversocket(8099);
	myserversocket.Init();
	//MyServerSocket serversocekt;
	printf("Hello World");
}


void *dowork(void *arg){
	printf("this is a new thread\n");
	CensusService &cs = CensusService::Instance();
	cs.IncPV();
	printf("pv is %d\n", cs.GetPV());
}

void recieveMessage(char* message){
	int length;
	int byte;
	char* buff;
	ZileanUtil::ParseFromMessage(message, length, byte, buff);
	printf("length is %d\n", length);
	puts(buff);
	TouchMessage tm;
	tm.ParseFromArray(buff, length);
	puts("this is parse from");
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
	puts("The Resp byte is");
	for (int i = 0; i < length; ++i){
		putchar(byte[i]);
	}
	puts("");
	outputRTM(byte, length);
	char* message = ZileanUtil::Format2Message(length, 1, byte);
	puts("Send To Client");
	for (int i = 0; i < length + 16; ++i){
		putchar(message[i]);
	}
	puts("");
	printf("Send To Client, Length is %d\n", length + 16);
	ms->Send(message, length + 16);
	int ll;
	int tt;
	char* bu;
	ZileanUtil::ParseFromMessage(message, ll, tt, bu);
	outputRTM(bu, ll);
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
		printf("recieve from client, length is [%d], data is [%s]", recvRet, buff);
		recieveMessage(buff);
		sendMessage(ms);
		ms->Close();
		//ms->Send("Hello World", 12);
		//pthread_t tid;
		//pthread_create(&tid, NULL, dowork, NULL);
		//ms->Close();
	}
}

void testPBPar(char* message){
	int length;
	int byte;
	char* buff;
	ZileanUtil::ParseFromMessage(message, length, byte, buff);
	printf("length is %d\n", length);
	puts(buff);
	TouchMessage tm;
	tm.ParseFromArray(buff, length);
	puts("this is parse from");
	std::cout << tm.uid() << std::endl;
}


void testPBMessage(){
	TouchMessage tm;
	tm.set_uid("opq");
	tm.set_dataversion("0001");
	tm.set_timestamp("2016-12-01");
	tm.set_appversion("android_0.0.1");
	int length = tm.ByteSize();
	char* buff = (char*)malloc(sizeof(char) * length);
	tm.SerializeToArray(buff, length);
	char* message = ZileanUtil::Format2Message(length, 1, buff);
	puts("This is the message:\n");
	for (int i = 0; i < length + 16; ++i){
		putchar(message[i]);
	}
	puts("");
	testPBPar(message);
}


int main(){
	puts("Zilean backend start up!");
	int pid;
	pid = fork();
	if (pid < 0){
		printf("Fork Error, Error Number is %d\n", errno);
	}else if (pid == 0){
		testPBMessage();
		printf("Parent process\n");
	}else{
		printf("Sub process\n");
		work();
	}
}

