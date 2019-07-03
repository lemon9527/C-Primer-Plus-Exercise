/******************Chapter 10 Exercise********************/
//07.c
//编写一个程序，初始化一个double类型的二维数组，使用练习2中的一个拷贝函数
//把该数组中的数据拷贝至另一个二维数组(使用一维数组的拷贝函数拷贝每个子数组)
#include <stdio.h>
#include <stdlib.h>

void copy_ptr(double * target, double * source, int arr_len);

int main(void)
{
    //初始化一个二维double数组
    double source[10][10];
    double target[10][10];

    //给原数组赋值f
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            source[i][j] = rand()/(double) RAND_MAX;
        }
    }

    //copy 原数组到目标数组
    for(int i = 0; i < 10; i++)
        copy_ptr(target[i], source[i], 10);

    //打印原数组
    printf("source array:\n");
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            printf("%6.2f", source[i][j]);
        }
        putchar('\n');
    }
    //打印目标数组
    printf("target array:\n");
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            printf("%6.2f", target[i][j]);
        }
        putchar('\n');
    }
}

void copy_ptr(double * target, double * source, int arr_len)
{
    for(int i = 0; i < arr_len; i++)
        *(target + i) = *(source + i);
}
