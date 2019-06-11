//#11
//在数组中读入8个整数，然后倒序打印这8个整数
#include<stdio.h>

int main(void)
{
    int array[8];
    printf("Please enter 8 integers separated by spaces:\n");
    for(int i=0; i<8; i++)
        scanf("%d", &array[i]);

    //print
    printf("倒序打印如下：\n");
    for(int i=7; i>=0; i--)
        printf("%d  ", array[i]);

    return 0;
}
