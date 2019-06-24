//07.c
//从标准输入读取字符，直到文件结尾。程序要报告每个字符是否是字母。
//如果是，要报告该字母在字母表中的数值位置。例如c/C位置都是3.
//编写一个函数，函数以字符为参数。字母则返回数值位置。否则返回-1
#include <stdio.h>
#include <ctype.h>

int location(char ch);

int main(void)
{
	char ch;
	int num;

	printf("Enter some text.\n");
	while((ch=getchar())!=EOF)
	{
		if((num=location(ch))>=0)
			printf("%c location in alphabet is %d.\n", ch, num);
		else
			printf("%c is not in alphabet.\n", ch);

	}

	printf("Bye.\n");
	return 0;
}

int location(char ch)
{
	if(isalpha(ch))
    {
        //change to upper case
        ch = toupper(ch);
        return (ch-'A'+1);
    }
    else
        return -1;
}
