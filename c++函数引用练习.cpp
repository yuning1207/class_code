#include <iostream>
using namespace std;
/* 你提交的代码将被嵌入到这里 */

void f(int * a,int x,int & max,int & min);

void f(int * a,int x,int & max,int & min)
{
	int i,j;
	int t;
	for(i=0;i<10;i++)
	{
		for(j=i;j<10;j++)
		{
			if(*(a+i)>*(a+j))
			{
				t=*(a+i);
				*(a+i)=*(a+j);
				*(a+j)=t;
			}
		}
	}
	min=*a;
	max=*(a+9);
}
int main( )
{
  int a[10];
  int max,min,i;
  for(i=0;i<10;i++){
     cin>>a[i];
  }
  f(a,10,max,min);
  cout<<"Max: "<<max<<endl;
  cout<<"Min: "<<min<<endl;
  return 0;
}