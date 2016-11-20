#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 100

typedef struct
{
	int data[maxsize];
	int front; 
	int rear;
}csequeue;

csequeue * initcsequeue(void);
int incsequeue(csequeue * s,char x);
int outcsequeue(csequeue * s,char * x);

csequeue * initcsequeue(void)//置空队 
{
	csequeue * s;
	s=(csequeue *)malloc(sizeof(csequeue));
	s->front=s->rear=maxsize-1;
	return s;
}

int incsequeue(csequeue * s,char x)//入队 
{
	if((s->rear+1)%maxsize==s->front)
	{
		printf("队满！");
		return 0;
	}
	else
	{
		s->rear=(s->rear+1)%maxsize;
		s->data[s->rear]=x;
		return 1;
	}
} 

int outcsequeue(csequeue * s,char * x)//出队 
{
	if(s->front==s->rear)
	{
		printf("队空！");
		return 0;
	}
	else
	{
		s->front=(s->front+1)%maxsize;
		*x=s->data[s->front];
		return 1;
	}
} 
int main(void)
{
	csequeue *s;
	char a[100]={0},b[100]={0};
	int i=0,j=0;
	char x=0;
	s=initcsequeue();
	gets(a);
	for(i=0;a[i]!='#';i++)
	{
		j=incsequeue(s,a[i]);
		if(j==0)
			break;
	}
	for(i=0;s->front!=s->rear;i++)
	{
		j=outcsequeue(s,&b[i]);
		if(j==0)
			break;
	}
	puts(b);
	return 0;
}