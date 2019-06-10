//#5
//编写一个程序，提示用户输入一个大写字母，使用嵌套循环以下面的格式打印字母
//比如输入E, 则有如下输出:

/*
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
*/

#include<stdio.h>

int main(void)
{
    char ch;
    printf("Please enter an uppercase letter:\n");
    scanf("%c", &ch);

    char c1, c2;
    for(c1 ='A'; c1<=ch; c1++)
    {
        for(int i=0; i<=ch-c1; i++)
        {
            printf(" ");
        }
        //打印递增字母
        for(c2='A'; c2<c1; c2++)
            printf("%c", c2);

        //打印递减字母
        for(; c2>='A'; c2--)
            printf("%c", c2);

        printf("\n");

    }

    return 0;
}
