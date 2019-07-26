/***********************************Chapter 14 Exercise***************************/
//#01
//编写一个程序，用户输入月份名称，函数就返回一年中到该月为止(包含该月)的天数.
//用上面复习题3,4的结构模板和结构数组
#include <stdio.h>
#include <string.h>

char * s_gets(char *st, int n);
int days(const char * monnum);

struct month {
    char name[10];
    char abbrev[4];
    int days;
    int monnum;
};
struct month months[12] = {
        {"January", "jan", 31, 1 },
        {"February", "feb", 28, 2 },
        {"March", "mar", 31, 3 },
        {"April", "apr", 30, 4 },
        {"May", "may", 31, 5 },
        {"June", "jun", 30, 6 },
        {"July", "jul", 31, 7 },
        {"August", "aug", 31, 8 },
        {"September", "sep", 31, 9 },
        {"October", "oct", 31, 10},
        {"November", "nov", 30, 11 },
        {"December", "dec", 31, 12 }
};

int main(void)
{
    char monname[10];

    puts("Please enter month Name:");
    puts("Press [enter] at the start of a line to stop.");

    while(s_gets(monname, 10) != NULL && monname[0] !='\0')
    {
        printf("your enter monname is %s with %d days.\n", monname, days(monname));

        puts("Please enter month Name:");
        puts("Press [enter] at the start of a line to stop.");
    }

    return 0;
}

int days(const char * monname)
{
    int monnum, i, sum;
    for(i = 0, monnum = 0; i < 12; i++)
    {
        if(strcmp(monname, months[i].name) == 0)
        {
            monnum = i + 1;
            break;
        }
    }

    if(monnum <1 || monnum > 12)
        return (-1);
    for(i = 0, sum = 0; i < monnum; i++)
    {
        sum += months[i].days;
    }
    return sum;
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
