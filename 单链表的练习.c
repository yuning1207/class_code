#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *create_list(void);//���� 
void traver_list(NODE *phead);//������� 
NODE *add_node(NODE *phead);//ͷ�� 

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
		printf("����ʧ�ܣ�������ֹ��\n");
		exit(-1);
	}
	//q->next=NULL;
	printf("��������Ҫ����Ľڵ��ֵ��\n");
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
		printf("����ʧ�ܣ�������ֹ��\n");
		exit(-1);
	}
	NODE *ptail=phead;
	ptail->next=NULL;
	printf("�����������Ľڵ������");
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		printf("�������%d���ڵ������:",i+1);
		scanf("%d",&val);
		NODE *pnew=(NODE*)malloc(sizeof(NODE));
        if(pnew==NULL)
		{
			printf("����ʧ�ܣ�������ֹ��\n");
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