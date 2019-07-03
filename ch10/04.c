/******************Chapter 10 Exercise********************/
//04.c
//编写一个函数，返回存储在double类型数组中最大值的下标
#include <stdio.h>
#define SIZE 10
int maxvalue_index(double * arr, int arr_size);

int main(void)
{
    double arr[SIZE] = {9.9, 1.2, 12.1, 3.4, 4.5, 5.8, 6.7, 7.8, 8.9, 8.0};
    //print array
    printf("double array:\n");
    printf("Index ");

    for(int i = 0; i < SIZE; i++)
        printf("%6d", i);
    printf("\n      ");
    for(int i = 0; i < SIZE; i++)
        printf("%6.2f", arr[i]);
    putchar('\n');

    printf("\nThe maxvalue index is %d.\n", maxvalue_index(arr, SIZE));

    return 0;
}

int maxvalue_index(double * arr, int arr_size)
{
    int index = 0;
    for(int i = 1; i < arr_size; i++)
    {
        //if(arr[i]>arr[index])
        if(*(arr+i) > *(arr+index))
        {
            index = i;
        }
    }
    return index;
}
