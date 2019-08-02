/*********************************Chapter 14 Exercise***************************/
//#04
//编写一个程序，创建一个有两个成员的结构模板
//a. 第一个成员是社会保险号，第二个成员是一个有3个成员的结构，其中第一个成员代表名，
//第二个成员代表中间名，第三个成员代表姓。创建并初始化一个内含5个该结构类型的数组。
//并以下面格式打印
//Dribble, Flossie M. -- 302039823
//如果有中间名，只打印第一个字母，并加. 没有则不用打点。
//编写一个函数，把结构数组传递给这个函数
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXFNAME 20
#define MAXMNAME 20
#define MAXLNAME 20

struct names {              //第一个结构
    char first[MAXFNAME];
    char middle[MAXMNAME];
    char last[MAXLNAME];
};

struct person{
    int ss_num;
    struct names handle;    //嵌套结构
};

void print_person_a(struct person *people);  //按地址传递结构给函数
void print_person_b(struct person people);   //按值传递结构给函数

int main(void)
{
    struct person people[5] = {//声明guy结构模板类型的数组, 内含5个元素
        {12345671, {"Marvin", "The", "Martian"}},
        {12345672, {"Scrooge", "Mc", "Duck"}},
        {12345673, {"Mantis", "Froggy", "Tobogan"}},
        {12345674, {.first="Night", .last="Man"}},
        {12345675, {.first="Day", .last="Man"}},
    };

    int i;
    for(i = 0; i < 5; i++)
    {
            print_person_a(&people[i]);
    }

    printf("按值传递结构给函数\n");
    for(i = 0; i < 5; i++)
    {
            print_person_b(people[i]);
    }

    return 0;
}

void print_person_a(struct person * people)    //按地址传递结构给函数
{
        printf("%s, %s ", people->handle.first, people->handle.last);
        //处理middle name
        if(people->handle.middle[0] != '\0')
            printf("%c. ", toupper(people->handle.middle[0]));

        printf("-- %d\n", people->ss_num);
}

void print_person_b(struct person people)    //按值传递结构给函数
{
        printf("%s, %s ", people.handle.first, people.handle.last);
        //处理middle name
        if(people.handle.middle[0] != '\0')
            printf("%c. ", toupper(people.handle.middle[0]));

        printf("-- %d\n", people.ss_num);
}
