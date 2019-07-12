/******************Chapter 12 Exercise********************/
//05 编写一个程序，生成100个1~10范围内的随机数，并以降序排列
//可以把第11章的排序算法稍加改动，这里仅对整数排序
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void generate_and_sort(int * num, int size);


int main(void)
{
    int num[100];
    srand((unsigned int)time(0));
    generate_and_sort(num, SIZE); //生成100个随机整数(1~10)

    for(int i = 0; i < SIZE; i++)
    {
        printf("%4d", num[i]);
        if(i%5 == 4)
            putchar('\n');
    }

    return 0;
}

void generate_and_sort(int * num, int size)
{
    int i = 0;
    int j = 0;
    int temp;
    //generate array
    for(i=0; i<size; i++)
    {
        num[i] = rand()%10 + 1;
    }

    //sort in decreasing order
    for(i = 0; i < size-1; i++)
        for(j = i+1; j < size; j++)
        {
            if(num[i] < num [j])
            {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
}
