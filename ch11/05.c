/******************Chapter 11 Exercise********************/
//#05
//设计并测试一个函数，搜索第一个函数行参指定的字符串，在其中查找第二个形参指定的字符
//首次出现的位置。成功则返回该字符的指针，如果在该字符串中未找到指定字符，则返回空指针。
//(同strchr()功能). 使用一个循环给函数提供输入值
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 40

char * str_chl(char * str, int ch);

int main(void)
{
	char sourcestring[SIZE] = "Hello Lemon!";
	char ch;
	char * ptr_ch;
	puts(sourcestring);
	puts("请输入一个你想查找的字符:");
	while((ch=getchar())!= EOF && isalpha(ch))
	{
		if((ptr_ch=str_chl(sourcestring, ch)) != NULL)
		{
			printf("%c address is %p\n", ch, ptr_ch);
			printf("首次出现的位置是第%ld个字符。\n", ptr_ch - sourcestring + 1);
		}
		else
			printf("%c is not in %s.\n", ch, sourcestring);
		while(getchar() != '\n')	//跳过输入行的其余部分
			continue;
		puts("请输入一个你想查找的字符:");
	}
	puts("Bye.");

}

char * str_chl(char * str, int ch)
{
	//查找ch 在str[]第一次出现的位置
	// int i = 0;
	// int ch_1st_location = 0;
	// bool instring = false;

	// while(i < strlen(str))
	// {
	// 	if(str[i] != ch)
	// 		i++;
	// 	else
	// 	{
	// 		ch_1st_location = i;
	// 		instring = true;
	// 		break;
	// 	}
	// }
	// if(instring)
	// 	return &str[ch_1st_location];
	// else
	// 	return NULL;

	while(*str != '\0')
	{
		if(*str == ch)
			return str;
		str++;
	}

	return NULL;
}
