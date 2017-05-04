#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	int i,len;
    string s1,s2;
	while(cin>>s1>>s2)
	{
		len=s1.length()>s2.length()?s2.length():s1.length();
		for(i=0;i<len;i++)
		{
			if(s1[i]!=s2[i])
				break;
		}
		if(i>0){
			s1=s1.substr(0,i);
			cout<<"The common prefix is "<<s1<<endl;
		}
		else
			cout<<"No common prefix"<<endl;
	}
} 