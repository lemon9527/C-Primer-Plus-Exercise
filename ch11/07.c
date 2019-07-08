/******************Chapter 11 Exercise********************/
//07.c
//strncpy(s1, s2, n) 函数把s2中的n个字符拷贝至s1中。截断s2，如有必要，在末尾加上空字符
//如果S2长度大于等于n，目标字符串不能以空字符结尾。该函数返回s1.
//自己编写一个函数名为mystrncpy().
#include <stdio.h>
#include <string.h>
#define SIZE 81

char * mystrncpy(char * s1, char * s2, int n);
char * s_gets(char * st, int n);
void clear_string(char *str, int n);

int main(void)
{
    char s1[SIZE];
    char s2[SIZE];
    int n = 0;

    puts("Enter a string to copy:");
    s_gets(s2, SIZE);
    while(s2[0] != '\0')
    {
        printf("How many letters do you want copy? (maximum %d) ", SIZE);
        scanf("%d", &n);

        while(getchar()!='\n')
            continue;
        mystrncpy(s1, s2, n);
        puts("s1:");
        puts(s1);

        clear_string(s1, SIZE);
        puts("Enter a string to copy:");
        s_gets(s2, SIZE);
    }

    puts("Bye.");

    return 0;
}

char * mystrncpy(char * s1, char * s2, int n)
{
    int s2_len = strlen(s2);
    int i = 0;

    if(s2_len < n)  //在目标字符串末尾加上空字符
    {
        while(i < s2_len)
        {
            s1[i] = s2[i];
            i++;
        }
        s1[s2_len] = '\0';
    }
    else            //目标字符串不以空字符结尾
    {
        while(i < n)
        {
            s1[i] = s2[i];
            i++;
        }
        s1[n] = '\0';
    }

    return s1;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        while(st[i] != '\n' && st[i] != '\0')
            i++;
        if(st[i] == '\n')
            st[i] = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}

void clear_string(char *str, int n)
{
    for (int i = 0; i<n; i++)
        str[i] = '\0';
}
