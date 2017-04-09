#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct olnode
{
	int row;
	int col;
	int value;
	struct olnode * right;
	struct olnode * down;
}olnode; 

typedef struct b
{
	olnode ** rowhead;   
	olnode ** colhead;
	int rows;
	int cols;
	int num;
}crosslist;

int initcrosslist(crosslist * m);

int initcrosslist(crosslist * m)
{
	int rows,cols,num,k;
	int flag;
	int row,col,value;
	olnode *p,*q;
	if(!(m->rowhead))
	{
		printf("无法生成十字链表！");
		return 0;
	}
	do
	{
		flag=0;
		printf("输入需要创建的矩阵的行数、列数和非零元素的个数。\n");
		scanf("%d%d%d",&rows,&cols,&num);
		if(rows<0||cols<0||num<0)
			flag=1;
	}while(flag);
	m->rows=rows;
	m->cols=cols;
	m->num=num;
	m->rowhead=(olnode **)malloc((rows+1)*sizeof(olnode *));
	if(!(m->rowhead))
		exit(-1);
	m->colhead=(olnode **)malloc((cols+1)*sizeof(olnode *));
	if(!(m->colhead))
		exit(-1);
	for(k=1;k<=rows;k++)
		m->rowhead[k]=NULL;
	for(k=1;k<=cols;k++)
		m->colhead[k]=NULL;
	for(k=1;k<=num;k++)
	{
		int row,col,value,flag;
		do
		{
			flag=0;
			printf("输入第%d个节点的行号、列号以及值。\n",k);
			scanf("%d%d%d",&row,&col,&value);
			if(row<0||col<0)
				flag=1;
		}while(flag);
		p=(olnode *)malloc(sizeof(olnode));
		if(p==NULL)
			exit(-1);
		p->row=row;
		p->col=col;
		p->value=value;
		if(m->rowhead[row]==NULL||m->rowhead[row]->col>col)
		{
			p->right=m->rowhead[row];
			m->rowhead[row]=p;
		}
		else
		{
			for(q=m->rowhead[row];q->right&&q->right->col<col;q=q->right);
			p->right=q->right;
			q->right=p;
		}
		if(m->colhead[col]==NULL||m->colhead[col]->col>col)
		{
			p->down=m->colhead[col];
			m->colhead[col]=p;
		}
		else
		{
			for(q=m->colhead[col];q->down&&q->down->row<row;q=q->down);
			p->down=q->down;
			q->down=p;
		}
	}
	return 1; 
}
int main(void)
{
	crosslist * m;
	m=(crosslist *)malloc(sizeof(crosslist));
	initcrosslist(m);
	return 0;
}