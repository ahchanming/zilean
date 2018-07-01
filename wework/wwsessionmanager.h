#ifndef __WWSESSION_MANAGER_
#define __WWSESSION_MANAGER_


#include <iostream>

class SessionManager{
	public:
		int GetSession(std::string &session);
		int SendMsg(int agentId, std::string content);
};


#endif


