/******************Chapter 10 Exercise********************/
//06.c
//编写一个函数，把一个double类型数组中的数据倒序排列
#include <stdio.h>
#define SIZE 10

void reverse(double * arr, int arr_size);

int main(void)
{
    double arr[SIZE] = {9.9, 1.2, 12.1, 3.4, 4.5, 5.8, 6.7, 7.8, 8.9, 8.0};
    //print array
    printf("The original array: \n");
    for(int i = 0; i < SIZE; i++)
        printf("%6.2f", arr[i]);

    reverse(arr, SIZE);
    printf("\nThe array after reverse: \n");
    for(int i = 0; i < SIZE; i++)
        printf("%6.2f", arr[i]);

    return 0;
}

void reverse(double * arr, int arr_size)
{
    double temp;
    for(int i = 0; i < arr_size/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[arr_size-1-i];
        arr[arr_size-1-i]= temp;
    }
}

//排序，从大到小
//void sort_arr(double * arr, int arr_size)
//{
//    int i, j;
//
//    for(j = 0; j < arr_size-1; j++)
//    {
//        for(i = 0; i < arr_size-j-1; i++)
//        {
//            if(arr[arr_size-1-i]>arr[arr_size-2-i])
//            {
//                double temp;
//                temp = arr[arr_size-1-i];
//                arr[arr_size-1-i] = arr[arr_size-2-i];
//                arr[arr_size-2-i] = temp;
//            }
//        }
//    }
//}
