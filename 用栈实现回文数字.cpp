#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxsize 100

typedef struct
{
	int data[maxsize];
	int top;
}SeqStack;

SeqStack *init_SeqStack();
int Empty_SeqStack(SeqStack * s);
int Push_SeqStack(SeqStack * s,char x);
int Pop_SeqStack(SeqStack * s,char * x);

SeqStack *init_SeqStack()
{
	SeqStack * s;
	s=(SeqStack *)malloc(sizeof(SeqStack));
	s->top=-1;
	return s;	
}
int Empty_SeqStack(SeqStack * s)
{
	if(s->top==-1)
		return 1;
	else
		return 0; 
}
int Push_SeqStack(SeqStack * s,char x)
{
	if(s->top==maxsize-1)
	return 0;
	else{
		s->top++;
		s->data[s->top]=x;
		return 1;
	}
}
int Pop_SeqStack(SeqStack * s,char * x)
{
	if(Empty_SeqStack(s)==1)
		return 0;
	else{
		* x=s->data[s->top];
		s->top--;
		return 1;
	}
}

int main(void)
{
	char a[100]={0},b[100]={0};
	int i,j;
	gets(a);
	SeqStack * s;
	s=init_SeqStack();
	for(i=0;a[i]!='\0';i++)
	{
		j=Push_SeqStack(s,a[i]);
		if(j==0)
			break;
	}
	for(i=0;;i++)
	{
		j=Pop_SeqStack(s,&b[i]);
		if(j==0)
			break;
	}
	b[i]='\0';
	if(strcmp(a,b)==0)
		printf("回文数字！");
	else
		printf("不是回文数字！");
	return 0;	
} 