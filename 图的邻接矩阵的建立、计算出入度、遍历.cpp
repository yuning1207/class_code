#include <stdio.h>
#include <stdlib.h>
#define maxvertex 20

typedef struct graphnode
{
	int numver;
	int numedge;
	char vexs[maxvertex];
	int edges[maxvertex][maxvertex];
} graphnode;

typedef struct queue
{
	char data[maxvertex];
	int front;
	int rear;
}csequeue;

int visited[maxvertex];

void creat_graph(graphnode * g);//邻接矩阵创建网 
void dfstraval(graphnode * g);//邻接矩阵的深度遍历操作
void dfs(graphnode * g,int i);//深度遍历 
void bfs(graphnode * g);//广度优先遍历操作 
int emptycsequeue(csequeue * q);//判队空 
int fullcsequeue(csequeue * q);//判队满 
int incsequeue(csequeue * q,int x);//入队
int outcsequeue(csequeue * q,int * x);//出队 
void sum_out_in(graphnode * g);//计算出入度 

void sum_out_in(graphnode * g)
{
	int i,out,in,j;
	for(i=0;i<g->numver;i++)
	{
		out=0;
		in=0;
		for(j=0;j<g->numver;j++)
			if(g->edges[i][j]==1)
				out++;
		for(j=0;j<g->numver;j++)
			if(g->edges[j][i]==1)
				in++;
		printf("%c %d %d\n",g->vexs[i],out,in);
	}
} 
int outcsequeue(csequeue * q,int * x)
{
	if(emptycsequeue(q))
		return 0;
	else
	{
		q->front=(q->front+1)%maxvertex;
		* x=q->data[q->front];
		return 1;
	}
}
int incsequeue(csequeue * q,int x)
{
	if(fullcsequeue(q))
		return 0;
	else
	{
		q->rear=(q->rear+1)%maxvertex;
		q->data[q->rear]=x;
		return 1;
	}
}
int fullcsequeue(csequeue * q)
{
	if((q->rear+1)%maxvertex==q->front)
		return 1;
	else
		return 0;
}
int emptycsequeue(csequeue * q)
{
	if(q->front==q->rear)
		return 1;
	else
		return 0;
}
void bfs(graphnode * g)
{
	int i,j;
	csequeue * q;
	q=(csequeue *)malloc(sizeof(csequeue));
	q->front=q->rear=maxvertex-1;
	for(i=0;i<g->numver;i++)
		visited[i]=0;
	for(i=0;i<g->numver;i++)
	{
		if(!visited[i])
		{
			visited[i]=1;
			printf("%c",g->vexs[i]);
			incsequeue(q,i);
			while(!emptycsequeue(q))
			{
				outcsequeue(q,&i);
				for(j=0;j<g->numver;j++)
				{
					if(g->edges[i][j]==1&&!visited[j])
					{
						visited[j]=1;
						printf("%c",g->vexs[j]);
						incsequeue(q,j);
					}
				}
			}
		}
	}
}
void dfs(graphnode * g,int i)
{
	int j;
	visited[i]=1;
	printf("%c",g->vexs[i]);
	for(j=0;j<g->numver;j++)
	{
		if(!visited[j]&&g->edges[i][j]==1)
			dfs(g,j);
	}
}
void dfstraval(graphnode * g)
{
	int i;
	for(i=0;i<g->numver;i++)
		visited[i]=0;
	for(i=0;i<g->numver;i++)
	{
		if(!visited[i])
		dfs(g,i);
	}
	printf("\n");
} 
void creat_graph(graphnode * g)
{
	int i,j,x,y;
	char v1,v2; 
	char ch[100]; 
	//printf("请输入顶点数和边数：\n");
	scanf("%d %d",&g->numver,&g->numedge);
	//printf("请输入各个顶点的信息：\n");
	scanf("%s",ch);
	for(i=0;i<g->numver;i++)
	{
		g->vexs[i]=ch[i]; 
	} 
	//printf("请输入有连通的顶点的下标：\n");
	for(i=0;i<g->numedge;i++)
	{
		scanf("%s",ch);
		v1=ch[0];
		v2=ch[1];
		for(j=0;j<g->numver;j++)
			if(g->vexs[j]==v1)
				x=j;
		for(j=0;j<g->numver;j++)
			if(g->vexs[j]==v2)
				y=j;
	 	g->edges[x][y]=1;
	}
} 
int main(void)
{
	graphnode * g;
	g=(graphnode *)malloc(sizeof(graphnode));
	creat_graph(g);
	sum_out_in(g);
	dfstraval(g);
	bfs(g);
	return 0;
}