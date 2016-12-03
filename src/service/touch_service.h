#ifndef _TOUCH_SERVICE_H
#define _TOUCH_SERVICE_H
#include "pb/touch_message.pb.h"
#include "google/protobuf/message.h"
#include "pb/resp_touch_message.pb.h"

class TouchService{
private:
public:
	::google::protobuf::Message* Touch(TouchMessage* tm);
};
#endif
