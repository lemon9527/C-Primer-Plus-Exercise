/******************************Chapter 15 Exercise********************************/
//#4
//编写一个程序，接收两个int类型的参数，一个是值，一个是位的位置。如果指定的位的位置为1，
//则返回1；否则返回0.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int bitvalue(int n, int position);

int main(void)
{
    int number, position;
    puts("Please enter an integer number (q to quit):");
    while(scanf("%d", &number) == 1)
    {
        while(getchar()!='\n') continue; //clear input
        puts("Please enter the position:");
        while(scanf("%d", &position) == 1)
        {
            while(getchar()!='\n') continue; //clear input
            printf("the value in position %d is %d.\n", position, bitvalue(number, position));
        }
        while(getchar()!='\n') continue; //clear input
        puts("Please enter another integer number (q to quit):");
    }

    return 0;
}

int bitvalue(int n, int position)
{
    n>>=position-1;
    return (n&0x01);
}
