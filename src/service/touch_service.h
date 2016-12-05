#ifndef _TOUCH_SERVICE_H
#define _TOUCH_SERVICE_H
#include "pb/touch_message.pb.h"
#include "google/protobuf/message.h"
#include "pb/resp_touch_message.pb.h"

class TouchService{
private:
	TouchService();
	TouchService(TouchService&);
	TouchService& operator=(const TouchService& tmp);
public:
	::google::protobuf::Message* Touch(TouchMessage* tm);
	static TouchService& Instance();
};
#endif
