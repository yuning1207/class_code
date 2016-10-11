#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p;
	int n,t,i;
	scanf("%d",&n);
	p=(int *)malloc(n*sizeof(int));
	t=1;
	for(i=0;i<n;i++)
	{
		p[i]=t;
		t++;
	}
    for(i=0;i<n;i++)
	{
		printf("%-5d",p[i]);
	}
	printf("\n");
	free(p);
}
