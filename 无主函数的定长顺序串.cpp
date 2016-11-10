#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 50

typedef struct a 
{
	char ch[maxsize+1];
	int len;
}sstring;

sstring * initstring(void);//置空串
int sstringinsert(sstring * s,int pos,const sstring t);//串插入函数 const为定义常量，具有不可变性 
int sstringdelete(sstring * s,int pos,int len);//串删除函数 
int sstringcat(sstring * s,const sstring t);//串连接函数 
int subsstring(sstring * t,sstring s,int pos,int len);//求子串函数 

int subsstring(sstring * t,sstring s,int pos,int len)
{
	int i;
	if(t==NULL||t->ch==NULL||s.ch==NULL||pos<1||pos>s.len||len<0||len>(s.len-pos+1))
		return 0;
	for(i=pos;i<=pos+len;i++)
		t->ch[i-pos+1]=s.ch[i];
	t->len=len;
	return 1;
}
int sstringcat(sstring * s,const sstring t)
{
	int i;
	if(s==NULL||s->ch==NULL||t.ch==NULL)
		return 0;
	if(s->len+t.len<=maxsize)//连接后的串没有被截断
	{
		for(i=s->len+1;i<=s->len+t.len;i++)
			s->ch[i]=t.ch[i-s->len];
		s->len=s->len+t.len;
		return 1;
	}
	else if(s->len+t.len>maxsize)//连接后的串t被截断
	{
		for(i=s->len+1;i<=maxsize;i++)
			s->ch[i]=t.ch[i-s->len];
		s->len=maxsize;
		return 0;
	} 
	else //s的长度==maxsize 
		return 0;
}
int sstringdelete(sstring * s,int pos,int len)
{
	int i;
	if(s->ch==NULL||s==NULL||pos<1||pos>(s->len-len+1))
		return 0;
	for(i=pos;i<=s->len-len;i++)
		s->ch[i]=s->ch[i+len];
	s->len=s->len-len;
	return 1;
} 
int sstringinsert(sstring * s,int pos,const sstring t)
{
	int i;
	if(s->ch==NULL||s==NULL||t.ch==NULL||pos<1||pos>(s->len+1))
		return 0;
	if(s->len+t.len<maxsize+1)//插入后串没有被截断 
	{
		for(i=s->len+t.len;i>=pos+t.len;i--)
			s->ch[i]=s->ch[i-t.len];
		for(i=pos;i<s->len+t.len;i++)
			s->ch[i]=t.ch[i-pos+1];
		s->len=s->len+t.len; 
	}
	else if(pos+t.len<maxsize+1)//插入后t没有被截断 
	{
		for(i=maxsize;i>=pos+t.len;i--)
			s->ch[i]=s->ch[i-t.len];
		for(i=pos;i<pos+t.len;i++)
			s->ch[i]=t.ch[i-pos+1];
		s->len=maxsize;
	}
	else//插入后t被截断 
	{
		for(i=pos;i<=maxsize;i++)
			s->ch[i]=t.ch[i-pos+1];
		s->len=maxsize;
	}
	return 1;
} 
sstring * initstring(void)
{
	sstring * s;
	s=(sstring *)malloc(sizeof(sstring));
	return s;
}
int main(void)
{
	return 0;
}