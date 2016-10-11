#include <stdio.h>
int fb(int x)
{
	if(x<1)
	{
		printf("输入不合法！\n");
		return -1;
	}
	if(x==1||x==2)
		return 1;
	else 
		return (fb(x-1)+fb(x-2));
}
int main()
{
	int x;
	scanf("%d",&x);
	printf("%d\n",fb(x));	
	return 0;
}