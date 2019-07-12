#include "pe12_3a.h"
#include <stdio.h>

#define METRIC  0
#define US      1
#define QUIT   -1

void clear_input_stream(void)
{
    while(getchar()!='\n')
        continue;
}

void set_mode(int * new_mode)
{
    while(*new_mode != METRIC && *new_mode != US)
    {
        printf("Invalid mode specified, enter the right mode again: \n");
        scanf("%d", new_mode);
    }
}

void get_info(int mode, double *distance, double *fuel_consumed)
{
    printf("Enter distance traveled in %s: ", mode == METRIC? "kilometers" : "miles");
    while(scanf("%lf", distance) != 1)
    {
        clear_input_stream();
        printf("Invalid input, Enter distance traveled in %s: ", mode == METRIC? "kilometers" : "miles");
    }

    printf("Enter Fuel consumed in %s: ", mode == METRIC? "liters" : "gallon");
    while(scanf("%lf", fuel_consumed) != 1)
    {
       clear_input_stream();
        printf("Invalid input, Enter distance traveled in %s: ", mode == METRIC? "liters" : "gallon");
    }

}

void show_info(int mode, double distance, double fuel_consumed)
{
    printf("Fuel consumption is %.2f %s per %s.\n", mode == METRIC? (float)((fuel_consumed/distance)*100):(float)(distance/fuel_consumed),
           mode == METRIC?"liters":"miles", mode == METRIC? "100km":"gallon");
}
