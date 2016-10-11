#include <stdio.h>
#define s(a,b) {int c;c=a;a=b;b=c;}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	s(a,b);
	printf("%-5d%-5d",a,b);
}