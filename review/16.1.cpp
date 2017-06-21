#include <iostream>
using namespace std;

double hmean(double x,double y)
{
	if(x+y==0)
	{
		throw "bad hmean()arguments: a=-b not allowed";
	}
	else
		return 2*x*y/(x+y);
}
int main(void)
{
	double x,y;
	cin>>x>>y;
	try
	{
		cout<<hmean(x,y);
	}
	catch(const char * s)
	{
		cout<<s<<endl;
	}
	return 0;
}