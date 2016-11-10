#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 50

typedef struct a
{
	char ch[maxsize+1];
	int len;
}sstring;

int index(sstring * s,int pos,sstring * t);//bfÄ£Ê½Æ¥Åä 
sstring * initsstring(void);//ÖÃ¿Õ´® 
int sstringassign(sstring * s);//¸ø´®s¸³Öµ 

int sstringassign(sstring * s)
{
	int i=0;
	char * a;
	a=(char *)malloc(sizeof(char));
	if(a==NULL)
		return 0;
	if(s==NULL||s->ch==NULL)
		return 0;
	gets(a);
	while(a[i]!='\0')
		i++;
	s->len=i;
	s->ch[0]=s->len;
	for(i=1;i<=s->len;i++)
		s->ch[i]=a[i-1];
	return 1;
}
int index(sstring * s,int pos,sstring * t)
{
	int i=pos;
	int j=1;
	while(i<=s->len&&j<=t->len)
	{
		if(s->ch[i]==t->ch[j])
		{
			i++;
			j++;
		}
		else{
			i=i-j+2;
			j=1;
		}
	}
	if(j>t->len)
		return i-t->len;
	else
		return 0;
}
sstring * initsstring(void)
{
	sstring * s;
	s=(sstring *)malloc(sizeof(sstring));
	if(s!=NULL)
		return s;
}
int main(void)
{
	int i,pos;
	sstring * s;
	sstring * t;
	t=initsstring();
	s=initsstring();
	i=sstringassign(s);
	if(i==0)
		return 0;
	i=sstringassign(t);
	if(i==0)
		return 0;
	pos=1;
	i=index(s,pos,t);
	printf("%d",i);
	return 0;
}