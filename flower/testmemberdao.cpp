#include "memberdao.h"

int main(){
	member newmember{11, 0, "nn0", "on0"};
    //insertMember(newmember );
	member* queryMember = getMemberById(1l);
	printf("%d\n", queryMember->type);
	printf("nick name is %s \n", queryMember->nick_name);
	return 0;   
}
