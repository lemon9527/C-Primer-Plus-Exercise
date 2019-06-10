//#7
//编写一个程序，读入一个单词到一个字符数组中，然后倒序打印这个单词
#include<stdio.h>
#include<string.h>

int main(void)
{
    char ch[20];
    int length;

    printf("Please enter an word:\n");
    scanf("%s",ch);

    length = strlen(ch);
    for(int i = length; i>0; i--)
    {
        printf("%c",ch[i-1]);
    }
    printf("\n");
    return 0;
}
