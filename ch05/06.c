//#6
//第五题算成平方和
#include <stdio.h>

int main(void)
{
    int days;
    int i = 1;
    int income_sum = 0;

    printf("Please enter an amount number of days: \n");
    scanf("%d", &days);

    while(i<=days){
        income_sum = income_sum + i*i;
        i++;
    }
    printf("Total income in %d days are %d.\n", days, income_sum);

    return 0;
}
