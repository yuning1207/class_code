#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	string s1,s2;
	int len,i;
	while(cin>>s1>>s2)
	{
		len=s1.length()>s2.length()?s2.length():s1.length();
		for(i=0;i<len;i++)
		{
			if(s1[i]!=s2[i])
			{
				break;
			}
		}
		if(i>0)
		{
			s1=s1.substr(0,i);//返回从0开始i个字符组成的字符串 
			cout<<"The common prefix is "<<s1<<endl; 
		}
		else
		{
			cout<<"No common prefix"<<endl;
		}
	}
	return 0;
}