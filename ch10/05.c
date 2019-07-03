/******************Chapter 10 Exercise********************/
//05.c
//编写一个函数，返回存储在double类型数组中最大值和最小值的差值
#include <stdio.h>
#define SIZE 10

double max_min(double * arr, int arr_size);

int main(void)
{
    double arr[SIZE] = {9.9, 1.2, 12.1, 3.4, 4.5, 5.8, 6.7, 7.8, 8.9, 8.0};
    //print array
    printf("The difference between the largest and smallest values of \n");
    for(int i = 0; i < SIZE; i++)
        printf("%6.2f", arr[i]);

    printf(" is %6.2f", max_min(arr, SIZE));

    return 0;
}

double max_min(double * arr, int arr_size)
{
    //求出最大值和最小值
    double max = arr[0];
    double min = arr[0];

    for(int i = 1; i < arr_size; i++)
    {
        if(arr[i]>max)
            max = arr[i];
        if(arr[i]<min)
            min = arr[i];
    }
    return max-min;
}
