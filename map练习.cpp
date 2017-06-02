#include <map>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	map<string,string>map1;
	map<string,string>::iterator p;
	string name1,phonenumber;
	cin>>name1;
	while(name1!="noname")
	{
		cin>>phonenumber;
		map1.insert(map<string,string>::value_type(name1,phonenumber));
		cin>>name1;
	}
	cin>>name1;
	p=map1.find(name1);
	if(p!=map1.end())
	{
		cout<<p->second<<endl;
	}
	else
	{
		cout<<"NOT FOUND!"<<endl;
	}
	return 0;
}