#makefile

INCLUDE=-I/home/opq/working/c/zilean/src

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

