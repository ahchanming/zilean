
#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON
#include "httpclient.h"
#include "wwsessionmanager.h"

using namespace std;
using namespace rapidjson;


int SessionManager::GetSession(string &session)
{
	char* url = "https://qyapi.weixin.qq.com/cgi-bin/gettoken?corpid=ww285b41c580a23153&corpsecret=i1-4i10hmmYUMGUXGC3_OrdsKruhf5llFm6piCFg2RA";            
	string result;
	string errmsg;
	doGet(url, result, errmsg);

	Document document;
	//printf("%s\n", resstr);
	if (document.Parse(result.c_str()).HasParseError())
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

int SessionManager::SendMsg(int agentId, std::string content)
{
	string url = "https://qyapi.weixin.qq.com/cgi-bin/message/send?access_token=";
	string token;
	int ret = GetSession(token);
	if (ret != 0)
	{
		printf("Get Session Error ret is %d\n", ret);
	}
	string postUrl = url + token;
	char postData[4096];
	sprintf(postData, "{\"touser\" : \"@all\",\"msgtype\" : \"text\",\"agentid\" : %d,\"text\" : {\"content\" : \"%s\"},\"safe\":0}", agentId, content.c_str());
	printf("postData[%s]", postData);
	string result;
	string error;
	ret = doPost(postUrl.c_str(), postData, result, error);
	return 0;
}

