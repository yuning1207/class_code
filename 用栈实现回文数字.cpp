#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxsize 100

typedef struct
{
	int data[maxsize];
	int top;
}SeqStack;

SeqStack *init_SeqStack();//建立栈 
int Empty_SeqStack(SeqStack * s);//判断栈是否为空 
int Push_SeqStack(SeqStack * s,char x);//进行x的入栈 
int Pop_SeqStack(SeqStack * s,char * x);//出栈，并将出栈的元素存入x中 

SeqStack *init_SeqStack()
{
	SeqStack * s;
	s=(SeqStack *)malloc(sizeof(SeqStack));//为栈分配空间 
	s->top=-1;//初始top值赋为-1 
	return s;	
}
int Empty_SeqStack(SeqStack * s)
{
	if(s->top==-1)
		return 1;//若栈空，返回1 
	else
		return 0; 
}
int Push_SeqStack(SeqStack * s,char x)
{
	if(s->top==maxsize-1)//若栈满，返回0 
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
		*x=s->data[s->top];//将栈顶元素赋给x 
		s->top--;
		return 1;
	}
}

int main(void)
{
	char a[100]={0};//初始化数组 
	char b[100]={0}; 
	int i,j;
	gets(a);//输入一串字符，以@结束 
	SeqStack * s;
	s=init_SeqStack();
	for(i=0;a[i]!='@';i++)//将这一串字符入栈，‘@’没有入栈 
	{
		j=Push_SeqStack(s,a[i]);
		if(j==0)
			break;
	}
	for(i=0;;i++)//再出栈到另一个数组中 
	{
		j=Pop_SeqStack(s,&b[i]);
		if(j==0)
			break;
	}
	b[i]='@';//再将‘@’赋给b[i] 
	if(strcmp(a,b)==0)//判断两个数组是否相同 
		printf("回文数字！\n");
	else
		printf("不是回文数字！\n");
	return 0;	
} 