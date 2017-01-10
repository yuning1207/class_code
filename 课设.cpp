#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <windows.h>

typedef struct node
{
	int weight;
	int parent,lchild,rchild;
	char data_;
}huffmantree;

char ** creathuffmantree(huffmantree * ht,char * data,int * w,int n);//建立哈夫曼树
void select(huffmantree * ht,int n,int s1,int s2);
//找出数组前n个元素中权值最小的两个节点下标，分别用s1,s2保存 
int readfp(FILE ** fp);//读取文件
void huffmancode(char ** hc,char * ch,char * data,int n,int x);//对文件进行编码
void huffmandecode(huffmantree * ht,char ** hc,char * data,int n,int m);//对文件进行译码 

void huffmandecode(huffmantree * ht,char ** hc,char * data,int n,int m)
{
	char * code;
	int fsize,j;
	int i=m;
	FILE * fp2;
	FILE * fp3;
	char filename[100]={'0'};
	Sleep(500);
	//system("cls");
	fsize=readfp(&fp2);
	code=(char *)malloc(fsize*sizeof(char));
	fgets(code,fsize+1,fp2);
	system("cls");
	printf("现在进行译码!\n");
	printf("请输入将译码存入的文件的完整路径及名称：\n");
	gets(filename);
	fp3=fopen(filename,"wt");
	system("cls");
	printf("译码结果为：\n");
	Sleep(1000);
 	for(j=0;j<=fsize;j++)
 	{	
	 	if(code[j]=='0')
	 	{
	 		i=ht[i].lchild;
	 	}	
 		else
 		{
		 	i=ht[i].rchild;
		 }	
		if((ht[i].lchild==0)&&(ht[i].rchild==0))
		{
			printf("%c",ht[i].data_);
			fprintf(fp3,"%c",ht[i].data_);
			i=m;
		}		
	 }
}
void huffmancode(char ** hc1,char * ch,char * data,int n,int x)
{
	int i,j;
	FILE * fp1;
	char filename[100]={'0'};
	printf("现在开始进行编码！\n");
	printf("请输入将编码要存入的文件完整路径和文件名：\n");
	gets(filename);
	fp1=fopen(filename,"wt");
	for(i=1;i<=x;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(ch[i-1]==data[j])
			{
				printf("%c的编码为：%s\n",data[j],hc1[j]);
				fprintf(fp1,"%s",hc1[j]);
				break;
			}	
		}
	}
	fclose(fp1);
}
int readfp(FILE ** fp)
{
	int fno;
	int fsize;
	char filename[100]={0};
	printf("请输入要打开文件的完整路径及文件名：\n"); 
	gets(filename);
	*fp=fopen(filename,"rt");
	if(*fp==NULL)
	{
		printf("文件打开失败！%s可能不存在！",filename);
		exit(1);
	}
	fno=fileno(*fp);
	fsize=filelength(fno);
	return fsize;
}
void select(huffmantree * ht,int n,int * s1,int * s2)
{
	int min1,min2;
	int i,j,k,m;
	for(i=1;i<=n;i++)
	{
		if(ht[i].parent==0)
		{
			min1=ht[i].weight;
			k=i;
			for(j=i;j<=n;j++)
			{
				if(ht[j].weight<=min1&&ht[j].parent==0)
				{
					min1=ht[j].weight;
					k=j;
				}		
			}
			(*s1)=k;
			break;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(ht[i].parent==0&&i!=(*s1))
		{
			min2=ht[i].weight;
			m=i;
			for(j=i;j<=n;j++)
			{
				if(ht[j].weight<=min2&&j!=(*s1)&&ht[j].parent==0)
				{
					min2=ht[j].weight;
					m=j;
				}		
			}
			(*s2)=m;
			break;
		}	
	}
}
char ** creathuffmantree(huffmantree * ht,char * data,int * w,int n)
{
	int i,c,f,j;
	int m,s1,s2;
	char * code;
	char ** hc;
	m=2*n-1;
	for(i=1;i<=n;i++)
	{
		ht[i].data_=data[i];
		ht[i].weight=w[i];
		ht[i].parent=0;
		ht[i].lchild=0;
		ht[i].rchild=0;
	}
	for(i=n+1;i<=m;i++)
	{
		ht[i].data_='0';
		ht[i].weight=0;
		ht[i].parent=0;
		ht[i].lchild=0;
		ht[i].rchild=0;
	}
	for(i=n+1;i<=m;i++)
	{
		select(ht,i-1,&s1,&s2);
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[s1].parent=ht[s2].parent=i;
		ht[i].lchild=s1;
		ht[i].rchild=s2;
	}
	hc=(char **)malloc(n*sizeof(char *));
	code=(char *)malloc(n*sizeof(char));
	//开始编码 
	for(i=1;i<=n;i++)//编码从第一位开始存 
	{
		for(c=i,f=ht[i].parent,j=0;f!=0;c=ht[c].parent,f=ht[c].parent,j++)
		{
			if(ht[f].lchild==c)
			{
				code[j]='0';
			}		
			else if(ht[f].rchild==c)
			{
				code[j]='1';
			}		
		}
		code[j]='\0';
		int k,m,len;
		char t;
		len=strlen(code);
		for(k=0,m=len-1;k<m;k++,m--)
		{
			t=code[k];
			code[k]=code[m];
			code[m]=t;
		}
		code[len]='\0';
		hc[i]=(char *)malloc(strlen(code)*sizeof(char));
		strcpy(hc[i],code);
	}
	return hc;
}
int main(void)
{
	huffmantree * ht;
	char * ch;
	char c;
	int x,m,i=0,j,k=1,mark;
	int w[256]={0};
	char data[256]={'0'};
	FILE * fp;
	char ** hc1;
	x=readfp(&fp);
	ch=(char *)malloc(x*sizeof(char));
	while((c=getc(fp))!=EOF)
	{
		ch[i]=c;
		i++;
	}
	fclose(fp);
	for(i=0;i<x;i++)
	{
		c=ch[i];
		mark=0;
		for(j=1;j<k;j++)
		{
			if(c==data[j])
			{
				w[j]++;
				mark=1;
				break;
			}
		}
		if(mark==0)
		{
			data[k]=ch[i];
			w[k]=1;
			k++;
		}
	}
	printf("从文件中读到的内容为：\n");
	Sleep(1000);
	for(i=0;i<x;i++)
		printf("%c",ch[i]);
	printf("\n");
	Sleep(2000);
	system("cls");
	m=2*(k-1)-1;
	ht=(huffmantree *)malloc((m+1)*sizeof(huffmantree));
	hc1=(char **)malloc(k*sizeof(char *));
	for(i=0;i<k;i++)
		hc1[i]=(char *)malloc(sizeof(char));
	hc1=creathuffmantree(ht,data,w,k-1);
	huffmancode(hc1,ch,data,k,x); 
	huffmandecode(ht,hc1,data,k-1,m);
	return 0;
}
