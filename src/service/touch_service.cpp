
#include "touch_service.h"
#include "census_service.h"
#include <cstdio>

::google::protobuf::Message* TouchService::Touch(TouchMessage* tm){
	printf("Ready To touch\n");
	CensusService &cs = CensusService::Instance();
	if (tm == NULL){
		puts("error");
		return NULL;
	}
	cs.IncUV(tm->uid());
	puts("inc uv done");
	RespTouchMessage* rtm = new RespTouchMessage();
	rtm->set_code(1024);
	rtm->set_msg("helloWorld");
	rtm->set_uv(cs.GetUV());
	return (::google::protobuf::Message*)rtm;
}

TouchService::TouchService(){

}

TouchService& TouchService::Instance(){
	static TouchService m_ts;
	return m_ts;
}


/*
int main(){
	TouchService& ts = TouchService::Instance();
	ts.Touch(NULL);
}
*/
