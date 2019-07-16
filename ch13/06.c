/******************Chapter 13 Exercise********************/
//06
//重写13.2清单中的程序，不适用命令行参数，提示用户输入所需信息
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 81

void get(char *string, int n);

int main(void)
{
    FILE *in, *out; //声明两个指向FILE的指针
    int ch;
    char destname[LEN]; //储存输出文件名
    char sourcename[LEN]; //源文件名
    int count = 0;

    puts("Enter a file name for reduce:");
    get(sourcename, LEN-5);
    //设置输入
    if((in = fopen(sourcename, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", sourcename);
        exit(EXIT_FAILURE);
    }

    strcpy(destname, sourcename);
    strcat(destname, ".red");//文件名后增加.red

    if((out = fopen(destname, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }

    //拷贝数据
    while((ch=getc(in))!=EOF)
    {
        if(count++ % 3 == 0)
            putc(ch, out);
    }

    if(fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files.\n");

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
