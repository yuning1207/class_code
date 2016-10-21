#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int num;
	int password;
	struct node *next;
}node;

node head = {0};
node *end = {0};

void createlist(int n)
{
	int *a = NULL;
	int i; 
	a = (int *)malloc(n * sizeof(int));
	node *p = &head;
	for (i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i<n; i++)
	{
		p->num = i + 1;
		p->password = a[i];
		if (i<n - 1)
		{
			p->next = (node *)malloc(sizeof(node));
			p = p->next;
		}
	}
	p->next = &head;//构成循环链表 
	end = p;//尾指针 
}

void j(int n, int password)
{
	int i = 1;
	node *q;
	node *p = end;//p指针指向密码的前一个节点，方便删除 
	while (n>0)
	{
		if (i == password)
		{
			q = p->next;
			printf("%d ", q->num);
			password = q->password;
			p->next = q->next;
			free(q); 
			n--;
			i = 1;
		}
		else {
			p = p->next;
			i++;
		}
	}
	return;

}

int main(void)
{
	int m, n;
	scanf("%d %d", &n, &m);
	createlist(n);
	j(n, m);
	return 0;
}
