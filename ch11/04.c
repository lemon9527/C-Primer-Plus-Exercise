/******************Chapter 11 Exercise********************/
//#04
//同上练习3，它接受第二个参数指明可读取的最大字符数 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 30
char * getword(char * target, int n);

int main(void)
{
	char hello[SIZE];
	puts("Enter some text:");
	getword(hello, SIZE);
	puts(hello);
}

char * getword(char * target, int n)
{
	char ch;
	int i = 0;
	bool inword = false;

	while((ch=getchar()) != EOF && i < n)
	{
		//清除第一个非空白字符前的空白字符
		if(isspace(ch))
		{
			if(inword)	//第一个单词结束，退出while loop
				break;
			else
				continue; //跳过开头的空白字符
		}

		//这里既是从第一个非空白字符开始，inword置1
		if(!inword)
			inword = true;
		*(target+i) = ch;
		i++;
	}
	//清除输入缓冲区的内容
	if(ch != '\n')
		while((ch=getchar())!= '\n')
			continue;
	return target;
}
