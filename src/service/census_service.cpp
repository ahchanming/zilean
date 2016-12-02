#include "census_service.h"
#include <cstdio>
#include <errno.h>
#include <iostream>


void *clearTask(void* arg){
	while (true){
		printf("This is a clear Task\n");
		sleep(1);
	}
}

CensusService::CensusService(){
	std::cout << ToString() << "!!!" << std::endl;	
	std::cout << m_uv << std::endl;
	std::cout << &m_tid << std::endl;
	int ret;
	if (ret = pthread_create(&m_tid, NULL, clearTask, NULL) < 0){
		std::cout << ret << " " << errno << std::endl;
	}
	std::cout << "ret is " << ret << std::endl;
}

CensusService& CensusService::Instance(){
	static CensusService m_cs;
	return m_cs;
}

CensusService& CensusService::operator=(const CensusService& tmp){
}

std::string CensusService::ToString(){
	return "This is a censusService";
}

void CensusService::IncPV(){
	m_pv++;
}

void CensusService::IncUV(std::string str){
	m_uv++;
}

int CensusService::GetPV(){
	return m_pv;
}

int CensusService::GetUV(){
	return m_uv;
}

void CensusService::ClearAll(){
	m_pv = m_uv = 0;
}

