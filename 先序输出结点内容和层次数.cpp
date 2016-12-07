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
void previsittree(bitnode * root,int level);//������� 

void previsittree(bitnode * root,int level)
{
	if(root)
	{
		printf("(%c,%d)",root->data,level);
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
	int level=1;
	root=(bitnode *)malloc(sizeof(bitnode));
	creatbitree(&root);
	previsittree(root,level);
	return 0;
}