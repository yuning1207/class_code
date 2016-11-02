#include <stdio.h>
#define maxsize 100
#include <stdlib.h>

typedef struct 
{
	char stack[maxsize];
	int lefttop;
	int righttop;
} dupsqstack;
int initdupsqstack(dupsqstack ** s);
int pushdupsqstack(dupsqstack * s,char status,char x);
char popdupsqstack(dupsqstack * s,char status);
char popdupsqstack(dupsqstack * s,char status)
{
	if(status=='l')
	{
		if(s->lefttop==-1)
			return NULL;
		else
			{
				s->lefttop--;
				return(s->stack[s->lefttop]);
			}
	}
	else if(status=='R')
	{
		if(s->righttop==maxsize-1)
			return NULL;
		else
		{
			s->righttop++;
			return(s->stack[s->righttop]);
		}
	}
	else
		return 0;
}
int pushdupsqstack(dupsqstack * s,char status,char x)
{
	if(s->lefttop+1==s->righttop)
		return 0;
	if(status='L')
	{
		s->lefttop++;
		s->stack[s->lefttop]=x;
	}
	else if(status='R')
	{
		s->righttop--;
		s->stack[s->righttop]=x;
	}
	else 
		return 0;
	return 1;
}
int initdupsqstack(dupsqstack ** s)
{
	*s=(dupsqstack *)malloc(sizeof(dupsqstack));
	if(*s==NULL){
		return 0;	
	}
	
	(*s)->lefttop= -1;
	(*s)->righttop=maxsize;
	return 1;
}
int main(void)
{
	dupsqstack * s;
	int i;
	char j,status;
	i=initdupsqstack(&s);
	if(i==0)
		return 0;
	while(1)
	{
		scanf("%c,%c\n",&j,&status);
		if(j=='#')
			break;
		i=pushdupsqstack(s,status,j);
		if(i==0)
			return 0;
	}
	j=1;
	while(j!=NULL)
	{
		scanf("%c",&status);
		j=popdupsqstack(s,status);
		printf("%c",j);	
	}
	return 0;
}