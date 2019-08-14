
/***********************************Chapter 16***********************************************/
//02 调和平均数
#include <stdio.h>
#define CLEARINPUT while(getchar()!='\n') continue
#define INVERSE(X) 1./X
#define AVERAGE(X, Y) (2./(INVERSE(X) + INVERSE(Y)))

int main(void)
{
    double x, y;

    puts("Please enter two numbers:");
    while(scanf("%lf %lf", &x, &y) == 2)
    {
        CLEARINPUT;
        printf("The harmonic mean of %.7f and %.7f is %.7f.\n", x, y, AVERAGE(x, y));

        printf("Enter another two numbers:\n");
    }
    puts("Bye\n");
    return 0;
}
