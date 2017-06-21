#include <iostream>
using namespace std;

template<typename T>

T Min (T *a,int n)
{
	int i;
	T t;
	t=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]<t)
		{
			t=a[i];
		}
	}
	return t;
}
int main(void)
{
	int m,n,i;
	int * a;
	double * b;
	cin>>m;
	a=new int[m];
	for(i=0;i<m;i++)
	{
		cin>>a[i];
	}
	cin>>n;
	b=new double[n];
	for(i=0;i<n;i++)
	{
		cin>>b[i];
	}
	cout<<Min(a,m)<<endl;
	cout<<Min(b,n)<<endl;
	return 0;
}