//#01 设计一程序，统计在读取到文件结尾之前读取的字符数
#include <stdio.h>

int main(void)
{
	int char_count =0;

	printf("Enter some text.\n");
	while(getchar()!=EOF)
		char_count++;

	printf("Total input %d characters.\n", char_count);
	return 0;
}
