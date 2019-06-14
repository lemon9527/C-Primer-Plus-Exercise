//#4
//用if else语句编写一个程序，读取输入，读到#停止。用感叹号替换句号，用两个感叹号替换原本的感叹号。
//最后报告进行了多少次替换
#include <stdio.h>
#define STOP '#'

int main(void)
{
	int replace_times = 0;
	char ch;

	printf("Enter some text with . and !.\n");
	printf("# to quit.\n");

	while((ch=getchar()) != STOP)
	{
		if(ch == '.')
		{
			printf("!");
			replace_times++;
		}
		else if(ch == '!')
		{
			printf("!!");
			replace_times++;
		}
		else
			printf("%c", ch);
	}
	printf("\nTotal replace %d times.\n", replace_times);
	return 0;
}
