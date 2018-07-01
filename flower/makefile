
main: bin/main.o
	g++ bin/main.o bin/membermanager.o -o main

bin/main.o: main.cpp bin/membermanager.o
	g++ -c main.cpp bin/membermanager.o -o bin/main.o

bin/membermanager.o: membermanager.h member.h
	g++ -c membermanager.cpp  -o  bin/membermanager.o




#test
testmemberdao: memberdao.h member.h
	g++ -std=c++11 -g testmemberdao.cpp `mysql_config --cflags --libs` -o testmemberdao
