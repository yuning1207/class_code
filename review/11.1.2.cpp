#include <iostream>
#include <list>
#include <cstring>
using namespace std;

int main(void)
{
	list<string>name;
	list<string>::iterator p;
	int i,n;
	string s;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>s;
		name.push_back(s);
	}
	name.sort();
	p=name.begin();
	while(p!=name.end())
	{
		cout<<*p<<endl;
		p++;
	}
	return 0;
}