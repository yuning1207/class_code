#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	string a,b,c,m;
	int found,i;
	getline(cin,a);//读取一行 
	while(1)
	{
		getline(cin,m);
		if(!m.compare("end"))//m与"end"比较，相等返回0，>返回1，<返回-1 
		{
			break;
		}
		a.append(m);//把字符串m连接到当前字符串结尾 
	}
	cin>>b;
	cin>>c;
	found=a.find(b);//在a中查找b，返回首地址 
	while(found!=-1)
	{
		a.replace(found,b.length(),c);//从第一个参数位置开始删除第二个参数个，将第三个参数的字符串从第一个参数的 
		found=a.find(b);
	}
	cout<<a<<endl;
	return 0;
} 