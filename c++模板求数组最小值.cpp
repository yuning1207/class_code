#include <iostream>
using namespace std;

template<typename T>

T Min(T *p, int len)
{
	int i,j;
	T t;
	for(i=0;i<len;i++)
	{
		for(j=i;j<len;j++)
		{
			if(*(p+i)>*(p+j))
			{
				t=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=t;
			}
		}
	}
	return *p;
} 

int main( )
{
    int n,m,*pn,i=0;
    cin>>n;
    pn=new int[n];
    do{
        cin>>pn[i];
        i++;
    }while(i<n);

    double *pd;
    i=0;
    cin>>m;
    pd=new double[m];
    do{
        cin>>pd[i];
        i++;
    }while(i<m);

    cout<<Min(pn,n)<<endl;
    cout<<Min(pd,m)<<endl;
    delete [ ] pn;
    delete [ ] pd;
    return 0;
}