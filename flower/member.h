#ifndef __MEMBER__
#define __MEMBER__
enum member_type {Owner, Normal};

struct member{
	//userId
	long id;
	// user type see enum membertype
	int type;
	// user nick name
	char* nick_name;
	//origin
	char* origin_id;
};
#endif
