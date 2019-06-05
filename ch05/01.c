//#1
#include <stdio.h>

#define M_PER_H 60

int main(void)
{
    int minutes;
    int nhours, nminutes;
    printf("This program convert minutes to Hour and minutes.\n");
    printf("Please enter an amount of time in minute:\n");
    scanf("%d", &minutes);

    while(minutes>0)
    {
        nhours = (int)minutes/M_PER_H;
        nminutes = (int)minutes%M_PER_H;

        printf("%d minutes is: %d hours and %d minutes.\n",minutes, nhours,nminutes);

        //get a new amount of time
        printf("Please enter an amount of time in minute:\n");
        scanf("%d", &minutes);
    }
    
    return 0;
}
