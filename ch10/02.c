/******************Chapter 10 Exercise********************/
//02.c
//初始化一个double 类型的数组，然后把该数组内容拷贝至3个其他数组中
//1. 使用带数组表示法进行第一份拷贝
//2. 使用带指针表示法和指针递增进行第二份拷贝
//3. 以目标数组名，源数组名，和指向源数组最后一个元素后面的元素的指针 为参数.


#include <stdio.h>
#define SIZE 5

void copy_arr(double * target, double * source, int arr_len);
void copy_ptr(double * target, double * source, int arr_len);
void copy_ptrs(double * target, double * source_start, double * source_end);

int main(void)
{
    double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    copy_arr(target1, source, SIZE);
    copy_ptr(target2, source, SIZE);
    copy_ptrs(target3, source, source+SIZE);

    printf("%15s|%15s|%15s\n", "target1", "target2", "target3");
    for(int i = 0; i < SIZE; i++)
        printf("%15.3f|%15.3f|%15.3f\n", target1[i], target2[i], target3[i]);

    return 0;
}

void copy_arr(double * target, double * source, int arr_len)
{
    for(int i = 0; i < arr_len; i++)
        target[i] = source[i];
}


void copy_ptr(double * target, double * source, int arr_len)
{
    for(int i = 0; i < arr_len; i++)
        *(target + i) = *(source + i);
}

void copy_ptrs(double * target, double * source_start, double * source_end)
{
    for(double *ptr = source_start; ptr<source_end; ptr++, target++)
        *target = *ptr;
}
