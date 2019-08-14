/***********************************Chapter 16***********************************************/
//04
#include <stdio.h>
#include <time.h>

void delay(double n);

int main(void)
{
    printf("start\n");

    delay(5);

    printf("end\n");
}

void delay(double n)
{
    printf("please wait %.2f seconds...\n", n);
    clock_t t1 = clock();

    while((clock() - t1)/(double)CLOCKS_PER_SEC < n);
}
