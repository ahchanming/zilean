

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
	return tmp > 0 ? -1 : 0;
}

int readNumberOnChar(char* str, int dignum){
	int ret = 0;
	for (int i = 0; i < dignum; ++i){
		if (str[i] < '0' || str[i] > '9'){
			return -1;
		}
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
	if ((length = readNumberOnChar(message, BODY_LENGTH)) < 0){
		printf("ZileanUtil::readNumberOnChar ReadLength Error\n");
		return -1;
	}
	if ((type = readNumberOnChar(message + BODY_LENGTH, TYPE_LENGTH)) < 0){
		printf("ZileanUtil::readNumberOnChar readType Error\n");
		return -1;
	}
	byte = (char*)malloc(sizeof(char) * length);
	memcpy(byte, message + HEADER_LENGTH, length);
	return 0;
}
