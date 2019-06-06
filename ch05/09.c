//#9
//输入一个double型的华氏温度，转换成摄氏温度和开氏温度
//摄氏温度 = 5.0/9.0 *(华氏温度-20)
//开氏温度 = 摄氏温度 + 273.16

#include <stdio.h>

void Temperatures(double n);

int main(void)
{
    double temperature_F;
    printf("Enter an temperature in (℉):\n");

    while(scanf("%lf", &temperature_F)==1)
    {
        Temperatures(temperature_F);

        printf("Enter an temperature in (℉):\n");
    }

    return 0;
}

void Temperatures(double n)
{
    printf("%.3f ℉ is %.3f ℃， %.3fK\n", n, 5.0/9.0 * (n-20), 5.0/9.0 * (n-20)+273.16);
}
