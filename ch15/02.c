/******************************Chapter 15 Exercise********************************/
//#2
//编写一个程序，通过命令行参数读取两个二进制字符串，对这两个二进制数使用~ & | ^ 运算符。
//并以二进制字符串形式打印结果.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define BINSIZE 40

int parsebinarystring(char *str);
char * tobinarystring(int n, char *str, int strlen);

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        puts("command line arguments error!!!");
        exit(EXIT_FAILURE);
    }

    int m =0, n = 0;
    m = parsebinarystring(argv[1]);
    n = parsebinarystring(argv[2]);
    int strlen = sizeof(int)*CHAR_BIT+1;
    char binarystring[strlen];
    printf("binarystr1: %s = %d\n", argv[1], m);
    printf("binarystr2: %s = %d\n", argv[2], n);

    printf("~%s = %s.\n", argv[1], tobinarystring(~m, binarystring, strlen));
    printf("~%s = %s.\n", argv[2], tobinarystring(~n, binarystring, strlen));

    printf("%s & %s = %s.\n", argv[1], argv[2], tobinarystring(m&n, binarystring, strlen));
    printf("%s | %s = %s.\n", argv[1], argv[2], tobinarystring(m|n, binarystring, strlen));
    printf("%s ^ %s = %s.\n", argv[1], argv[2], tobinarystring(m^n, binarystring, strlen));

    return 0;
}

int parsebinarystring(char *str)
{
    int str_length = strlen(str);
    int i = 0;
    int retval = 0;
    while( i < str_length)
    {
        retval |= ((str[i] - '0') << (str_length-i-1));
        i++;
    }
    return retval;
}

char * tobinarystring(int n, char *str, int strlen)
{
    for(int i = strlen+1; i >= 0; i--)
    {
        str[i] = '0' + (n & 0x01);
        n>>=1;
    }
    return str;
}
