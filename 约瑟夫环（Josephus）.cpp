#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
	struct node * next;
	int password;
	int num;
}node;

node head={0};

void creatlist(node * p,int n);
void josephusoperate(node * p,int password,int n);
void josephusoperate(node * p,int password,int n)
{
	int i=0;
	node * q;
	for(;n>0;p=p->next)
	{
		i++;
		if(i==password-1)
		{
			printf("%d ",p->next->num);
			password=p->next->password;
			q=p->next;
			p->next=p->next->next;
			free(q);
			n--;
			i=0;
		}
	}
	return;
}
void creatlist(node * p,int n)
{
	int * a;
	int i;
	a=(int *)malloc(n*sizeof(int));
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int password;
	int num;
	for(i=1;i<=n;i++)
	{
		p->num=i;
		p->password=a[i];
		if(i!=n)
		{
			p->next=(node *)malloc(sizeof(node));
			p=p->next;
		}	
	}
	p->next=&head;
	free(a);
	return;
}
int main(void)
{
	int num;
	int password;
	scanf("%d %d",&num,&password);
	creatlist(&head,num);
	josephusoperate(&head,password,num);
	return 0;
}