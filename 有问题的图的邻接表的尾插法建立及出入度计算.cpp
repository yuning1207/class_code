#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxvex 20

typedef struct arcnode
{
	char adjvex;
	int weight;
	struct arcnode * next;
}arcnode;//���ı߽ṹ

typedef struct vertexnode
{
	char vexdata;
	arcnode * firstedge;
} vertexnode;//����ṹ

typedef struct a
{
	vertexnode vertex[maxvex];//������ṹ�洢�������� 
	int vexnum;//������ 
	int arcnum;//���� 
} adjlist;

void creat(adjlist * g);//������ 
void sum_out_in(adjlist * g);//�����������ĳ��Ⱥ���� 

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
	printf("��������Ҫ�����ı�Ķ������ͻ�����");
	scanf("%d %d",&g->vexnum,&g->arcnum);
	printf("���������������Ϣ��");
	fflush(stdin);
	for(i=0;i<g->vexnum;i++)
	{
		scanf("%c",&g->vertex[i].vexdata);
		g->vertex[i].firstedge=NULL;
	}
	for(i=0;i<g->arcnum;i++)
	{
		printf("��������ͨ���������㣺");
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
			printf("û���ҵ���ͨ�Ķ��㣡\n");
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