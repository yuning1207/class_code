#include <iostream>
using namespace std;

void f(int * a,int n,int & max,int & min);

void f(int * a,int n,int & max,int & min)
{
        int i,j,t;
        max=a[0];
        min=a[0];
        for(i=0;i<n;i++)
        {
                if(a[i]>max)
                {
                        max=a[i];
                }
                if(a[i]<min)
                {
                        min=a[i];
                }
        }
}
int main(void)
{
        int a[10];
        int max,min,i;
        for(i=0;i<10;i++)
        {
                cin>>a[i];
        }
        f(a,10,max,min);
        cout<<"Max: "<<max<<endl;
        cout<<"Min: "<<min<<endl;
        return 0;
}
