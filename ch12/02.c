/******************Chapter 12 Exercise********************/
//02 pe12_2b.c
//与pe12_2a.c一起编译
#include <stdio.h>
#include "pe12_2a.h"

int mode;
float distance;
float fuel_consumed;

int main(void)
{
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while(mode >= 0)
    {
        set_mode(mode);
        get_info();
        show_info();
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}
