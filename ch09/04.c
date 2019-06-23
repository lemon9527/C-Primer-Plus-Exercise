//04.c
//两个数的调和平均数： 先得到两个数的倒数，然后计算两个倒数的平均值，最后取计算结果的倒数。
//编写一个函数，接受两个double类型的参数，返回这两个参数的调和平均数
#include <stdio.h>

double harmonic_average(double x1, double x2);

int main(void)
{
	double a, b;
	double result;

	printf("Enter two numbers.\n");
	while(scanf("%lf %lf", &a, &b)==2)
	{
		result = harmonic_average(a, b);
		printf("The harmoic average of %.3f and %.3f is %.3f\n", a, b, result);

		while(getchar()!='\n') continue;

		printf("Enter two numbers.\n");
	}

	printf("Bye.\n");

	return 0;
}

double harmonic_average(double x1, double x2)
{
	return 2/(1/x1 + 1/x2);
}

