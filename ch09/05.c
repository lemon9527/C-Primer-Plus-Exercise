//05.c
//编写并测试一个函数larger_of(), 该函数把两个double类型变量的值替换为较大的值。
//例如，larger(x, y) 会把 x 和 y中较大的值重新赋值给两个变量，
#include <stdio.h>

void larger_of(double * x, double * y);

int main(void)
{
	double x1, y1;

	printf("Test larger_of() function\n");
	printf("Enter two double numbers.\n");
	while(scanf("%lf %lf", &x1, &y1)==2)
	{
		printf("Original x1 = %.3f, y1 = %.3f.\n", x1, y1);
		larger_of(&x1, &y1);
		printf("The new x1 = %.3f, y1 = %.3f.\n", x1, y1);

		while(getchar()!='\n') continue;

		printf("Enter two double numbers.\n");
	}
	return 0;
}

void larger_of(double * x, double * y)
{
	if(*x >= *y)
	{
		*y = *x;
	}
	else
	{
		*x = *y;
	}
}
