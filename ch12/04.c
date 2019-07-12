/******************Chapter 12 Exercise********************/
//04 在一个循环中编写并测试一个函数，返回它被调用的次数
//这里需要使用静态局部变量
#include <stdio.h>
int func(void);

int main(void)
{
    int i;
    int times;
    printf("How many times do you want to call func()?\n (0 to quit): ");
    while(scanf("%d", &times) && times>=0)
    {
        if(times==0)
            break;
        for(i = 0; i < times; i++)
        {
            printf("func() called at %d times.\n", func());
        }
        printf("How many times do you want to call func()?\n (0 to quit): ");
    }
    puts("Done.");

    return 0;
}

int func(void)
{
    static int call_times = 0;
    call_times++;

    return call_times;
}
