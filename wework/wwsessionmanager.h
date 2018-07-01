
#include <iostream>

class SessionManager{
	public:
		int GetSession(std::string &session);
		int SendMsg(int agentId, std::string content, std::string session);
};


