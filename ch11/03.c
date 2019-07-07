/******************Chapter 11 Exercise********************/
//#03
//设计并测试一个函数，从一行输入中把一个单词读入一个数组，并丢弃输入行中的其余字符
//函数应跳过第一个非空白字符前的所有空白。
//将一个单词定义为没有空白，制表符和换行符的字符序列
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #define SIZE 81
// #define SPACE 32
// #define RETURN '\n'
// #define TAB	9

// void sgetword(char * st, char * word);

// int main(void)
// {
// 	char line[SIZE];
// 	char word[SIZE];

// 	puts("Enter some text:");
// 	sgetword(line, word);
// 	printf("你的输入如下：\n");
// 	puts(line);
// 	puts("第一个单词如下:");
// 	puts(word);

// 	return 0;
// }

// void sgetword(char * st, char *word)
// {
// 	int i = 0;
// 	int start, end;

// 	fgets(st, SIZE, stdin);
// 	//跳过第一个非空白字符前的所有空白
// 	while((st[i] == SPACE || st[i] == RETURN || st[i] == TAB) && i < SIZE)
// 		i++;
// 	start = i;
// 	//找到第一个单词结尾
// 	i = 1;
// 	while((st[start+i] != SPACE && st[i] != RETURN && st[i] != TAB) && i < SIZE)
// 		i++;
// 	end = start + i;
// 	printf("Start = %d, end = %d\n", start, end);
// 	//单词从start到end
// 	for(i = 0; i < end - start; i++)
// 		word[i] = st[start + i];
// }

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 30
char * getword(char * target);

int main(void)
{
	char hello[SIZE];
	puts("Enter some text:");
	getword(hello);
	puts(hello);
}

char * getword(char * target)
{
	char ch;
	int i = 0;
	bool inword = false;

	while((ch=getchar()) != EOF)
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
