//#4
//使用嵌套循环，按下面的格式打印字母
/*
A
BC
DEF
GHIJ
KLMNO
PQRSTU
*/
#include<stdio.h>

int main(void)
{
    int i, j;
    char k = 'A';

    for(i = 0; i<6; i++)
    {
        for(j = 0; j <= i; j++)
        {
            printf("%c", k++);
        }
        printf("\n");
    }

    return 0;
}
