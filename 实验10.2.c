#include <stdio.h>
#define one(a) "%6.2f\n",a
#define two(a,b) "%6.2f%6.2f\n",a,b
#define three(a,b,c) "%6.2f%6.2f%6.2f\n",a,b,c
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf(one(a));
	printf(two(a,b));
	printf(three(a,b,c));
}