//#6
//编写程序读取输入，读到#停止，报告ei出现的次数
//该程序要记录前一个字符和当前字符， 用Receive your eieio award这样的输入来测试
#include <stdio.h>
#include <ctype.h>
#define STOP '#'

int main(void)
{
	int ei_show_times = 0;
	char ch, pre_ch;

	printf("Enter some text, q to quit.\n");

	while((ch=getchar()) != STOP)
	{
		ch = tolower(ch);
		if(ch == 'e')
		{
			pre_ch = ch;
		}
		else if(ch != 'i')
		{
			pre_ch = 0;
		}
		else
		{
			if(pre_ch == 'e')
				ei_show_times++;
		}
	}
	printf("ei_show_times = %d\n", ei_show_times);
	return 0;
}
