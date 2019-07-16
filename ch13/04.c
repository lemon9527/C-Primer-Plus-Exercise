/******************Chapter 13 Exercise********************/
//04
//编写一个程序，按顺序在屏幕上显示命令行中列出的所有文件，使用argc循环控制
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[])
{
    int i = 1;
    int ch; //读取文件时，存储每个字符的地方
    FILE * file;

    if(argc == 1)
    {
        printf("Usage: %s file1 file2 ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    while(i < argc)
    {
        //设置源文件
        if((file = fopen(argv[i], "rb")) == NULL)
        {
            fprintf(stderr, "Could not open the file \"%s\"\n", argv[i]);
            exit(EXIT_FAILURE);
        }

        //打印文件到屏幕
        while((ch=getc(file)) != EOF)
            putc(ch, stdout);

        fclose(file);
        i++;
    }
    return 0;
}
