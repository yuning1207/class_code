#include <stdio.h>

int mjs(int x,int n)
{
	if(n==0)
		return 1;
	return (x*mjs(x,n-1));
}

int main()
{
	int x,n;
	scanf("%d %d",&x,&n);
	printf("%ld\n",mjs(x,n));
}
/*
#include <stdio.h>

int dg(int x)
{
	if(x==0)
		return 1;
	return (x*dg(x-1));
}

int main()
{
	int x;
	scanf("%d",&x);
	printf("%ld\n",dg(x));
}
*/