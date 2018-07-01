#include "wwsessionmanager.h"

using namespace std;
int main()
{
	SessionManager *sm = new SessionManager();
	string token;
	sm->GetSession(token);
	cout << token << endl;
}
