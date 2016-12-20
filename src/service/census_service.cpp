#include "census_service.h"
#include <cstdio>
#include <errno.h>
#include <iostream>


void *clearTask(void* arg){
	std::cout << "begin clear task" << std::endl;
	while (true){
		printf("This is a clear Task\n");
		sleep(10);
	}
}

CensusService::CensusService(){
	std::cout << "Init Haha" << std::endl;
	int ret;
	if (ret = pthread_create(&m_tid, NULL, clearTask, NULL) < 0){
		std::cout << ret << " " << errno << std::endl;
	}
	std::cout << "Ret is " << ret << " " << errno << " tid is " << m_tid << std::endl;
	m_pv = m_uv = 0;
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
	std::cout << "The uid is " <<  str << std::endl;
	std::cout << "Map size is " << m_userMap.size() << std::endl;
	if (m_userMap[str] > 0){
		
	}else{
		m_userMap[str] = 1;
		m_uv++;
	}
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

