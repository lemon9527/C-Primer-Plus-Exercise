// 11.c
// transform(source, target, 100, sin);
// transform 函数接受4个参数，内含double类型数据的源数组名, double 类型的目标数组名.
// 一个表示元素个数的int变量，一个函数名(或等价的函数指针)
#include<stdio.h>
#include<math.h>
#include<stdlib.h>  //使用rand()函数

#define SIZE 100

double source[SIZE];
double target[SIZE];
int n = 100;

double d(double x);
void transform(const double *source, double *target, int n, double (*pf)(double));

int main(void)
{
    //先初始化 source数组, 0~99之间的随机数
    for(int i=0; i<100; i++)
    {
        source[i] = (double) (rand()%100);
    }
    //print source
    for(int i=0; i<100; i++)
    {
        printf("%8.2f", source[i]);
        if(i%10 == 0)
            printf("\n");
    }
    puts("sin(x):");
    transform(source, target, n, d);
    //print target
    for(int i=0; i<100; i++)
    {
        printf("%8.2f", target[i]);
        if(i%10 == 0)
            printf("\n");
    }

}

void transform(const double *source, double *target, int n, double (*pf)(double))
{
    for(int i=0; i<100; i++)
    {
        target[i] = pf(source[i]);
    }
    return;
}

double d(double x)
{
    return 2*x;
}

