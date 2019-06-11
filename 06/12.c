//#12
//计算无限序列, 直到到达某个次数
//让用户交互地输入指定次数，当输入0或者负数时结束
/*
1 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + 1.0/5.0 +...
1 - 1.0/2.0 - 1.0/3.0 - 1.0/4.0 - 1.0/5.0 +...
*/
#include<stdio.h>

int main(void)
{
    long int n;
    float sum1=0.0, sum2=0.0;

    printf("请输入指定序列的次数:\n");
    scanf("%ld", &n);

    for(long int i=1; i<=n; i++)
        sum1+=1.0f/i;
    for(long int j=1; j<=n; j++)
        sum2-=1.0f/j;

    printf("1 + 1.0/2.0 +...+1/%ld = %.5f\n", n, sum1);
    printf("1 - 1.0/2.0 -...-1/%ld = %.5f\n", n, sum2);

    return 0;
}
