//#15
//输入一行字符，再把输入的内容倒序打印出来
#include<stdio.h>

int main(void)
{
    char line[255];
    int i = 0;

    printf("Enter a line to reverse:\n");
    while(scanf("%c", &line[i]), line[i]!='\n')
        i++;

    for(;i>=0; i--)
        printf("%c", line[i]);

    printf("\n");
    return 0;
}
