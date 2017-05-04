#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

int main(void)
{
	list<int> l;
	int i=0;
	for(i;i<10;i++)
	{
		l.push_back(i);
	}
	list<int>::iterator p=l.begin();
	while(p!=l.end())
	{
		cout<<*p<<endl;
		p++;
	}
	return 0;
} 