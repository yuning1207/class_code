#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
	struct node * lchild;
	struct node * rchild;
}bitnode;

void creatbitree(bitnode ** root);//构建二叉树 
void outputroute(bitnode * root,char *ab,int alength);//输出叶子结点的路径 

void outputroute(bitnode * root,char *ab,int alength)
{
	int i;
	if(root)
	{
		if(root->lchild==NULL&&root->rchild==NULL)
		{
			printf("%c:",root->data);
			for(i=0;i<alength;i++)
			{
				printf("%c",ab[i]);
			}
			printf("\n");
		}
		else
		{
			ab[alength++]=root->data;
			outputroute(root->lchild,ab,alength);
			outputroute(root->rchild,ab,alength);
		}
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
	char * ab;
	int alength=0;
	ab=(char *)malloc(sizeof(char));
	root=(bitnode *)malloc(sizeof(bitnode));
	creatbitree(&root);
	outputroute(root,ab,alength);
	return 0;
}