#define len 100
#include <stdio.h>
char filename[len];
void save(void);
void read(void);
void read(void)
{
	char c;
	FILE *fp;
	fp=fopen(filename,"r");
	while(!feof(fp))
	{
		c=fgetc(fp);
		printf("%c",c);
	}			
	fclose(fp);
}
void save(void)
{
	FILE *fp;
	scanf("%s",filename);
	getchar();
	fp=fopen(filename,"w");
	char c;
	while((c=getchar())!='0'&&c!='EOF')
	{
		fputc(c,fp);
	}
	fclose(fp);
	return;
}

int main(void)
{
	save();
	read();
	return 0;
} 