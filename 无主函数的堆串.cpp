#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct a 
{
	char * ch;
	int len;
}hstring;

hstring * hstringinit(void);//ÖÃ¿Õ´®
int hstringassign(hstring * s,const char * char);//´®¸³Öµº¯Êý 
int hstringinsert(hstring * s,int pos,const hstring t);//´®²åÈëº¯Êý 
int hstringdelete(hstring * s,int pos,int len);//´®É¾³ýº¯Êý 
int hstringcat(hstring * s,const hstring t);//´®Á¬½Óº¯Êý 
int subhstring(hstring * t,hstring s,int pos,int len);//Çó×Ó´®º¯Êý 

int subhstring(hstring * t,hstring s,int pos,int len)
{
	if(t==NULL||t->ch==NULL||s.ch==NULL||pos<1||pos>s.len||len<0||len>(s.len-pos+1))
		return 0;
	t->len=len;
	t->ch=(char *)malloc((t->len+1)*sizeof(char));
	if(t->ch==NULL)
		return 0;
	for(i=1;i<=len;i++)
		t->ch[i]=s->ch[i+pos-1];
	return 1;
}
int hstringcat(hstring * s,const hstring t)
{
	int i;
	char * temp;
	if(s==NULL||s->ch==NULL||t.ch==NULL)
		return 0;
	temp=(char *)malloc((s->len+t.len+1)*sizeof(char));
	if(temp==NULL)
		return 0;
	for(i=1;i<=s->len;i++)
		temp[i]=s->ch[i];
	for(i=s->len+1;i<=s->len+t.len;i++)
		temp[i]=t.ch[i-s->len];
	free(s->ch);
	s->ch=temp;
	s->len=s->len+t.len;
	return 1;
}
int hstringdelete(hstring * s,int pos,int len)
{
	int i;
	char * temp;
	if(s==NULL||s->ch==NULL||pos<1||pos>s->len||len>0||len<s->len-pos+1)
		return 0;
	temp=(char *)malloc((s->len-len+1)*sizeof(char));
	if(temp==NULL)
		return 0;
	for(i=1;i<pos;i++)
		temp[i]=s->ch[i];
	for(i=pos;i<=s->len-len;i++)
		temp[i]=s->ch[i+len];
	free(s->ch);
	s->ch=temp;
	s->len=s->len-len;
	return 1;
}
int hstringinsert(hstring * s,int pos,const hstring t)
{
	int i;
	char * temp;
	if(s==NULL||s->ch==NULL||t.ch==NULL||pos<1||pos>s->len||)
		return 0;
	temp=(char *)malloc((s->len+t.len+1)*sizeof(char));
	if(temp==NULL)
		return 0;
	for(i=1;i<pos;i++)
		temp[i]=s->ch[i];
	for(i=pos;i<=pos+t.len;i++)
		temp[i]=t.ch[i-pos+1];
	for(i=pos+t.len+1;i<=s->len+t.len;i++)
		temp[i]=s->ch[i-t.len];
	free(s->ch);
	s->ch=temp;
	s->len=s->len+t.len;
	return 1;
}
int hstringassign(hstring * s,const char * cha)
{
	int i=0;
	if(s==NULL||cha==NULL)
		return 0;
	while(cha[i]!='\0')
		i++;
	s->len=i;
	if(s->len!=0)
	{
		if(s->ch!=NULL)
			free(s->ch);
		s->ch=(char *)malloc((s->len+1)*sizeof(char));
		if(s->ch==NULL)
			return 0;
		for(i=1;i<=s->len;i++)
			s->ch[i]=cha[i-1];
	}
	else
		s->ch=NULL;
	return 1;
} 
hstring * hstringinit(void)
{
	hstring * s;
	s=(hstring *)malloc(sizeof(hstring));
	s->ch=NULL;
	s->len=0;
	return s;
}