//#9
//修改练习8， 用一个函数返回计算结果
#include<stdio.h>

float caculate(float n1, float n2); //ANSI C原型

int main(void)
{
    float num1, num2;
    printf("Please enter two floating-point numbers: \n");

    while(scanf("%f %f", &num1, &num2)==2)
    {
        printf("(%.3f - %.3f)/(%.3f * %.3f) = %.3f", num1, num2, num1, num2, caculate(num1, num2));
        printf("Please enter two floating-point number: \n");
    }
    return 0;
}

float caculate(float n1, float n2)
{
    return (n1-n2)/(n1*n2);
}
