#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main(void)
{
	map<string,int>map1;
	map<string,int>::iterator p;
	string name;
	int score;
	while(1)
	{
		cin>>name;
		if(!name.compare("noname"))
			break;
		cin>>score;
		map1.insert(pair<string,int>(name,score));
	}
	cin>>name;
	p=map1.find(name);
	if(p!=map1.end())
	{
		cout<<p->second*0.21<<endl;
	}
	else
	{
		cout<<"Not found."<<endl;
	}
	return 0;
}