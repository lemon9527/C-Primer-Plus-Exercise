/******************Chapter 13 Exercise********************/
//01
//改写程序13.1, 要求提示输入文件名，并读取用户输入的信息，不使用命令行参数
#include <stdio.h>
#include <stdlib.h>
#define SLEN 41

void get(char * string, int n);

int main(void)
{
    int ch;    //读取文件时，存储每个字符的地方
    FILE *fp;   //文件指针
    unsigned char filename[SLEN];
    unsigned long count = 0;

    puts("Enter the file name: ");
    get(filename, SLEN);

    if((fp=fopen(filename, "r"))== NULL)
    {
        printf("Could not open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    while((ch=getc(fp))!=EOF)
    {
        putc(ch, stdout);   //与putchar(ch)相同
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters.\n", filename, count);

    return 0;
}

void get(char * string, int n)
{
    //wrapper for fgets() -read from stdin and replace
    //first newline with null character, 回车换成空字符
    //因为fgets()保留了换行符
    fgets(string, n, stdin);

    while(*string !='\0')
    {
        if(*string == '\n')
        {
            *string = '\0';
            break;
        }
        string++;
    }
}
