#ifndef _ZILEAN_UTIL_H
#define _ZILEAN_UTIL_H

class ZileanUtil{
private:
	const static int BODY_LENGTH = 8;
	const static int TYPE_LENGTH = 4;
	const static int HEADER_LENGTH = 16;
public:
	static char* Format2Message(int length, int type, char* byte);
	static int ParseFromMessage(char* message, int &length, int &tyte, char* &byte);
};

#endif
