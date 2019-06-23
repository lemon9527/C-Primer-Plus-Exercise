//01.c
//设计一个函数min(x,y), 返回两个double类型值的较小值。
//在一个简单的驱动中测试该函数
#include <stdio.h>

double min(double x, double y);

int main(void)
{
	double a , b;
	printf("Enter two double numbers (non double input to quit):\n");
	while(scanf("%lf %lf", &a, &b) == 2)
	{
		printf("The smaller of %.3f and %.3f is %.3f\n", a, b, min(a ,b));
		printf("Enter two double numbers (non double input to quit):\n");	
	}

	printf("Bye.\n");
	
	return 0;
}

double min(double x, double y)
{
	if(x<=y)
		return x;
	else 
		return y;
}
