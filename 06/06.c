//#6
//打印一个表格，每行打印一个整数，该数的平方，该数的立方。
//要求输入表格的上下限
#include<stdio.h>

int main(void)
{
    long min_integer, max_integer;

    printf("Please enter min_integer: ");
    scanf("%ld",&min_integer);
    printf("Please enter max_integer: ");
    scanf("%ld", &max_integer);

    printf(" Integer   | Square    | Cube      |\n");

    for(long i=min_integer; i<=max_integer; i++)
    {
        printf("%10ld |%10ld |%10ld |\n",i, i*i, i*i*i);
    }
    return 0;
}
