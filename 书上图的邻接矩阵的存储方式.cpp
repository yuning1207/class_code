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

void creat(AdjMatrix * G);//创建无向网 

void creat(AdjMatrix * G)
{
	int weight,vex1,vex2,i,j;
	printf("输入无向网中的顶点个数和边数：");
	scanf("%d %d",&G->vexnum,&G->arcnum);
	for(i=0;i<G->vexnum;i++)
	{
		for(j=0;j<G->vexnum;j++)
		{
			G->arcs[i][j]=infinty;//如果不是网，是图，则赋值为0 
		}
	}
	printf("请输入无向网中%d个顶点：",G->vexnum);
	for(i=0;i<G->vexnum;i++)
	{
		printf("NO.%d个顶点：",i+1);
		fflush(stdin);
		scanf("%c",&G->vex[i]);
	}
	printf("请输入无向网中%d条边：\n",G->arcnum);
	for(i=0;i<G->arcnum;i++)
	{
		printf("NO.%d条边： 顶点",i+1);
		scanf("%d",&vex1);
		printf("                 <--->顶点");
		scanf("%d",&vex2);
		printf("                           权值：");
		scanf("%d",&weight);
		G->arcs[vex1][vex2]=weight;//若不是网，则赋值为1 
		G->arcs[vex2][vex1]=weight;//若是有向网，则删掉此句 
	}
}
int main(void)
{
	AdjMatrix *G;
	G=(AdjMatrix *)malloc(sizeof(AdjMatrix));
	creat(G);
	return 0;
}