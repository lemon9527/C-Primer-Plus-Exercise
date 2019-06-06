//#2
//提示用户输入天数，然后转换成周数和天数，例如输入18， 输出2周4天
//18days are 2 weeks, 4 days
#include <stdio.h>

int main(void)
{
    int total_days;
    int mweeks, mdays;

    printf("Please enter days (or enter 0 to quit): \n");
    scanf("%d", &total_days);

    while(total_days>0){
        mweeks = (int)total_days/7;
        mdays = total_days%7;
        printf("%d days are %d weekys, %d days.\n", total_days, mweeks, mdays);

        printf("Please enter days (or enter 0 to quit): \n");
        scanf("%d", &total_days);
    }


    return 0;
}
