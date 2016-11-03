#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stacknode
{
	char data;
	struct stacknode * next;	
}lstacktype;

int pushlstack(lstacktype * top,char x);
char poplstack(lstacktype * top);

char poplstack(lstacktype * top)
{
	lstacktype * p;
	char x;
	p=(lstacktype *)malloc(sizeof(lstacktype));
	if(p==NULL)
	{
		return 0;
	}
	p=top->next;
	if(p==NULL)
	{
		return 0;
	}
	top->next=p->next;
	x=p->data;
	free(p);
	return x;
}
int pushlstack(lstacktype * top,char x)
{
	lstacktype * p;
	p=(lstacktype *)malloc(sizeof(lstacktype));
	if(p==NULL)
	{
		return 0;
	}
	p->data=x;
	p->next=top->next;
	top->next=p;
	return 1;
}
int main(void)
{
	lstacktype * top;
	char a[100]={0};
	char b[100]={0};
	int i=0,j;
	top=(lstacktype *)malloc(sizeof(lstacktype));
	top->next=NULL;
	top->data=0;
	gets(a);
	while(1)
	{
		if(a[i]!='@')
		{
			j=pushlstack(top,a[i]);
		}
		else
		{
			break;
		}
		if(j==0)
		{
			return 0;
		}
		i++;
	}
	for(i=0;;i++)
	{
		b[i]=poplstack(top);
		if(b[i]==0)
		{
			break;
		}
	}
	b[i]='@';
	if(strcmp(a,b)==0)
	{
		printf("回文数字");
	} 
	else
	{
		printf("不是回文数字");
	}
	return 0;
}