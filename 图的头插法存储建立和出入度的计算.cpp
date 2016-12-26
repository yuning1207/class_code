#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxvertex 20

typedef struct edgenode//�߱�ڵ� 
{
	char adjvex;
	int weight;
	struct edgenode * next;
} edgenode;

typedef struct vertexnode//�����ڵ� 
{
	char data;
	edgenode * firstedge;
}vertexnode;

typedef struct graphnode
{
	int vertexnum;
	int edgenum;
	vertexnode graph[maxvertex];
}graphnode;

void creatgraph(graphnode * g);//ͷ�巨����ͼ 
void sum_out_in(graphnode * g);//���㶥��ĳ��Ⱥ���� 

void sum_out_in(graphnode * g)
{
	int i,j;
	int out;
	int in;
	edgenode * p;
	for(i=0;i<g->vertexnum;i++)
	{
		out=0;
		in=0;
		for(p=g->graph[i].firstedge;p!=NULL;p=p->next)
			out++;
		for(j=0;j<g->vertexnum;j++)
		{
			for(p=g->graph[j].firstedge;p!=NULL;p=p->next)
			{
				if(p->adjvex==g->graph[i].data)
				{
					in++;
					break;
				}
			}
		}
		printf("%c %d %d\n",g->graph[i].data,out,in);
	}
}
void creatgraph(graphnode * g)
{
	int i,j;
	char v1,v2;
	edgenode * p;
	printf("������ͼ�Ķ������ͱ�����\n");
	scanf("%d %d",&g->vertexnum,&g->edgenum);
	printf("����������������Ϣ��\n");
	fflush(stdin);
	for(i=0;i<g->vertexnum;i++)
	{
		scanf("%c",&g->graph[i].data);
		g->graph[i].firstedge=NULL;
	}
	printf("��������ͨ���������㣺\n");
	for(i=0;i<g->edgenum;i++)
	{
		fflush(stdin);
		scanf("%c%c",&v1,&v2);
		p=(edgenode *)malloc(sizeof(edgenode));
		p->adjvex=v2;
		p->weight=0;
		for(j=0;j<g->vertexnum;j++)
		{
			if(v1==g->graph[j].data)
				break;
		}
		p->next=g->graph[j].firstedge;
		g->graph[j].firstedge=p;
	} 
}
int main(void)
{
	graphnode * g;
	g=(graphnode *)malloc(sizeof(graphnode));
	creatgraph(g);
	sum_out_in(g);
	return 0;
}