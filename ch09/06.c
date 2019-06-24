//06.c
//编写并测试一个函数，该函数以三个double变量的地址作为参数，把最小值放入第一个
//中间值放入第二个变量，最大值放入第三个变量
#include <stdio.h>

void sort(double * s1, double * s2, double * s3);

int main(void)
{
    double x1, x2, x3;

    printf("Enter 3 double numbers.\n");
    while(scanf("%lf %lf %lf", &x1, &x2, &x3)==3)
    {
        printf("Before sorting, x1 = %.3f, x2 = %.3f, x3 = %.3f\n", x1, x2, x3);
        sort(&x1, &x2, &x3);
        printf("After sorting, x1 = %.3f, x2 = %.3f, x3 = %.3f\n", x1, x2, x3);

        while(getchar()!='\n') continue;
        printf("Enter 3 double numbers.\n");
    }
    printf("Bye.\n");
    return 0;
}

void sort(double * s1, double * s2, double * s3)
{
    //从小到大排序
    if(*s1 > *s2)
    {
        double temp = *s2;
        *s2 = *s1;
        *s1 = temp;
    }
    if(*s2 > *s3)
    {
        double temp = *s3;
        *s3 = *s2;
        *s2 = temp;

        if(*s1 > *s2)
        {
            double temp = *s2;
            *s2 = *s1;
            *s1 = temp;
        }
    }
}
