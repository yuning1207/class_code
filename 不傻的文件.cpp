#include <stdio.h>
#define len 100
typedef struct 
{
	char name[10];
	char num[18];
	float score;
}stu;
stu st[100];
void save (stu *p,int people);
int read (stu *p);
void save (stu *p,int people)
{
	FILE *fp;
	fp=fopen("stu.txt","a");	
	for(int i=0;i<people;i++)
	{
		fprintf(fp,"%s %s %f\n",p[i].name,p[i].num,p[i].score);
	}
	fclose(fp);
}
int main()
{
	int people;
	scanf("%d",&people);
	for(int i=0;i<people;i++)
	{
		scanf("%s %s %f",st[i].name,st[i].num,&st[i].score);
	}
	save(st,people);
	stu x[1000];
	people = read(x);
	for(int i=0;i<people;i++)
		printf("%s %s %.2f\n",x[i].name,x[i].num,x[i].score);
	
	return 0;
}

int read(stu *p)
{
	int i=0;
	FILE *fp;
	fp=fopen("stu.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %f\n",p[i].name,p[i].num,&p[i].score);
		i++;
	}
	fclose(fp);
	return i;
}