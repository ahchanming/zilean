#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H
#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

int getUrl(char *url, char* &resstr)
{
	CURL *curl;
	CURLcode res;
	FILE *fp;
	char* filename = "test.txt";
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("open file error\n");
		return -1;
	}
	struct curl_slist *headers = NULL;
	headers = curl_slist_append(headers, "Accept: Agent-007");
	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp); //将返回的http头输出到fp指向的文件
		//curl_easy_setopt(curl, CURLOPT_HEADERDATA, fp); //将返回的html主体数据输出到fp指向的文件
		//curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
		//curl_easy_setopt(curl, CURLOPT_HEADERDATA, stdout);
		res = curl_easy_perform(curl); // 执行
		if (res != 0) {
			curl_slist_free_all(headers);
			curl_easy_cleanup(curl);
		}
	}else
	{
		printf("CURL init failed\n");
	}
	fclose(fp);
	if ((fp == fopen(filename, "r")) == NULL)
	{
		printf("open file error\n");
		return -1;
	}
	resstr = (char*)malloc(sizeof(char) * 4096);
	fgets(resstr, 4096, fp);
	//printf("resstr length %d\n", strlen(resstr));
	//puts(resstr);
	return 0;
}


#endif
