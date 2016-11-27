#makefile

INCLUDE=-I/home/opq/working/c/zilean/src

all: testCensusService

censusServer:
	g++ -c ../service/census_service.cpp -o census_service.o

testCensusService: census_service.o test_census_service.o
	g++ census_service.o test_census_service.o -o testCS
test_census_service.o:
	g++ -c test_census_service.cpp -o test_census_service.o

clean:
	@echo "clean make"
	-rm *.o
	@echo "clean done"

