#include <stdio.h>
#include <stdlib.h>
int main()
{
	int **p;
	int x,y,i,j,t;
	scanf("%d%d",&x,&y);
	p=(int **)malloc(x*sizeof(int *));
	for(i=0;i<x;i++)
		p[i]=(int *)malloc(y*sizeof(int));
	t=1;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			p[i][j]=t;
			t++;
		}
	}
    for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			printf("%-5d",p[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<x;i++)
		free(p[i]);
	free(p);
}