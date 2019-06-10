//#8
//要求输入两个浮点数，并打印两数之差除以两数乘积的结果

#include<stdio.h>

int main(void)
{
    float num1, num2;

    printf("Please enter two floating-point number: \n");
    while(scanf("%f %f", &num1, &num2)==2)
    {
        printf("(%.3f - %.3f)/(%.3f * %.3f) = %.3f", num1, num2, num1, num2, (num1-num2)/(num1*num2));
        printf("Please enter two floating-point number: \n");
    }


    return 0;
}
