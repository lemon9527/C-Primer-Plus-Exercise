/******************Chapter 10 Exercise********************/
//08.c
//使用练习2中的拷贝函数，把一个内含7个元素的数组中第3~5个元素拷贝
//至内含3个元素的数组中
#include <stdio.h>
#define SIZE 7
void copy_ptr(double * target, double * source, int arr_len);

int main(void)
{
    double source[SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    double target[3];
    //print source array
    printf("source array:\n");
    for(int i = 0; i < SIZE; i++)
        printf("%5.1f", source[i]);

    //copy_ptr(target, &source[2], 3);
    copy_ptr(target, source+2, 3);

    //print target array
    printf("\n\ntarget array:\n");
    for(int i = 0; i < 3; i++)
        printf("%5.1f", target[i]);
}

void copy_ptr(double * target, double * source, int arr_len)
{
    for(int i = 0; i < arr_len; i++)
        *(target + i) = *(source + i);
}
