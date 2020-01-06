// 10.c
// 编写一个程序，通过函数指针数组实现菜单功能，选择菜单a，将激活该数组第一个
// 元素指向的函数
#include <stdio.h>

double fun0(double x, double y);
double fun1(double x, double y);
double fun2(double x, double y);
double fun3(double x, double y);
double fun4(double x, double y);

//void (*pf)(char *);   //声明函数指针 declare array of function point
typedef double(*V_FP_CHAR)(double x, double y);
V_FP_CHAR arpf[5] = {fun0, fun1, fun2, fun3, fun4};

int main(void)
{
    int ch = 0;
    double x, y;
    while(1)
    {
        printf("************** menu test *****************\n");
        puts("To choose a menu:");
        puts("a) fun0");
        puts("b) fun1");
        puts("c) fun2");
        puts("d) fun3");
        puts("e) fun4");

        if((ch = getchar()) != '\n')
            while(getchar() != '\n') continue;  //clear input stream
        ch -= 'a';
        
        if(ch < 0 || ch >= 5)
        {
            puts("This is not a valid option.");
            continue;   //结束本次循环，开始下一次循环
        }
        
        printf("Enter two numbers:\n");
        while(scanf("%lf %lf", &x, &y) != 2)
        {
            while(getchar() != '\n') continue;  //clear input stream
            printf("Invalid input, Enter two numbers:\n");
        }
        while(getchar() != '\n') continue;  //clear input stream
        printf("%f\n", arpf[ch](x, y));
        puts("");
    }



    return 0;
}

double fun0(double x, double y)
{
    return (x+y);
}

double fun1(double x, double y)
{
     return (x-y);
}

double fun2(double x, double y)
{
     return (x*y);
}

double fun3(double x, double y)
{
     return (x/y);
}

double fun4(double x, double y)
{
     return (x+y);
}
