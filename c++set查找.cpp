#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(void)
{
	int i=0;
	string str;
	set<string> a;
	set<string>::iterator p;
	for(i=0;i<2;i++)
	{
		getline(cin,str);
		while(str!="end")
		{
			a.insert(str);
			getline(cin,str);
		}
	}
	p=a.begin();
	while(p!=a.end())
	{
		cout<<*p++<<endl;
	}
}