#include <iostream>
#include <set>
#include <cstring>
using namespace std;

int main(void)
{
	set<string>a;
	set<string>::iterator p;
	int i=0;
	string s;
	while(i++<2)
	{
		getline(cin,s);
		while(s.compare("end"))
		{
			a.insert(s);
			getline(cin,s);
		}
	}
	p=a.begin();
	while(p!=a.end())
	{
		cout<<*p<<endl;
		p++;
	}
	return 0;
}