#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "httpclient.h"
#include "wwsessionmanager.h"
#include <vector>

using namespace std;
using namespace rapidjson;


class ContestItem
{
	public:

	uint64_t timeSecond;
	string timeStr;
	string contestName;
};

int getPostData(vector<ContestItem> &list)
{
	char* url = "http://contests.acmicpc.info/contests.json";
	string errmsg;
	string result;
	int ret = doGet(url, result, errmsg);
	if (ret != 0)
	{
		printf("Get Contest Data error, ret = %d\n", ret);
		printf("Error msg %s\n", errmsg.c_str());
		return ret;
	}

	Document document;
	if (document.Parse(result.c_str()).HasParseError())
	{
		printf("Parse Contest Data error\n");
		return -1;
	}
	
	cout << document.IsObject() << endl;
	cout << document.IsArray() << endl;
	for (Value::ConstValueIterator itr = document.Begin(); itr != document.End(); ++itr)
	{
		printf("%s\n", (*itr)["id"].GetString());
		ContestItem item;
		item.timeStr = string((*itr)["start_time"].GetString());
		item.contestName = string((*itr)["name"].GetString());
		list.push_back(item);
	}
	return 0;
}

int getLastestContest()
{
	//获取最近一场比赛
	
}
void doExecute()
{
	
}

int main()
{
	printf("HelloWorld\n");
	vector<ContestItem> contestList;
	getPostData(contestList);
	string str = "最近一场比赛" + contestList[0].contestName + ",时间为" + contestList[0].timeStr;
	SessionManager *sm;
	sm->SendMsg(1000002, str);
	return 0 ;

}
