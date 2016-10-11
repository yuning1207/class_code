#include <stdio.h>
typedef struct student
{
	char name[21];
	char num[9];
	float score;	
}stu;
stu st[100];
void save(stu * p,int people);
int read(stu *  p);
int main(void)
{
	int i;
	int people;
	printf("请输入有多少学生：\n");
	scanf("%d",&people);
	for(int i=0;i<people;i++)
	{
		printf("请输入第%d个学生的姓名 学号 成绩：\n",i+1);
		scanf("%s %s %f",st[i].name,st[i].num,&st[i].score);
	}
	save(st,people);
	stu x[100];
	people=read(x);
	for(int i=0;i<people;i++)
	{
		printf("%s %s %f\n",st[i].name,st[i].num,st[i].score);
	}
	return 0;
}

void save(stu *p, int people)
{
	FILE * fp;
	int i;
	fp=fopen("stu1.txt","a");
	for(i=0;i<people;i++)
	{
		fprintf(fp,"%s %s %f\n",p[i].name,p[i].num,p[i].score);	
	}	
	fclose(fp);
	return;
}

int read(stu *p)
{
	FILE * fp;
	int i=0;
	fp=fopen("stu1.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %f\n",p[i].name,p[i].num,&p[i].score);
		i++;
	}
	fclose(fp);
	return i;		
}