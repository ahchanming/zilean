#ifndef _DISPATCH_SERVICE_H
#define _DISPATCH_SERVICE_H

#include "google/protobuf/message.h"


/*
   dispatch and filter
   */
class DispatchService{
private:
	::google::protobuf::Message* innerDispatch(int length, int type, char* byte);
	DispatchService();
public:
	::google::protobuf::Message* Dispatch(int length, char* byte);
	static DispatchService& Instance();
};

#endif 
