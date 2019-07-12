#include "pe12_2a.h"
#include <stdio.h>

#define METRIC 0
#define US     1

void set_mode(int new_mode)
{
//    if(new_mode != METRIC && new_mode != US)
//        printf("Invalid mode specified. Mode %d(%s) used.\n",
//               mode, mode == METRIC ? "metric": "US");
    while(new_mode != METRIC && new_mode != US)
    {
        printf("Invalid mode specified, enter the right mode again: \n");
        scanf("%d", &new_mode);
    }
    mode = new_mode;
}

void get_info(void)
{
    printf("Enter distance traveled in %s:", mode == METRIC? "kilometers" : "miles");
    scanf("%f", &distance);

    printf("Enter Fuel consumed in %s:", mode == METRIC? "liters" : "gallon");
    scanf("%f", &fuel_consumed);
}

void show_info(void)
{
    printf("Fuel consumption is %.2f %s per %s.\n", mode == METRIC? (float)((fuel_consumed/distance)*100):(float)(distance/fuel_consumed),
           mode == METRIC?"liters":"miles", mode == METRIC? "100km":"gallon");
}
