//#02 编写一个程序，在遇到EOF前，把输入作为字符流读取，程序要打印每个输入的字符及其
//相对应的ASCII 十进制。 注意处理非打印字符(空格之前的字符为非打印字符)
#include <stdio.h>

int main(void)
{
	char ch;
	int char_count = 0;

	printf("Enter some text.\n");
	while((ch=getchar()) != EOF)
	{
		if(ch>=' ')
			printf("\'%c\':  %3d", ch, ch);
		else if(ch == '\n')
			printf("\'\\n\': %3d", ch);
		else if(ch == '\t')
			printf("\'\\t\': %3d", ch);
		else //ascii 控制字符
			printf("\'^%c\': %3d", ch+64, ch);

		char_count++;
		if(char_count%10 == 0)
			printf("\n");
		else
			printf("   ");

	}
	printf("\n");

	return 0;
}
