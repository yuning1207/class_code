#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	string s,s1,s2,temp;
	int tag,t,a1;
	getline(cin,s);
	t=s.find_last_of('/');
	a1=s.find_last_of('\\');
	if(a1>t)
	{
		t=a1;
	}
	s[t]='\n';
	s+='\n';
	cout<<s;
	return 0;
}