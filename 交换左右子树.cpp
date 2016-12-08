#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
	struct node * lchild;
	struct node * rchild;
}bitnode;

void creatbitree(bitnode ** root);//建立二叉树 
void swapbitree(bitnode * root);//交换二叉树的左右子树 
void visit(char data);//输出结点的数据域 
void preorder(bitnode * root);//先序遍历二叉树 
void inorder(bitnode * root);//中序遍历二叉树 
void postorder(bitnode * root);//后序遍历二叉树

void postorder(bitnode * root)
{
	if(root)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		visit(root->data);
	}
} 
void inorder(bitnode * root)
{
	if(root)
	{
		inorder(root->lchild);
		visit(root->data);
		inorder(root->rchild);
	}
}
void preorder(bitnode * root)
{
	if(root)
	{
		visit(root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
void visit(char data)
{
	printf("%c",data);
} 

void swapbitree(bitnode * root)
{
	char t;
	bitnode * a;
	if(root&&(root->lchild||root->rchild))
	{
		if(root->lchild!=NULL&&root->rchild!=NULL)
		{
			a=root->lchild;
			root->lchild=root->rchild;
			root->rchild=a;
		}
		else if(root->lchild==NULL&&root->rchild!=NULL)
		{
			root->lchild=root->rchild;
			root->rchild=NULL;
		}
		else
		{
			root->rchild=root->lchild;
			root->lchild=NULL;
		}
		swapbitree(root->lchild);
		swapbitree(root->rchild); 
	}
} 
void creatbitree(bitnode ** root)
{
	char ch;
	ch=getchar();
	if(ch=='#')
		(*root)=NULL;
	else
		{
			(*root)=(bitnode *)malloc(sizeof(bitnode));
			if((*root)==NULL)
				exit(-1);
			(*root)->data=ch;
			creatbitree(&(*root)->lchild);
			creatbitree(&(*root)->rchild);
		}
} 
int main(void)
{
	bitnode * root;
	root=(bitnode *)malloc(sizeof(bitnode));
	creatbitree(&root);
	swapbitree(root);
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	return 0;
}