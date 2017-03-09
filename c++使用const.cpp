#include <iostream>

using namespace std;

void f(int model,int m);

void f(int model,int m)
{
	model==200;
	m++;
	cout<<model<<endl;
	cout<<m<<endl;
}

int main(void)
{
	int model=90;
	int v[]={1,2,3,4};
	const int x=5;
	f(model,v[2]);
	cout<<x<<endl;
	return 0;
}


