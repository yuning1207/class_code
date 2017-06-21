#include <iostream>
#include <cmath>
using namespace std;

double mySqrt(double x)
{
	if(x<0)
	{
		throw "Error:Can not take sqrt of negative number";
	}
	else
		return sqrt(x);
}
int main(void)
{
	double a;
	cin>>a;
	try
	{
		cout<<mySqrt(a)<<endl;
	}
	catch(const char * s)
	{
		cout<<s<<endl;
	}
}