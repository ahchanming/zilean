
#include "touch_service.h"


::google::protobuf::Message* TouchService::Touch(TouchMessage* tm){
	RespTouchMessage* rtm = new RespTouchMessage();
	rtm->set_code(1024);
	rtm->set_msg("helloWorld");
	return (::google::protobuf::Message*)rtm;
}
