#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{
	int data;
	struct node * lchild;
	struct node * rchild;
} bitnode;

void visit(int data);//访问该结点的数据
void preorder(bitnode * root); //非递归实现先序遍历 
void inorder(bitnode * root);//非递归实现中序遍历 
void postorder(bitnode * root);//非递归实现后序遍历
void levelorder(bitnode * root);//非递归实现层次遍历 

void levelorder(bitnode * root)
{
	seqqueue * s;
	bitnode * p;
	initqueue(s);
	enterqueue(s,root);
	while(!isempty(s))
	{
		deletequeue(s,&p);
		visit(p->data);
		if(p->lchild!=NULL)
		{
			enterqueue(s,p->lchild);
		}
		if(p->rchild!=NULL)
		{
			enterqueue(s,p->rchild);
		}
	}
}
void postorder(bitnode * root)
{
	seqstack * s;
	bitnode * p;
	bitnode * q;
	initstack(s);
	p=root;
	q=NULL;
	while(p!=NULL||!isemoty(s))
	{
		while(p!=NULL)
		{
			push(s,p);
			p=p->lchild;
		}
		if(!isempty(s))
		{
			top(s,&p);
			if(p->rchild==NULL||p->rchild==q)
			{
				pop(s,p);
				visit(p->data);
				q=p;
				p=NULL;
			}
			else
				p=p->rchild;
		}
	}
}
void inorder(bitnode * root)
{
	seqstack * s;
	initstack(s);
	bitnode * p;
	p=root;
	while(p!=NULL||!isempty(s))
	{
		while(p!=NULL)
		{
			push(s,p);
			p=p->lchild;
		}
		if(!isempty(s))
		{
			pop(s,&p);
			visit(p->data);
			p=p->rchild;
		}
	}
}
void preorder(bitnode * root)
{
	seqstack * s;
	bitnode * p;
	initstack(s);
	p=root;
	while(p!=NULL||!isempty(s))
	{
		while(p!=NULL)
		{
			visit(p->data);
			push(s,p);
			p=p->lchild;
		}
		if(!empty(s))
		{
			pop(s,&p);
			p=p->rchild;
		}
	}
}
void visit(int data)
{
	printf("%d ",data);
} 
int main(void)
{
	bitnode * root;
	root=(bitnode *)malloc(sizeof(bitnode));
	preorder(root);
	inorder(root);
	postorder(root);
	return 0;
}