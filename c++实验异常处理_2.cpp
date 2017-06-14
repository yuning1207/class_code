#include <iostream>
using namespace std;

int division(int x,int y);
int main(void)
{
	int m,n;
	cout<<"Please input two  intergers:";
	cin>>m>>n;
	try
	{
		cout<<division(m,n)<<endl;
	}
	catch(int)
	{
		cout<<"Divided by 0!"<<endl;
		return -1;
	}
	return 0;
}
int division(int x,int y)
{
	if(y==0)
		throw 0;
	else
		return (x/y);
}