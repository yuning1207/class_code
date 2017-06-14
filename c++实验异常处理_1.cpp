#include <iostream>
using namespace std;

int main(void)
{
	int m,n;
	cout<<"Please input two intergers:";
	cin>>m>>n;
	try
	{
		if(n==0)
			throw 0;
		cout<<(m/n)<<endl;
	}
	catch(int)
	{
		cout<<"Divided by 0!"<<endl;
		return -1;
	}
	return 0;
} 