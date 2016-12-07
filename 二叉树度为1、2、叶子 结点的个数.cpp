#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
	struct node * lchild;
	struct node * rchild;
}bitnode;

void creatbitree(bitnode ** root);//���������� 
int leaf(bitnode * root);//�������Ҷ�ӽ����� 
int one(bitnode * root);//��Ϊһ�Ľ����� 
int two(bitnode * root);//��Ϊ���Ľ����� 
void visitleaf(bitnode * root);//���Ҷ�ӽ�� 
int m=0,n=0;

void visitleaf(bitnode * root)
{
	if(root)
	{
		if(root->lchild==NULL&&root->rchild==NULL)
			printf("%c",root->data);
		visitleaf(root->lchild);
		visitleaf(root->rchild);
	}
}
int two(bitnode * root)
{
	if(root==NULL)
		return 0;
	else if(root->lchild&&root->rchild)
	{
		n+=1;
	}	
	two(root->lchild);
	two(root->rchild);
}
int one(bitnode * root)
{
	if(root==NULL)
		return 0;
	else if(root->lchild==NULL&&root->rchild==NULL)
		return 0;
	else if(root->lchild==NULL||root->rchild==NULL)
		m+=1;
	one(root->lchild);
	one(root->rchild);
}
int leaf(bitnode * root)
{
	int n1,n2;
	if(root==NULL)
		return 0;
	if(root->lchild==NULL&&root->rchild==NULL)
		return 1;
	n1=leaf(root->lchild);
	n2=leaf(root->rchild);
	return (n1+n2);
}
void creatbitree(bitnode ** root)
{
	char ch;
	ch=getchar();
	if(ch=='#')
		*root=NULL;
	else
	{
		(*root)=(bitnode *)malloc(sizeof(bitnode));
		if(*root==NULL)
			exit(-1);
		(*root)->data=ch; 
		creatbitree(&((*root)->lchild));
		creatbitree(&((*root)->rchild));
	} 
}
int main(void)
{
	int a,b,c;
	bitnode * root;
	root=(bitnode *)malloc(sizeof(bitnode));
	creatbitree(&root);
	a=leaf(root);
	b=one(root);
	c=two(root);
	printf("%d %d %d\n",a,m,n);
	visitleaf(root);
	return 0;
}