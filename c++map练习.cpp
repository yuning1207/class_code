#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{
	string s;
	double t;
	map<string,double> mm;
	while(1)
	{
		cin>>s;
		if(s=="noname")
		{
			break;
		}
		cin>>t;
		mm[s]=t;
	}
	cin>>s;
	if((int)mm[s])
	{
		cout<<mm[s]*0.21<<endl; 
	}
	else
	{
		cout<<"Not found."<<endl;
	}
	return 0;
}