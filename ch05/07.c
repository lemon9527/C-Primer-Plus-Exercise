//#7
//编写一个程序，提示用户输入double类型的数， 并打印该数的立方值。
//设计一个函数计算并打印立方值
#include <stdio.h>

double cube(double n);

int main(void)
{
    double input;
    printf("Please enter an number:\n");
    scanf("%lf", &input);   //double 型需要用%lf

    printf("The cube of %.3f is. %1.3f.\n", input, cube(input));

    return 0;
}

double cube(double n)
{
    return n * n *n ;
}
