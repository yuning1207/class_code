#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct node 
{
	char data;
	struct node * lchild;
	struct node * rchild;
	int level;
}bitnode;
 
int n=0;
void creatbitree(bitnode ** root);//创建二叉树 
void preorder(bitnode * root);//先序遍历 
 
void preorder(bitnode * root,int x)
{
	if(root)
	{
		if(root->level==x)
		{
			if(root->lchild==NULL&&root->rchild==NULL)
				n++; 
		}
		preorder(root->lchild,x);
		preorder(root->rchild,x);
	}
} 
 
void previsittree(bitnode * root,int level)
{
	if(root)
	{
		root->level=level;
		previsittree(root->lchild,level+1);
		previsittree(root->rchild,level+1);	
	}
}
void creatbitree(bitnode ** root)
{
	char ch;
	ch=getchar();
	if(ch=='#')
		* root=NULL;
	else
	{
		*root=(bitnode *)malloc(sizeof(bitnode));
		if(*root==NULL)
			exit(-1);
		(*root)->data=ch;
		creatbitree(&((*root)->lchild));
		creatbitree(&((*root)->rchild));
	}
} 
int main(void)
{
	bitnode * root;
	int x;
	root=(bitnode *)malloc(sizeof(bitnode));
	creatbitree(&root);
	scanf("%d",&x);
	previsittree(root,1);
	preorder(root,x);
 	printf("%d",n); 
	return 0;
}