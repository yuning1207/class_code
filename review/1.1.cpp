#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	double a,b,c,p,s;
	cout<<"请在这里写输入三角形的三条边长，例如：3.1 4.2 5.3"<<endl;
	cin>>a>>b>>c;
	if(a+b>c||a+c>b||b+c>a||abs(a-b)<c||abs(a-c)<b||abs(b-c)<a)
	{
		p=(a+b+c)/2;
		s=sqrt(p*(p-a)*(p-b)*(p-c));
		cout<<s<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
} 