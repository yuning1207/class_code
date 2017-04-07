#include <stdio.h>

void change(int *a,int *b);

void change(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t; 
}
int main(void)
{
	int a=3,b=5;
	change(&a,&b);
	printf("%d,%d\n",a,b);
} 