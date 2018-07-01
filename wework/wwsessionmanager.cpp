
#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON
#include "httpclient.h"
#include "wwsessionmanager.h"

using namespace std;
using namespace rapidjson;


int SessionManager::GetSession(string &session)
{
	char* url = "https://qyapi.weixin.qq.com/cgi-bin/gettoken?corpid=ww285b41c580a23153&corpsecret=i1-4i10hmmYUMGUXGC3_OrdsKruhf5llFm6piCFg2RA";            
	char* resstr;
	getUrl(url, resstr);

	Document document;
	//printf("%s\n", resstr);
	if (document.Parse(resstr).HasParseError())
	{
		printf("parse session error\n");
		return -1;
	}
	if (document.HasMember("access_token"))
	{
		session = string(document["access_token"].GetString());
		return 0;
	}else
	{
		return -1;
	}
}

int SessionManager::SendMsg(int agentId, std::string content, std::string session)
{
	return 0;
}

