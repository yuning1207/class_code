#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double a,b,c,s,p;
	cin>>a>>b>>c;
	if((a+b)<=c||(a+c)<=b||(b+c)<=a||fabs(a-b)>=c||fabs(a-c)>=b||fabs(b-c)>=a)
		cout<<"No";
	else
	{
		p=(a+b+c)/2;
		s=sqrt(p*(p-a)*(p-b)*(p-c));
		cout<<s<<endl;
	}
	return 0;
} 