#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 10

typedef struct 
{
	char element[maxsize];
	int top;
}seqstack;

int opreta(int a,char x,int b); 
char compare(char a,char b);
int in(char x,char op[]);
seqstack * intistack(void);
int push(seqstack * p,char x);
char pop(seqstack * p);
int exp(void);
char popo(seqstack * p);
char op[7]={'+','-','*','/','(',')','#'};

char popo(seqstack * p)
{
	char x;
	if(p->top==-1)
	{
		return 0;
	}
	x=p->element[p->top];
	return x;	
}
int opreta(int a,char x,int b)
{
	if(x=='+')
	{
		return (a+b);
	}
	else if(x=='-')
	{
		return (a-b);
	}
	else if(x=='*')
	{
		return (a*b);
	}
	else if(x=='/')
	{
		return (a/b);
	}
}
char compare(char a,char b)
{ 
	int i,j;
	char pre[][7]=
		{
		{'>','>','<','<','<','>','>'},  
        {'>','>','<','<','<','>','>'},  
        {'>','>','>','>','<','>','>'},  
        {'>','>','>','>','<','>','>'},  
        {'<','<','<','<','<','=','0'},  
        {'>','>','>','>','0','>','>'},  
        {'<','<','<','<','<','0','='}
		};
  switch(a)
  {
  	case '+':
  	{
	  	i=0;
	  	break;
  	}
	case '-':
  	{
	  	i=1;
	  	break;
  	}
	case '*':
  	{
	  	i=2;
	  	break;
  	}
	case '/':
  	{
	  	i=3;
	  	break;
  	}
	case '(':
  	{
	  	i=4;
	  	break;
  	} 
  	case ')':
  	{
	  	i=5;
	  	break;
  	}
  	case '#':
  	{
	  	i=6;
	  	break;
  	}
  } 
  switch(b)
  {
  	case '+':
  	{
	  	j=0;
	  	break;
  	}
	case '-':
  	{
	  	j=1;
	  	break;
  	}
	case '*':
  	{
	  	j=2;
	  	break;
  	}
	case '/':
  	{
	  	j=3;
	  	break;
  	}
	case '(':
  	{
	  	j=4;
	  	break;
  	} 
  	case ')':
  	{
	  	j=5;
	  	break;
  	}
  	case '#':
  	{
	  	j=6;
	  	break;
  	}	
  }
  return pre[i][j];
}
int in(char x,char op[])
{
	int i=0;
	while(op[i])
	{
		if(x==op[i])
		{
			return 1;
		}
		i++;
	}
	return 0;
}
char pop(seqstack * p)
{
	char x;
	if(p->top==-1)
	{
		printf("Ê§°Ü");
		return 0; 
	}
	x=p->element[p->top];
	p->top--;
	return x;
}
int push(seqstack * p,char x)
{
	if(p->top==maxsize-1)
	{
		return 0;
	}
	else
	{
		p->top++;
		p->element[p->top]=x;
		return 1;
	}
}
seqstack * intistack()
{
	seqstack * s;
	s=(seqstack *)malloc(sizeof(seqstack));
	s->top=-1;
	return s;	
}
int exp()
{
	char ch;
	char x;
	int a,b,val,j,data;
	seqstack * oprd;
	seqstack * optr;
	oprd=intistack();
	optr=intistack();
	j=push(optr,'#');
	if(j==0)
	{
		printf("Ê§°Ü");
		return 0; 
	}
	printf("please input an expression:");
	fflush(stdin);
	ch=getchar();
	while(ch!='#'||popo(optr)!='#')
	{
		data=0;
		while(!in(ch,op))
		{
			data+=ch-'0';
			ch=getchar();
		}
		j=push(oprd,data);
		if(j==0)
 		{
			printf("Ê§°Ü");
			return 0; 
		}
		switch(compare(ch,x=popo(optr)))
		{
			case '>':
			{
				j=push(optr,ch);
				if(j==0)
				{
					printf("Ê§°Ü");
					return 0; 
				}
				ch=getchar();
				break;	
			}
			case '=':
			{
				x=pop(optr);
				ch=getchar();
				break;
			}
			case '<':
			{
				x=pop(optr);
				a=pop(oprd);
				b=pop(oprd);
				val=opreta(a,x,b);
				j=push(oprd,val);
				if(j==0)
				{
					printf("Ê§°Ü");
					return 0; 
				}
				ch=getchar();
				break;
			}
		}
	}
	val=pop(oprd);
	return val;
}
int main(void)
{
	int x;
	x=exp();
	printf("%d\n",x);
	return 0;
}

