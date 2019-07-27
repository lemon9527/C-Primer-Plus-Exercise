/*********************************Chapter 14 Exercise***************************/
//#02
//编写一个函数，提示用户输入日，月和年， 月份可以是月份号，月份名或月份名缩写，
//然后函数就返回一年中到该天为止(包含该天)的天数.
//用上面复习题3,4的结构模板和结构数组
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 10
#define MONTHS 12

char * s_gets(char *st, int n);

struct month {
    char name[LEN];
    char abbrev[4];
    int days;
    char monnum[3];
};
struct month months[MONTHS] = {
        {"January", "JAN", 31, "01" },
        {"February", "FEB", 28, "02" },
        {"March", "MAR", 31, "03" },
        {"April", "APR", 30, "04" },
        {"May", "MAY", 31, "05" },
        {"June", "JUN", 30, "06" },
        {"July", "JUL", 31, "07" },
        {"August", "AUG", 31, "08" },
        {"September", "SEP", 31, "09" },
        {"October", "OCT", 31, "10"},
        {"November", "NOV", 30, "11" },
        {"December", "DEC", 31, "12" }
};

int main(void)
{
	int daynum, monnum, year, daysum;
	int i;
	char month[LEN];

	puts("Please enter a year: ");
	while(scanf("%d", &year)!=1)
	{
		//clear input stream
		while(getchar()!='\n')
			continue;
		puts("Please enter a year: ");
	}
	//clear input stream
	while(getchar()!='\n')
		continue;
	printf("Please input a month by name, abbreviation\n");
	printf("or two-digital number(eg. January, Jan or 01:\n");
	s_gets(month, LEN); //get the input string

	printf("Please input a day(1~31):\n");
	while(scanf("%d", &daynum)!=1)
	{
		//clear input stream
		while(getchar()!='\n')
			continue;
		printf("Please input a day(1~31):\n");
	}

	//match input to month
	for(i=0; i<MONTHS; i++)
	{
		if(strcmp(month, months[i].name) == 0 ||
			strcmp(month, months[i].abbrev) == 0 ||
			strcmp(month, months[i].monnum) == 0 )
			break;
	}

	// if no match (i==12)
	if(i==MONTHS)
	{
		printf("No month matchting %s found.\n", month);
		exit(1);
	}

	//check leap year and adjust days in Feb if necessary
	if((year%400 == 0) || ((year%4 == 0) && (year%100 != 0)))
	{
		months[1].days = 29;
	}

	//check valid for day
	if(daynum > months[i].days)
	{
		printf("Invalid data, there is no %d in %s %d.\n", 
			daynum, months[i].abbrev, year);
		exit(1);
	}

	//get total days in year up to given date
	daysum = 0;
	for(int j = 0; j < i; j++)
	{
		daysum += months[j].days;
	}
	daysum += daynum;

	printf("There are %d days in %d through %s %d.\n", 
		daysum, year, months[i].abbrev, daynum);

	return 0;
}

char * s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar()!='\n')
                continue;
    }
    return ret_val;
}
