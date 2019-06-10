//#2
//使用嵌套循环，按下面格式打印字符
/*
$
$$
$$$
$$$$
$$$$$
*/
#include <stdio.h>

int main(void)
{
    int i, j;

    for(i = 0; i<5; i++)
    {
        for(j = 0; j<=i; j++)
        {
            printf("$");
        }
        printf("\n");
    }

    return 0;
}
