#ifndef __MEMBERDAO__
#define __MEMBERDAO__

#include "member.h"
#include <stdio.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>

const char* host = "localhost";
const char* username = "root";
const char* password = "Showtime100!@#321";
const char* dbname = "flower";


int insertMember(member newmember){
	MYSQL conn;
	int res;
	mysql_init(&conn);
	if (mysql_real_connect(&conn, "localhost", "root", "Showtime100!@#321", "flower", 0, NULL, CLIENT_FOUND_ROWS)){
		char sql[1024];
		char* origin = "insert into member(type, nick_name, origin_id) values('%d', '%s','%s');";
		sprintf(sql, origin, newmember.type, newmember.nick_name, newmember.origin_id);
		printf("final sql is [%s]", sql);
		int res = mysql_query(&conn, sql);
		if (res){
			printf("error\n");
			return -1;
		}else{
			printf("insert success\n");
			return 0;
		}
	}else{
		printf("connect error\n");
		return -1;
	}
}

long atol(char* str){
	long result = 0l;
	int len = strlen(str);
	for (int i = 0; i < len; ++i){
		result = result * 10 + str[i] - '0';
	}
	return result;
}

int atoi(char* str){
	int result = 0;
	int len = strlen(str);
	for (int i = 0; i < len; ++i){
		result = result * 10 + str[i] - '0';
	}
	return result;
}

member* getMemberById(long memberId){
	MYSQL conn;
	mysql_init(&conn);

	if (mysql_real_connect(&conn, host, username, password, dbname, 0, NULL, CLIENT_FOUND_ROWS)){
		printf("connect Success\n");
	}else{
		printf("error\n");
	}
	char* originsql = "select id, type, nick_name, origin_id from member where id = %lld";
	char sql[1024];
	sprintf(sql, originsql, memberId);
	printf("final sql is [%s]", sql);
	
	int res = mysql_query(&conn, sql);
	if (res){
		printf("query error\n");
		return NULL;
	}else{
		MYSQL_RES *res_ptr = mysql_store_result(&conn);
		if (res_ptr){
			int column = mysql_num_fields(res_ptr);
			int row = mysql_num_rows(res_ptr);
			printf("query from db , rows %d\n", row);

			MYSQL_FIELD *field;
			MYSQL_ROW result_row;

			if (row ==0){
				printf(" result is empty");
				return NULL;
			}else{
				result_row = mysql_fetch_row(res_ptr);
				printf("%s\n",  result_row[0]);
				member* member_ptr = new member;
				member_ptr->id = atol(result_row[0]);
				member_ptr->type = atoi(result_row[1]);
				member_ptr->nick_name = (char*)malloc(strlen(result_row[2]));
				strncpy(member_ptr->nick_name, result_row[2], strlen(result_row[2]));
				member_ptr->origin_id = result_row[3];
				//member_ptr->id = result_row[0];
				//member_ptr->type = result_row[1];
				mysql_free_result(res_ptr);
				return member_ptr;
			}
		}
	}
	return NULL;
}

#endif
