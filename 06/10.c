//#10
//输入一个上限整数和一个下限整数，计算从上限到下限所有整数的平方和。
//循环提示输入，知道用户输入的上限值小于下限值
#include<stdio.h>

int main(void)
{
    int upper_limit, lower_limit;
    int square_sum;

    printf("Please enter upper_limit integer and lower_limit(separated by space):\n");
    while(scanf("%d %d", &upper_limit, &lower_limit)==2 && upper_limit>=lower_limit)
    {
        square_sum = 0;
        for(int i=lower_limit; i<=upper_limit; i++)
            square_sum += i*i;

        printf("The sum of the squares from %d to %d is %d\n", lower_limit, upper_limit, square_sum);
        printf("Enter next set of limits:\n");
    }

    printf("Done!\n");

    return 0;
}
