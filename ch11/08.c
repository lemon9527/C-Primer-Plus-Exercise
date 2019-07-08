/******************Chapter 11 Exercise********************/
//08.c
//编写一个名为string_in() 函数，接受两个指向字符串的指针作为参数，如果第二个字符串包含在第一个
//字符串中，该函数将返回包含在第一个字符串中的第二个字符串开始的地址。例如 string_in("hats", "at")
//将返回hats中a的地址。 否则，该函数返回空指针
#include <stdio.h>
#define SIZE 81

char * string_in(char * str1, char * str2);
char * s_gets(char * st, int n);

int main(void)
{
    char string1[SIZE];
    char string2[SIZE];
    char * ptr;

    puts("Enter a string: ");
    s_gets(string1, SIZE);
    while(string1[0] != '\0')
    {
        puts("Enter another string: ");
        s_gets(string2, SIZE);

        ptr = string_in(string1, string2);

        if(ptr != NULL)
            printf("%s is in %s, from letter %lu\n", string2, string1, ptr-string1);
        else
            printf("%s is not in %s.\n", string2, string1);

        puts("Enter a string: ");
        s_gets(string1, SIZE);
    }

    puts("Bye.");

    return 0;
}

char * string_in(char * str1, char * str2)
{
    int i = 0;
    int j = 0;
    while(i < strlen(str1))
    {
        if(str2[j] == str1[i] && j<strlen(str2))
        {
            j++;
            if(str2[j] == '\0')
            {
                return &str1[i-j+1];
                break;
            }
        }
        else
            j = 0;
        i++;
    }
    return NULL;

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
