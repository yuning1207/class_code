#include <iostream>
using namespace std;
double max(double x,double y);
long max(long x,long y);
int max(int x,int y);

double max(double x,double y)
{
	return (x>y)?x:y;
}

long max(long x,long y)
{
	return (x>y)?x:y;
}

int max(int x,int y)
{
	return (x>y)?x:y;
}
int main()
{
  int x1,y1; long x2,y2; double x3,y3;
  cin>>x1>>y1;
  cout<<"max="<<max(x1,y1)<<endl;
  cin>>x2>>y2;
  cout<<"max="<<max(x2,y2)<<endl;
  cin>>x3>>y3;
  cout<<"max="<<max(x3,y3)<<endl;
  return 0;
}