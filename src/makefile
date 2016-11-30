#makefile

INCLUDE=-I/home/opq/working/c/zilean/src

main: bin/main.o bin/my_sockaddr.o bin/my_socket.o bin/my_server_socket.o bin/census_service.o
	g++ bin/main.o bin/my_sockaddr.o bin/my_socket.o bin/my_server_socket.o bin/census_service.o -o main ${INCLUDE} -pthread
bin/main.o: main.cpp
	g++ -c main.cpp -o bin/main.o
bin/my_sockaddr.o: lib/my_sockaddr.h lib/my_sockaddr.cpp
	g++ -c lib/my_sockaddr.cpp -o bin/my_sockaddr.o ${INCLUDE}
bin/my_socket.o: lib/my_socket.h lib/my_socket.cpp lib/my_sockaddr.o
	g++ -c lib/my_socket.cpp bin/my_sockaddr.o -o bin/my_socket.o ${INCLUDE}
bin/my_server_socket.o: lib/my_server_socket.h lib/my_server_socket.cpp bin/my_socket.o bin/my_sockaddr.o
	g++ -c lib/my_server_socket.cpp bin/my_socket.o bin/my_sockaddr.o -o bin/my_server_socket.o ${INCLUDE}
bin/census_service.o: service/census_service.h service/census_service.cpp
	g++ -c service/census_service.cpp -o bin/census_service.o ${INCLUDE}

all: testCensusService

testCensusService: census_service.o test_census_service.o
	g++ census_service.o test_census_service.o -o testCS -pthread

census_service.o: ../service/census_service.cpp ../service/census_service.h
	g++ -c ../service/census_service.cpp -o census_service.o

test_census_service.o: test_census_service.cpp
	g++ -c test_census_service.cpp -o test_census_service.o 

clean:
	@echo "clean make"
	-rm *.o
	@echo "clean done"

