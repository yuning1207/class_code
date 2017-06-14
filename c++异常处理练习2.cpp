#include <iostream>
#include <cmath>

using namespace std;

double mySqrt(double x);
double mySqrt(double x)
{
	char * s;
	s="Error: Can not take sqrt of negative number";
	if(x<0)
	{
		throw s;
	}
	else
	{
		cout<<"The sqrt of "<<x<<" is "<<sqrt(x)<<endl;
	}
	return 0;
}
int main(void)
{
	double x;
	cin>>x;
	try
	{
		mySqrt(x);
	}
	catch(char * s)
	{
		cout<<s<<endl;
	}
	return 0;
}