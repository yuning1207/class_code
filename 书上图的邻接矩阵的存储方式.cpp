#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxvex 20
#define infinty 32767

typedef struct node
{
	int arcs[maxvex][maxvex];
	char vex[maxvex];
	int vexnum;
	int arcnum;
} AdjMatrix;

void creat(AdjMatrix * G);//���������� 

void creat(AdjMatrix * G)
{
	int weight,vex1,vex2,i,j;
	printf("�����������еĶ�������ͱ�����");
	scanf("%d %d",&G->vexnum,&G->arcnum);
	for(i=0;i<G->vexnum;i++)
	{
		for(j=0;j<G->vexnum;j++)
		{
			G->arcs[i][j]=infinty;//�������������ͼ����ֵΪ0 
		}
	}
	printf("��������������%d�����㣺",G->vexnum);
	for(i=0;i<G->vexnum;i++)
	{
		printf("NO.%d�����㣺",i+1);
		fflush(stdin);
		scanf("%c",&G->vex[i]);
	}
	printf("��������������%d���ߣ�\n",G->arcnum);
	for(i=0;i<G->arcnum;i++)
	{
		printf("NO.%d���ߣ� ����",i+1);
		scanf("%d",&vex1);
		printf("                 <--->����");
		scanf("%d",&vex2);
		printf("                           Ȩֵ��");
		scanf("%d",&weight);
		G->arcs[vex1][vex2]=weight;//������������ֵΪ1 
		G->arcs[vex2][vex1]=weight;//��������������ɾ���˾� 
	}
}
int main(void)
{
	AdjMatrix *G;
	G=(AdjMatrix *)malloc(sizeof(AdjMatrix));
	creat(G);
	return 0;
}