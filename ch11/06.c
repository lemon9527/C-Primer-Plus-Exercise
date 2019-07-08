/******************Chapter 11 Exercise********************/
//06.c
//编写一个is_within()的函数，接受一个字符和一个指向字符串的指针作为两个函数
//的形参。如果指定字符在字符串中，该函数返回一个非零值，否则返回0
//使用一个循环给函数提供输入值
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define SIZE 81
int is_within(char ch, char * str);
char * s_gets(char * st, int n);

int main(void)
{
    char ch;
    char sourcestring[81];
    puts("Enter some text:");
    s_gets(sourcestring, SIZE);
    puts("Enter a letter:");
    while((ch = getchar())!= EOF && isalpha(ch))
    {
        if(is_within(ch, sourcestring))
            printf("%c is in %s\n", ch, sourcestring);
        else
            printf("%c is not in %s\n", ch, sourcestring);
        puts("Enter some text:");
        s_gets(sourcestring, SIZE);
        puts("Enter a letter:");
    }

    puts("Bye.");

    return 0;
}

int is_within(char ch, char * str)
{
    bool instring = 0;
    int i = 0;
    for(i = 0; i< strlen(str); i++)
    {
        if(str[i] == ch)
        {
            instring = true;
            break;
        }
    }
    return instring;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        while(st[i] != '\n' && st[i] != '\0')
            i++;
        if(st[i] == '\n')
            st[i] = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}
