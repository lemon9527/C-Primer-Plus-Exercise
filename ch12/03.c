/******************Chapter 12 Exercise********************/
//03 pe12_3b.c
//与pe12_3a.c一起编译
#include <stdio.h>
#include "pe12_3a.h"

int main(void)
{
    int mode;
    double distance;
    double fuel_consumed;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while(mode >= 0)
    {
        set_mode(&mode);
        get_info(mode, &distance, &fuel_consumed);
        show_info(mode, distance, fuel_consumed);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}
