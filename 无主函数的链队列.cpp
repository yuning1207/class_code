#include <stdio.h>
#include <stdlib.h>

typedef struct a
{
	char data;
	struct a * next;
}qnode;

typedef struct b
{
	qnode * front;
	qnode * rear;
}lqueue;

lqueue * initlqueue(void);
void inlqueue(lqueue * p,char x);
int outlqueue(lqueue * s,char * x);

lqueue * initlqueue(void)//????   
{
	lqueue * p;
	qnode * q;
	p=(lqueue *)malloc(sizeof(lqueue));
	q=(qnode *)malloc(sizeof(qnode));
	q->next=NULL;
	p->front=p->rear=q;
	return p;
}

void inlqueue(lqueue * p,char x)
{
	qnode * q;
	q=(qnode *)malloc(sizeof(qnode));
	q->data=x;
	q->next=NULL;
	p->rear->next=q;
	p->rear=q;
}

int outlqueue(lqueue * p,char * x)
{
	if(p->front==p->rear)
	{
		printf("????");
		return 0;
	}
	qnode * q;
	q=(qnode *)malloc(sizeof(qnode));
	q=p->front->next;
	p->front->next=q->next;
	*x=q->data;
	free(q);
	if(p->front->next==NULL)
		p->rear=p->front;
	return 1;
}