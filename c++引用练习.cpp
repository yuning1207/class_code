#include <iostream.h>
void f(int *a,int n,int &max,int &min)
{
	max=min=a[9];
	for(int i=0;i<n;i++)
	{
		if(max<a[i])
			max=a[i];
		if(min>a[i])
			min=a[i];
	}
} 
int main(void)
{
	int a[10],i;
	int max,min;
	for(i=0;i<10;i++){
     cin>>a[i];
    }
	f(a,10,max,min);
	cout<<"Max: "<<max<<endl;
	cout<<"Min: "<<min<<endl;
	return 0;
}