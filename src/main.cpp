#include "cstdio"
//#include "lib/myserversocket.h"
#include "lib/my_sockaddr.h"
#include "lib/my_socket.h"
#include "lib/my_server_socket.h"
#include "service/census_service.h"
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

void work(){
	MyServerSocket mss(9292);
	mss.Init();
	while (true){
		MySocket *ms = mss.Accept();
		ms->Send("Hello World", 12);
		pthread_t tid;
		pthread_create(&tid, NULL, dowork, NULL);
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
		printf("Parent process\n");
	}else{
		printf("Sub process\n");
		work();
	}
}

