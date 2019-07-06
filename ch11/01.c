/******************Chapter 11 Exercise********************/
//#01
//设计一个函数，从输入中获取n个字符，把结果储存在一个数组里。
//它的地址北传递作为一个参数
#include <stdio.h>
#include <string.h>
#define SIZE 20
char * getnchar(char * array, int n);

int main(void)
{
	char input[SIZE];
	
	getnchar(input, SIZE);
	
	puts(input);

	puts("Bye!");
	return 0;
}

char * getnchar(char * array, int n)
{
	//从input获取n个字符，存在array中
	char ch;
	for(int i = 0; i < n; i++)
	{
		if((ch = getchar()) == EOF)
			break;
		*(array+i) = ch;
	}
	return array;
}
