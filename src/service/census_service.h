#ifndef _CENSUS_SERVER_H
#define _CENSUS_SERVER_H

#include <map>

class CensusService{
private:
	CensusService();
	~CensusService();
	CensusService(const CensusService&);
	CensusService& operator=(const CensusService& tmp);
	int m_uv;
	int m_pv;
	std::map<std::string, int> m_censusMap;
public:
	static CensusService& Instance();

};
#endif
