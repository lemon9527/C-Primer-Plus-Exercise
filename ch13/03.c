/******************Chapter 13 Exercise********************/
//03
//编写一个文件拷贝程序，提示用户输入文件名，并以该文件名作为原始文件名和
//输出文件名，程序要使用ctype.h里的toupper()函数，把所有文本转换为大写再
//写入到输出文件，使用标准IO和文本模式

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SLEN 41

void get(char * string, int n);

int main(void)
{
    int ch;    //读取文件时，存储每个字符的地方
    FILE *fp_s;   //文件指针
    FILE *fp_d;
    unsigned char filename[SLEN];
    unsigned char newfilename[SLEN];

    puts("Enter the file name for copy: ");
    get(filename, SLEN);
    puts("Enter the new file name: ");
    get(newfilename, SLEN);

    if((fp_s=fopen(filename, "r")) == NULL)
    {
        fprintf("Could not open file \"%s\"\n", filename);
        exit(EXIT_FAILURE);
    }

    if((fp_d=fopen(newfilename, "w")) == NULL)
    {
        fprintf("Could not open file \"%s\"\n", newfilename);
        exit(EXIT_FAILURE);
    }

    while((ch=getc(fp_s))!=EOF)
    {
        ch=toupper(ch);
        putc(ch, fp_d);
    }

    fclose(fp_s);
    fclose(fp_d);
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
