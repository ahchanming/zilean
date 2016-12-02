

#include "zilean_util.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int writeNumberOnChar(int number, char* str, int dignum){
	int tmp = number;
	int tmq = dignum;
	while(--tmq >= 0){
		*(str + tmq) = (char)('0' + tmp % 10);
		tmp /= 10;
	}
	puts("this is write number");
	for (int i = 0; i < dignum; ++i){
		putchar(*(str + i));
	}
	puts("");
	return tmp > 0 ? -1 : 0;
}

int readNumberOnChar(char* str, int dignum){
	int ret = 0;
	for (int i = 0; i < dignum; ++i){
		ret = ret * 10 + str[i] - '0';
	}
	return ret;
}

char* ZileanUtil::Format2Message(int length, int type, char* byte){
	const int finalLength = length + HEADER_LENGTH;
	char* ret = (char*) malloc(sizeof(char) * finalLength);
	memset(ret, 0, sizeof(finalLength));
	ret[12] =ret[13] = ret[14] = ret[15] = '0';
	writeNumberOnChar(length, ret, BODY_LENGTH);
	writeNumberOnChar(type, ret + BODY_LENGTH, TYPE_LENGTH);
	memcpy(ret + HEADER_LENGTH, byte, sizeof(char) * length);
	//strncpy(ret + HEADER_LENGTH, byte, length);
	return ret;
}

int ZileanUtil::ParseFromMessage(char* message, int &length, int &type, char* &byte){
	length = readNumberOnChar(message, BODY_LENGTH);
	type = readNumberOnChar(message + BODY_LENGTH, TYPE_LENGTH);
	byte = (char*)malloc(sizeof(char) * length);
	strncpy(byte, message + HEADER_LENGTH, length);
	puts("zileanUtil");
	puts(byte);
	return 0;
}
