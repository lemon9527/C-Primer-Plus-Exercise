//#2
//编写一个程序，读取输入，读到字符'#'停止，程序要打印每个输入的字符及其对应的ASCII码(十进制)，一行打印8个字符
//。建议使用字符计数和求模运算符%
#include <stdio.h>
#define STOP '#'

int main(void)
{
	char ch;
	int count = 0;

	printf("Enter some text, enter '#' to quit.\n");

	while((ch=getchar())!= STOP)
	{
		if(count%8!=0)
		{
			printf("%c  %3d  ", ch, ch);
		}
		else
		{
			printf("\n%c  %3d  ", ch, ch);
		}
		count++;
	}

	printf("\nDone!\n");
	return 0;
}
