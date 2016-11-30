#ifndef _CENSUS_SERVER_H
#define _CENSUS_SERVER_H

#include <map>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <pthread.h>

class CensusService{
private:
	CensusService();
	CensusService(const CensusService&);
	CensusService& operator=(const CensusService& tmp);
	int m_uv;
	int m_pv;
	std::map<std::string, int> m_censusMap;
	pthread_t m_tid;
public:
	static CensusService& Instance();
	std::string ToString();
	void IncPV();
	void IncUV();
	int GetPV();
	int GetUV();
	void ClearAll();
};
#endif
