#include "../service/census_service.h"
#include <iostream>
using namespace std;


int main(){
	CensusService &cs = CensusService::Instance();
	cout << cs.ToString() << endl;
	cout << "Hello World" << endl;
	sleep(30);
}
