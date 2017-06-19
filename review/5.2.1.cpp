#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	string s;
	int a,b;
	getline(cin,s);
	a=s.find_last_of("/\\");//会返回查找多个字符串中的最后的位置 
	s[a]='\n';
	s+='\n';
	cout<<s;
	return 0;
}