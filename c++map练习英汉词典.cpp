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
	chinese="��װ��";
	map1.insert(map<string,string>::value_type(english,chinese));
	english="inheritance";
	chinese="�̳���";
	map1.insert(map<string,string>::value_type(english,chinese));
	english="polymorphism";
	chinese="��̬��";
	map1.insert(map<string,string>::value_type(english,chinese));
	english="message";
	chinese="��Ϣ";
	map1.insert(map<string,string>::value_type(english,chinese));
	english="class";
	chinese="��";
	map1.insert(map<string,string>::value_type(english,chinese));
	english="object";
	chinese="����";
	map1.insert(map<string,string>::value_type(english,chinese));
	english="constructor";
	chinese="���캯��";
	map1.insert(map<string,string>::value_type(english,chinese));
	cin>>english;
	p=map1.find(english);
	if(p!=map1.end())
 		cout<<p->first<<" : "<<p->second<<endl;
	else 
		cout<<"��Ǹ��û���ҵ�"<<english<<endl;
	return 0;
} 