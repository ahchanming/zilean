#include "../pb/touch_message.pb.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	TouchMessage tm;
	tm.set_uid("opq");
	tm.set_dataversion("0.0.1");
	tm.set_timestamp("21034242342");
	tm.set_appversion("android_0.0.1");
	int lenth = tm.ByteSize();
	char* buf = new char[lenth];
	tm.SerializeToArray(buf, lenth);
	puts(buf);
	TouchMessage tm2;
	tm2.ParseFromArray(buf, lenth);
	cout << tm2.uid() << endl;
	cout << tm2.dataversion() << endl;
	cout << tm2.timestamp() << endl;
	cout << tm2.appversion() << endl;
	delete buf;
	printf("the bit size is %d\n", lenth);
}
