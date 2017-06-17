#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main(void)
{
	string english,chinese;
	map<string,string> map1;
	map<string,string>::iterator p;
	english="encapsulation";
	chinese="封装性";
	map1.insert(map<string,string>::value_type(english,chinese));
	english="inheritance";
	chinese="继承性";
	map1.insert(map<string,string>::value_type(english,chinese));
	english="polymorphism";
	chinese="多态性";
	map1.insert(map<string,string>::value_type(english,chinese));
	english="message";
	chinese="消息";
	map1.insert(map<string,string>::value_type(english,chinese));
	english="class";
	chinese="类";
	map1.insert(map<string,string>::value_type(english,chinese));
	english="object";
	chinese="对象";
	map1.insert(map<string,string>::value_type(english,chinese));
	english="constructor";
	chinese="构造函数";
	map1.insert(map<string,string>::value_type(english,chinese));
	cin>>english;
	p=map1.find(english);
	if(p!=map1.end())
 		cout<<p->first<<" : "<<p->second<<endl;
	else 
		cout<<"抱歉！没有找到"<<english<<endl;
	return 0;
} 