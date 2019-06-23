//02.c
//设计一个函数chline(ch, i, j), 打印指定的字符　j行i列，在一个简单的驱动中测试
#include <stdio.h>

void chline(char ch, unsigned int i, unsigned int j);

int main(void)
{
	char ch;
	int column=0, line=0;

	printf("Enter a character and two integer numbers.\n");
	while(scanf("%c %d %d", &ch, &column, &line)==3)
	{
		chline(ch, column, line);
		printf("\n");

		while(getchar()!='\n') continue; //
		printf("Enter a character and two integer numbers.\n");
	}

	printf("Bye.\n");

	return 0;
}

void chline(char ch, unsigned int i, unsigned int j)
{
	for(int a = 0; a < j; a++)
	{
		for(int b = 0; b < i; b++)
			putchar(ch);
		putchar('\n');
	}
}
