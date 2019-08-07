/******************************Chapter 15 Exercise********************************/
//#3
//编写一个函数，接收一个int类型的参数，并返回该参数中打开位的数量。
//比如: 10110110 (打开的位数是5)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int onbitnumber(int n);

int main(void)
{
    int number;
    puts("Please enter an integer number (q to quit):");
    while(scanf("%d", &number) == 1)
    {
        while(getchar()!='\n') continue; //clear input
        printf("%d has %d open bits.\n", number, onbitnumber(number));
        puts("Please enter another integer number (q to quit):");
    }

    return 0;
}

int onbitnumber(int n)
{
    int count = 0;
    while(n!=0)
    {
        if(n&0x01)
            count++;
        n>>=1;
    }
    return count;
}
