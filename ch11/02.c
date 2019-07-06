/******************Chapter 11 Exercise********************/
//#02
//修改练习1的函数，n个字符后停止，或在读到第一个空白，制表符，换行符时停止
#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
	// for(int i = 0; i < n; i++)
	// {
	// 	ch = getchar();
	// 	if(ch == EOF || ch == '\0' || ch == '\n' || ch == 9)
	// 		break;
	// 	*(array+i) = ch;
	// }
	int i = 0;
	while((ch = getchar()) != EOF && ch != '\n' && ch !=9 && !isspace(ch) && i < n)
	{
		*(array+i) = ch;
		i++;
	}
	return array;
}
