#makefile

INCLUDE=-I/home/opq/working/c/zilean/src
PB_INCLUDE=-I/usr/local/protobuf/include -L/usr/local/protobuf/lib -lprotobuf -pthread -I/home/opq/working/c/zilean/src

LIB=bin/my_sockaddr.o \
	bin/my_socket.o \
	bin/my_server_socket.o

PB=bin/touch_message.o \
   bin/resp_touch_message.o 

SERVICE=bin/census_service.o\
		bin/dispatch_service.o\
		bin/touch_service.o

UTIL=bin/zilean_util.o


#main: bin/resp_touch_message.o bin/zilean_util.o bin/touch_message.o bin/main.o bin/my_sockaddr.o bin/my_socket.o bin/my_server_socket.o bin/census_service.o

main: ${UTIL} ${PB} ${LIB} ${SERVICE} bin/main.o
	g++ ${UTIL} ${PB} ${LIB} ${SERVICE} bin/main.o -o main ${PB_INCLUDE} -pthread

bin/main.o: main.cpp
	g++ -c main.cpp -o bin/main.o ${PB_INCLUDE} -pthread

###lib
bin/my_sockaddr.o: lib/my_sockaddr.h lib/my_sockaddr.cpp
	g++ -c lib/my_sockaddr.cpp -o bin/my_sockaddr.o ${INCLUDE}
bin/my_socket.o: lib/my_socket.h lib/my_socket.cpp lib/my_sockaddr.o
	g++ -c lib/my_socket.cpp bin/my_sockaddr.o -o bin/my_socket.o ${INCLUDE}
bin/my_server_socket.o: lib/my_server_socket.h lib/my_server_socket.cpp bin/my_socket.o bin/my_sockaddr.o
	g++ -c lib/my_server_socket.cpp bin/my_socket.o bin/my_sockaddr.o -o bin/my_server_socket.o ${INCLUDE}

	
###service	
bin/census_service.o: service/census_service.h service/census_service.cpp
	g++ -c service/census_service.cpp -o bin/census_service.o ${INCLUDE} -pthread
bin/dispatch_service.o: service/dispatch_service.h service/dispatch_service.cpp
	g++ -c service/dispatch_service.cpp -o bin/dispatch_service.o ${INCLUDE} 
bin/touch_service.o: service/touch_service.h service/touch_service.cpp bin/census_service.o
	g++ -c service/touch_service.cpp bin/census_service.o -o bin/touch_service.o ${PB_INCLUDE} -pthread


###pb
bin/touch_message.o: pb/touch_message.pb.h pb/touch_message.pb.cc
	g++ -c pb/touch_message.pb.cc -o bin/touch_message.o ${PB_INCLUDE}
bin/resp_touch_message.o: pb/resp_touch_message.pb.h pb/resp_touch_message.pb.cc
	g++ -c pb/resp_touch_message.pb.cc -o bin/resp_touch_message.o ${PB_INCLUDE}
all: testCensusService

###util
bin/zilean_util.o: util/zilean_util.h util/zilean_util.cpp
	g++ -c util/zilean_util.cpp -o bin/zilean_util.o

testCensusService: census_service.o test_census_service.o
	g++ census_service.o test_census_service.o -o testCS -pthread

census_service.o: ../service/census_service.cpp ../service/census_service.h
	g++ -c ../service/census_service.cpp -o census_service.o

test_census_service.o: test_census_service.cpp
	g++ -c test_census_service.cpp -o test_census_service.o 

clean:
	@echo \
		"clean make"
	-rm bin/*.o
	@echo "clean done"


