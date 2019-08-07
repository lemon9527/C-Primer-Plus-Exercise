/******************************Chapter 15 Exercise********************************/
//#1
//编写一个函数，把二进制字符串转换为一个数值，例如，下面的语句
// char * pbin = "01001001";
//那么把pbin作为参数传递给该函数后，应该返回一个int类型的值25
#include <stdio.h>
#include <string.h>
#define BINLEN  40

//int str2int(char * str);
int str2numeric(char *str);
char * s_gets(char *st, int n);

int main(void)
{
    char binarystr[BINLEN];
    printf("Please enter an binary string (01001001):\n");

    s_gets(binarystr, BINLEN);
    printf("You input is %s ", binarystr);
    //printf("Decimal is %d", str2int(binarystr));
    printf("Decimal is %d", str2numeric(binarystr));


    return 0;
}

//Convert a binary string to a numeric value
//int str2int(char * str)
//{
//    int bitsize = strlen(str);
//    printf("bitsize = %d\n", bitsize);
//    int sum = 0, m = 1;
//    for(int i=bitsize-1; i>=0; i--)
//    {
//        sum +=(str[i]-'0')*m; //数字字符的ascii码减去字符'0'才是其数值
//        m*=2;
//    }
//    return sum;
//}

int str2numeric(char *str)
{
    int str_length = strlen(str);
    int i = 0;
    int retval = 0;
    while( i < str_length)
    {
        retval |= ((str[i] - '0') << (str_length-i-1));
        i++;
    }
    return retval;
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
