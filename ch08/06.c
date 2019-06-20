//8.6 编写get_first()函数，让其返回读取的第一个非空白字符
#include <stdio.h>
#define SPACE ' '

char get_first(void)
{
	int ch;

	while((ch=getchar()) == SPACE);
	while(getchar()!='\n')
		continue;

	return ch;
}

int main(void)
{
    int ch;
	printf("Enter some words.\n");
	printf("You will see the first non-whitespace character ");
	printf("in the terminal:\n");

	ch = get_first();
	while(ch!= 'q')
	{
		printf("%c\n", ch);
		ch = get_first();
	}

	return 0;
}
