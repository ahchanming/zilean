
main: bin/main.o
	g++ bin/main.o bin/membermanager.o -o main

bin/main.o: main.cpp bin/membermanager.o
	g++ -c main.cpp bin/membermanager.o -o bin/main.o

bin/membermanager.o: membermanager.h member.h
	g++ -c membermanager.cpp  -o  bin/membermanager.o


bin/wwsessionmanager.o: wwsessionmanager.h httpclient.h wwsessionmanager.cpp
	g++ -c  wwsessionmanager.cpp -o bin/wwsessionmanager.o -lculr -I/home/opq/workspace/rapidjson/include
	

#test
testmemberdao: memberdao.h member.h
	g++ -std=c++11 -g testmemberdao.cpp `mysql_config --cflags --libs` -o testmemberdao

testsessionmanager: test/testsessionmanager.cpp bin/wwsessionmanager.o
	g++ -std=c++11 bin/wwsessionmanager.o test/testsessionmanager.cpp -o test/testsessionmanager -I/home/opq/workspace/zilean/wework -lcurl 

	

