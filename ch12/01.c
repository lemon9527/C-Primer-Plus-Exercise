/******************Chapter 12 Exercise********************/
//#01 不适用全局变量，重写程序12.4
//不用指针，用函数返回值的方式
//#include <stdio.h>
//int critic(void);
//
//int main(void)
//{
//    int units;
//    printf("How many pounds to firkin of butter?\n");
//    scanf("%d", &units);
//    while(units != 56)
//    {
//        units = critic();
//    }
//    printf("You must have looked it up!\n");
//
//    return 0;
//}
//
//int critic()
//{
//    int temp;
//    printf("No luck, my friend, Try again.\n");
//    scanf("%d", &temp);
//
//    return temp;
//}

/*************用指针传递参数*****************/
#include <stdio.h>
void critic(int * units);

int main(void)
{
    int units;
    printf("How many pounds to firkin of butter?\n");
    scanf("%d", &units);
    while(units != 56)
        critic(&units);
    printf("You must have looked it up!\n");
}

void critic(int * units)
{
    printf("No luck, my friend, Try again.\n");
    scanf("%d", units);
}
