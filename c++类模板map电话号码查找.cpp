#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	string name1,phonenum;
	map<string,string> map1;
	map<string,string>::iterator p;
	cin>>name1;
	while(name1!="noname")
	{
		cin>>phonenum;
		map1.insert(map<string,string>::value_type(name1,phonenum));
		cin>>name1;
	}
	cin>>name1;
	p=map1.find(name1);
	if(p!=map1.end())
 		cout<<p->second<<endl;
	else 
		cout<<"Not found."<<endl;
}