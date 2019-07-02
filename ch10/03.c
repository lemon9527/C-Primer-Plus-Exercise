/******************Chapter 10 Exercise********************/
//03.c
//编写一个函数，返回储存在int 类型数组中的最大值，并在一个简单的程序中测试
#include <stdio.h>
#define SIZE 10

int max_in_arr(int * arr, int arr_size);

int main(void)
{
    int arr[SIZE] = {1, 2, 3, 41, 5, 6, 7, 8, 10, 9};

    printf("The max value in arr[10] is %d\n", max_in_arr(arr, SIZE));

    return 0;
}

int max_in_arr(int * arr, int arr_size)
{
    for(int i = 0; i < arr_size; i++)
    {
        if(arr[i]>=arr[i+1] && (i+1)<arr_size)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    return arr[arr_size-1];
}
