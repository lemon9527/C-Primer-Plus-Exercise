//#1
//编写一个程序，读取输入，读到字符‘#’停止，然后报告读取的空格数，换行符数和所有其它字符的数量
#include <stdio.h>

int main(void)
{
	char ch;
	int space_ct, line_break_ct, other_ct;
	space_ct = line_break_ct = other_ct = 0;

	const char space = ' ';
	const char line_break = '\n';


	printf("Enter some text, enter '#' to quit.\n");

	while((ch=getchar())!='#')
	{
		switch(ch)
		{
			case space:
				space_ct++;
				break;
			case line_break:
				line_break_ct++;
				break;
			default:
				other_ct++;
				break;
		}
	}
	printf("number of space line_break   other_char\n");
	printf("          %4d %8d %8d\n", space_ct, line_break_ct, other_ct);

	return 0;
}
