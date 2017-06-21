#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main(void)
{
	map<string,string>map1;
	map<string,string>::iterator p;
	int i=0;
	string name,number;
	while(i++<2)
	{
		while(1)
		{
			cin>>name;
			if(name=="end")
				break;
			cin>>number;
			map1.insert(pair<string,string>(name,number));
		}
	}
	p=map1.begin();
	while(p!=map1.end())
	{
		cout<<p->first<<p->second<<endl;
		p++;
	}
}