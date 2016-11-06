#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxsize 100

typedef struct
{
	int data[maxsize];
	int top;
}SeqStack;

SeqStack *init_SeqStack();//����ջ 
int Empty_SeqStack(SeqStack * s);//�ж�ջ�Ƿ�Ϊ�� 
int Push_SeqStack(SeqStack * s,char x);//����x����ջ 
int Pop_SeqStack(SeqStack * s,char * x);//��ջ��������ջ��Ԫ�ش���x�� 

SeqStack *init_SeqStack()
{
	SeqStack * s;
	s=(SeqStack *)malloc(sizeof(SeqStack));//Ϊջ����ռ� 
	s->top=-1;//��ʼtopֵ��Ϊ-1 
	return s;	
}
int Empty_SeqStack(SeqStack * s)
{
	if(s->top==-1)
		return 1;//��ջ�գ�����1 
	else
		return 0; 
}
int Push_SeqStack(SeqStack * s,char x)
{
	if(s->top==maxsize-1)//��ջ��������0 
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
		*x=s->data[s->top];//��ջ��Ԫ�ظ���x 
		s->top--;
		return 1;
	}
}

int main(void)
{
	char a[100]={0};//��ʼ������ 
	char b[100]={0}; 
	int i,j;
	gets(a);//����һ���ַ�����@���� 
	SeqStack * s;
	s=init_SeqStack();
	for(i=0;a[i]!='@';i++)//����һ���ַ���ջ����@��û����ջ 
	{
		j=Push_SeqStack(s,a[i]);
		if(j==0)
			break;
	}
	for(i=0;;i++)//�ٳ�ջ����һ�������� 
	{
		j=Pop_SeqStack(s,&b[i]);
		if(j==0)
			break;
	}
	b[i]='@';//�ٽ���@������b[i] 
	if(strcmp(a,b)==0)//�ж����������Ƿ���ͬ 
		printf("�������֣�\n");
	else
		printf("���ǻ������֣�\n");
	return 0;	
} 