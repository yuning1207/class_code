#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *create_list(void);//建链 
void traver_list(NODE *phead);//输出链表 
NODE *add_node(NODE *phead);//头插 

int main()
{
	NODE *phead=NULL;
	phead=create_list();
	traver_list(phead);
	phead=add_node(phead);
	traver_list(phead);
}

NODE *add_node(NODE *phead)
{
	NODE * q;
	q=(NODE *)malloc(sizeof(NODE));
	if(q==NULL)
	{
		printf("分配失败，程序终止！\n");
		exit(-1);
	}
	//q->next=NULL;
	printf("请输入需要插入的节点的值：\n");
	scanf("%d",&q->data);
	q->next=phead->next;
	phead->next=q;
	return phead;
}
NODE *create_list(void)
{
	int len,val,i;
	NODE *phead;
	phead=(NODE *)malloc(sizeof(NODE));
	if(phead==NULL)
	{
		printf("分配失败，程序终止！\n");
		exit(-1);
	}
	NODE *ptail=phead;
	ptail->next=NULL;
	printf("请输入该链表的节点个数：");
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		printf("请输入第%d个节点的数据:",i+1);
		scanf("%d",&val);
		NODE *pnew=(NODE*)malloc(sizeof(NODE));
        if(pnew==NULL)
		{
			printf("分配失败，程序终止！\n");
		    exit(-1);
		}
		pnew->data=val;
		ptail->next=pnew;
		pnew->next=NULL;
		ptail=pnew;
	}
	return phead;
}

void traver_list(NODE *phead)
{
	NODE *p;
	p=phead->next;
	while(p!=NULL)
	{
		printf("%-5d",p->data);
		p=p->next;
	}
	printf("\n");
}