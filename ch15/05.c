/******************************Chapter 15 Exercise********************************/
//#5
//编写一个函数，把一个unsigned int 类型值的所有位向左旋转指定数量的位。
//例如: rotate_1(x, 4) 把x中所有位向左移动4个位置，而且从左移除的位会重新出现在右端。
//也就是说把高阶位移出的位放在低阶位。
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

const unsigned int BITS = sizeof(unsigned int) * CHAR_BIT;
const unsigned int LBITMASK = 1<<(sizeof(unsigned int) * CHAR_BIT-1);
unsigned int rotate(unsigned int n, int shiftbits);

int main(void)
{
    unsigned int number, shiftbits, rotated;

    puts("Please enter an integer number (q to quit):");
    while(scanf("%d", &number) == 1)
    {
        while(getchar()!='\n') continue; //clear input
        puts("Please enter the shift bits:");
        while(scanf("%d", &shiftbits) == 1)
        {
            while(getchar()!='\n') continue; //clear input
            puts("Before rotation:");
            for(int i = 0; i < BITS; i++)
            {
                if((number<<i) & LBITMASK)
                    putchar('1');
                else
                    putchar('0');
            }
            putchar('\n');

            puts("After rotation:");
            rotated = rotate(number, shiftbits);
            for(int i = 0; i < BITS; i++)
            {
                if((rotated<<i) & LBITMASK)
                    putchar('1');
                else
                    putchar('0');
            }
            putchar('\n');
            puts("Please enter the shift bits:");
        }
        while(getchar()!='\n') continue; //clear input
        puts("Please enter another integer number (q to quit):");
    }

    return 0;
}

unsigned int rotate(unsigned int n, int shiftbits)
{
    int leftbit;
    for(int i = 0; i < shiftbits; i++)
    {
        leftbit = n & LBITMASK; //确定最左端位的值是0还是1
        n <<= 1;    //n左移一位, 最右边位补0
        if(leftbit)
            n |= 1;  //若上面确认的最左端位1， 则在左移一位后，把1补在最右边位
    }
    return n;
}
