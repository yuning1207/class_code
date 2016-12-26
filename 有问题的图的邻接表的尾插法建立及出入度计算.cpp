#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxvex 20

typedef struct arcnode
{
	char adjvex;
	int weight;
	struct arcnode * next;
}arcnode;//网的边结构

typedef struct vertexnode
{
	char vexdata;
	arcnode * firstedge;
} vertexnode;//顶点结构

typedef struct a
{
	vertexnode vertex[maxvex];//将顶点结构存储于数组中 
	int vexnum;//顶点数 
	int arcnum;//弧数 
} adjlist;

void creat(adjlist * g);//创建表 
void sum_out_in(adjlist * g);//计算各个顶点的出度和入度 

void sum_out_in(adjlist * g)
{
	int i,j;
	int out=0,in=0;
	arcnode * p;
	for(i=0;i<g->vexnum;i++)
	{
		for(p=g->vertex[i].firstedge;p!=NULL;p=p->next)
		{
			out++;
		}
		for(j=0;j<g->vexnum;j++)
		{
			for(p=g->vertex[j].firstedge;p!=NULL;p=p->next)
			{
				if(p->adjvex==g->vertex[i].vexdata)
					in++;
			}	
		}
		printf("%c %d %d\n",g->vertex[i].vexdata,out,in);
	}
} 
void creat(adjlist * g)
{
	int i,j;
	char v1,v2;
	arcnode * p;
	arcnode * q;
	printf("请输入需要构建的表的顶点数和弧数：");
	scanf("%d %d",&g->vexnum,&g->arcnum);
	printf("请输入各个顶点信息：");
	fflush(stdin);
	for(i=0;i<g->vexnum;i++)
	{
		scanf("%c",&g->vertex[i].vexdata);
		g->vertex[i].firstedge=NULL;
	}
	for(i=0;i<g->arcnum;i++)
	{
		printf("请输入连通的两个顶点：");
		fflush(stdin);
		scanf("%c%c",&v1,&v2);
		for(j=0;j<g->vexnum;j++)
		{
			if(v1==g->vertex[j].vexdata)
			{
				for(p=g->vertex[j].firstedge;p!=NULL;p=p->next);
				q=(arcnode *)malloc(sizeof(arcnode));
				q->adjvex=v2;
				q->next=NULL;
				p=q;
				break;
			}
		}
		if(j>g->vexnum)
			printf("没有找到连通的顶点！\n");
	}	                                                                                            
}
int main(void)
{
	adjlist * g;
	g=(adjlist *)malloc(sizeof(adjlist));
	creat(g);
	sum_out_in(g);
	return 0;
}