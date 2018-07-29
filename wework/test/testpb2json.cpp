#include <iostream>
#include <cstdio>
#include <google/protobuf/util/json_util.h>
#include "weworkapi.pb.h"

using namespace std;


int main()
{
	printf("Hello World\n");
	weworkapi::TokenReq tokenReq;
	tokenReq.set_corpid("sdadga");
	printf("hello\n");
	string jsonout;
	google::protobuf::util::MessageToJsonString(tokenReq, &jsonout);
	cout << jsonout << endl;
	weworkapi::TokenReq req;
	google::protobuf::util::JsonStringToMessage(jsonout, &req);
	cout << req.corpid() << endl;
	return 0;
}
