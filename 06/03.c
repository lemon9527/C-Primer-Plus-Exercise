//#3
//使用嵌套循环，按下面的格式打印字母
/*
F
FE
FED
FEDC
FEDCB
FEDCBA
*/
#include<stdio.h>

int main(void)
{
    int i, j;

    for(i = 0; i<6; i++)
    {
        for(j = 0; j<=i; j++)
        {
            printf("%c", 70-j);
        }
        printf("\n");
    }

    return 0;
}
