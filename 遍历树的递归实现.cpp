#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
	struct node * lchild;
	struct node * rchild;
} bitnode;

void visit(int data);//访问该结点 
void preorder(bitnode * root);//递归实现先序遍历 
void inorder(bitnode * root);//递归实现中序遍历 
void postorder(bitnode * root);//递归实现后序遍历 

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
void visit(int data)
{
	printf("%d ",data);
}
int main (void)
{
	bitnode * root;
	root=(bitnode *)malloc(sizeof(bitnode));
	preorder(root);
	inorder(root);
	postorder(root);
	return 0;
}