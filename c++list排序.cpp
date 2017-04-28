#include <iostream>
#include <list>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(void)
{
	int i=0,n=0;
	string x;
	list<string> lst;
	list<string>::iterator p;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		lst.push_back(x);
	}
	lst.sort();
	p=lst.begin();
	while(p!=lst.end())
	{
		cout<<*p<<endl;
		p++;
	}
}