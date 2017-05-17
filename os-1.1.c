#include <stdio.h>
int main()
{
	int p1,p2;
	if(p1=fork())
	{
		putchar('b');
	}
	else
	{
		if(p2=fork())
		{
			putchar('c');
		}
		else
		{
			putchar('a');
		}
	}
}
