#include <stdio.h>

int main(void)
{
	int a[5]={1,5,3,4,9};
	int i,j,t;
	for(i=0;i<5;i++)
	{
		for(j=i;j<5;j++)
		{
			if(a[i]>=a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0;i<5;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}