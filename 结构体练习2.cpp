 #define len 3
 #include <stdio.h>
 typedef struct student
 {
 	char name[21];
 	char num[9];
 	double score[3];
 	double sum;
 }stu;
 stu st[len];
 void sort(stu *p);
 void output(stu *p);
 void output(stu *p)
 {
 	int i;
 	for(i=0;i<len;i++)
 	{
	 	printf("%s\t%s\t%lf\n",p[i].name,p[i].num,p[i].sum);
	 }
	 return;
 }
 void sort(stu *p)
 {
 	int i,j;
 	stu t;
 	for(i=0;i<len-1;i++)
 	{
	 	for(j=i+1;j<len;j++)
	 	{
		 	if(p[i].sum<p[j].sum)
			 {
			 	 t=p[i];
				 p[i]=p[j];
				 p[j]=t;			
 			}	 		
	 	}
	 }
 	return;
 }
 int main()
 {
 	int i,j;
 	float sum1=0;
	for(i=0;i<len;i++)
	{
		printf("�������%d��ѧ����������",i+1);
		scanf("%s",st[i].name);
		printf("�������%d��ѧ����ѧ�ţ�",i+1);
		scanf("%s",st[i].num);
		printf("�������%d��ѧ���ķ�����",i+1);
		for(j=0;j<3;j++)
		{
			scanf("%lf",&st[i].score[j]);
			sum1+=st[i].score[j];	
		}
		st[i].sum=sum1;
		sum1=0;				
	} 
	sort(st);
	output(st);
 	return 0;
 }