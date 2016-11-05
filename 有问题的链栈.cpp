#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define m 10

typedef struct stacknode
{
	char data;
	struct stacknode * next;
}lstacktype;

int pushdupsls(lstacktype * top[m],int i,char x);
char popdupsls(lstacktype * top[m],int i);

char popdupsls(lstacktype * top[m],int i)
{
	lstacktype * p;
	char x;
	p=(lstacktype *)malloc(sizeof(lstacktype));
	if(p==NULL)
	{
		return 0;
	}
	if(top[i]->next==NULL)
	{
		return 0;
	}
	p=top[i]->next;
	x=p->data; 
	top[i]->next=p->next;
	free(p);
	return x; 
}
int pushdupsls(lstacktype * top[m],int i,char x)
{
	lstacktype * p;
	p=(lstacktype *)malloc(sizeof(lstacktype));
	if(p==NULL)
	{
		return 0;
	}
	p->data=x;
	p->next=top[i]->next;
	top[i]->next=p;
	return 1;
}

int main(void)
{
	int i,j,k;
	char a[5];
	char b[5];
	char c[5];
	lstacktype  *top[m];
	for(i=0;i<m;i++)
	{
		top[i]=(lstacktype *)malloc(sizeof(lstacktype)); 
		top[i]->data=i; 
		top[i]->next=NULL;
	}
	gets(a);
	gets(b);
	for(i=0;i<5;i++)
	{
		j=pushdupsls(&top[m],a[i],b[i]);
		if(j==0)
		{
			break;
		}
	}
	scanf("%d",&i);
	while(1)
	{
		j=popdupsls(&top[m],i);
		if(j==0)
		{
			break;
		}
		for(k=0;k<5;k++)
		{
			c[k]=j;
		}
	}
	puts(c);
	return 0;
}