#include <iostream>
using namespace std;

double hmean(double a,double b);
double hmean(double a,double b)
{
	char * s;
	s="bad hmean() arguments: a = -b not allowed";
	if(a+b==0)
	{
		throw s;
	}	
	return 2*a*b/(a+b);
}
int main()
{
    double x, y;
    cin >> x >> y; 
    try {
          cout<<hmean(x,y);
    }
    catch (const char * s)
    {
        cout << s << endl;
    }
    return 0;
}