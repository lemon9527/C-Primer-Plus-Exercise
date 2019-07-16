
/******************Chapter 13 Exercise********************/
//02
//编写一个拷贝程序，通过命令行获取原始文件名和目标文件名，尽量使用标准IO
//和二进制模式
#include <stdio.h>
#include <stdlib.h>
#define LEN 41

int main(int argc, char *argv[])
{
    FILE *sourcefile, *targetfile;
    int ch;

    //检查命令行参数
    while(argc < 3)
    {
        fprintf(stderr, "Usage %s sourcename targetname.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    //设置源文件
    if((sourcefile = fopen(argv[1], "rb"))==NULL)
    {
        fprintf(stderr, "Could not open the file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    //设置目标文件
    if((targetfile = fopen(argv[2], "wb"))==NULL)
    {
        fprintf(stderr, "Could not create target file \"%s\"\n", argv[2]);
        exit(3);
    }

    //拷贝数据
    while((ch=getc(sourcefile)) != EOF)
    {
        putc(ch, targetfile);
    }

    //收尾
    if(fclose(sourcefile) != 0 || fclose(targetfile) != 0)
    {
        fprintf(stderr, "Error in closing files.\n");
    }

    return 0;
}
