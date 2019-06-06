//#5
//提示用户输入天数，第一天赚$1, 第二天赚$2,以此类推
#include <stdio.h>

int main(void)
{
    int days;
    int i = 1;
    int income = 0;
    printf("Please enter an amount number of days (0 to quit): \n");
    scanf("%d", &days);

    while(days>0){
        while(i<=days){
        income = income + i;
        i++;
        }
        printf("Total income in %d days are %d.\n", days, income);

        printf("Please enter an amount number of days (0 to quit): \n");
        scanf("%d", &days);
    }
    return 0;
}
