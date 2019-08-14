/***********************************Chapter 16***********************************************/
//05 编写一个函数接受如下参数： 内含int类型元素的数组名，数组的大小，一个代表选取次数的值。
//该函数从数组中随机选择指定数量的元素，并打印它们。每个元素只能选择一次(模拟抽奖数字)。
//另外可以在srand()中使用time()的输出来初始化随机函数生成器rand()
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100

void sample(int * arr, int size, int count);

int main(void)
{
    int i;
    int arr1[SIZE];
    //initial array
    for(i = 0; i < SIZE; i++)
        arr1[i] = i;

    int n;
    printf("How many times do you want to sample:\n");
    while(scanf("%d", &n)==1 && n > 0)
    {
        sample(arr1, SIZE, n);

        puts("How many times do you want to sample:");
    }

    printf("Bye.\n");
    return 0;
}

void sample(int * arr, int size, int count)
{
    int i=0, n=0;
    bool chosen[size];

    if(count>size)
    {
        puts("Error: sample size can not be large than array size.");
        return;
    }

    for(i = 0; i < SIZE; i++)
        chosen[i] = false;

    srand((unsigned int)time(NULL));
    for(i = 1; i <= count; i++)  //sample times
    {
        //取随机数(0~size-1), 工count次，且每次不得重复
        n = rand()%SIZE;
        while(chosen[n])
            n = rand()%SIZE;
        chosen[n] = true;
        printf("%4d", arr[n]);

        if(i%5==0)
            putchar('\n');
    }
    putchar('\n');
}
