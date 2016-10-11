#include <stdio.h>
#include <stdlib.h>
struct student
{
	int num;
	char name[21];
	char sex;
	int score[4];
	float aver;
}s[];
void input(struct student s[],int n)
{
	int i,j;
	printf("please input the information:\n");
	for(i=0;i<n;i++)
	{
		printf("please input the num:");
		scanf("%d",&s[i].num);
		printf("please input the name:");
		scanf("%s",&s[i].name);
        printf("please input the sex:");   
	    flushall();
		scanf("%c",&s[i].sex);
        printf("please input the score:");
		for(j=0;j<4;j++)
		{
			scanf("%d",&s[i].score[j]);
		}
	}
}
void average(struct student s[],int n)
{
	int i,j,sum;
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=0;j<4;j++)
		{
			sum+=s[i].score[j];
			s[i].aver=sum/4.0;
		}
	}
}
void sort(struct student s[],int n)
{
	int i,j;
	struct student t;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(s[j].aver<s[i].aver)
			{
				t=s[j];
				s[j]=s[i];
				s[i]=t;
			}
		}
	}
}
void output(struct student s[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%-5d%s\t%c\t%4.2f\n",s[i].num,s[i].name,s[i].sex,s[i].aver);
	}
}
int main()
{
	int *s,n;
	printf("please input numbers:\n");
	scanf("%d",&n);
	s=(int *)malloc(n*sizeof(int));
	input(s,n);
	average(s,n);
	sort(s,n);
	output(s,n);
}