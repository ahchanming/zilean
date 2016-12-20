#include "dispatch_service.h"
#include <stdlib.h>
#include <stdio.h>
#include "util/zilean_util.h"
#include "pb/touch_message.pb.h"
#include "service/touch_service.h"


::google::protobuf::Message* DispatchService::Dispatch(int length, char* byte){
	int ret, pbLength, pbType;
	char* pbMessage;
	if ((ret = ZileanUtil::ParseFromMessage(byte, pbLength, pbType, pbMessage)) < 0){
		printf("DispatchService::Dispatch ParseFromMessage Error\n");
		return NULL;
	}
	::google::protobuf::Message* result;
	result = innerDispatch(pbLength, pbType, pbMessage);
	free(pbMessage);
	return result;
}


int parseFromArray(::google::protobuf::Message *message, int length, char* byte){
	int ret;
	if (!message->ParseFromArray(byte, length)){
		return -1;
	}
}

::google::protobuf::Message* DispatchService::innerDispatch(int length, int type, char* byte){
	switch (type){
		case 1000:
			printf("TouchMessage\n");
			TouchMessage* tm = new TouchMessage();
			tm->ParseFromArray(byte, length);
			TouchService& ts = TouchService::Instance();
			return ts.Touch(tm);
			break;
		defalut:
			return NULL;
	}
}


DispatchService::DispatchService(){

}

DispatchService& DispatchService::Instance(){
	static DispatchService m_dispatchService;
	return m_dispatchService;
}

