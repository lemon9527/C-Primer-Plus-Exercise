/*********************************Chapter 14 Exercise***************************/
//#05
//编写一个程序，满足下面要求
//a. 外部定义一个有两个成员的结构模板name: 一个字符串存储名，一个字符串存储姓
//b. 外部定义一个有3个成员的结构模板student: 一个name类型的结构，一个grade数组储存
//3个浮点型分数，一个变量储存3个分数的平均数
//c. 在main函数里声明一个内含4个student类型结构的数组，并初始化这些结构的名字。
// 执行下面的任务
//d. 以交互方式获取每个学生的分数，分数存到grade数组响应的数组里。
//e. 计算每个结构的平均分，并把计算后的值赋给合适的成员
//f. 打印每个结构的信息
//g. 打印班级平均分，及所有结构的数值成员的平均值


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXFNAME 20
#define MAXLNAME 20
#define GRADELEN 3
#define CSIZE 4

struct Name {       //结构模板name
    char firstname[MAXFNAME];
    char lastname[MAXLNAME];
};

struct Student {
    struct Name names;  //嵌套结构
    float grade[GRADELEN];
    float average;
};

void getgrades(struct Student * student);
void getaverage(struct Student * student);
void showsinfo(struct Student * student);
float getclassaverage(struct Student ** student);

int main(void)
{
    struct Student students[CSIZE] = {
            {.names = {"Lemon", "Liu"}},
            {.names = {"Jimmy", "Liu"}},
            {.names = {"Asa", "Zou"}},
            {.names = {"Aike", "Yang"}},
    };

    //get student name and grade
    for(int i = 0; i < CSIZE; i++)
        getgrades(&students[i]);	//按地址传递结构

    //get average grade, and assign it to student->average
    for(int i = 0; i < CSIZE; i++)
        getaverage(&students[i]);

    //print struct infomation
    for(int i = 0; i < CSIZE; i++)
        showsinfo(&students[i]);

    float total = 0;
    //get the class average grade
    for(int i = 0; i < CSIZE; i++)
    {
    	total += students[i].average;
    }
    printf("class average is %.2f.\n", (float)total/CSIZE);

    return 0;
}

void getgrades(struct Student * student)
{
    for(int i = 0; i < GRADELEN; i++)
    {
        printf("Please enter grade %d for %s %s: \n", i+1, student->names.firstname, student->names.lastname);
        //scanf("%f", &student->grade[i]);
        while(scanf("%f", &student->grade[i]) != 1)
            while(getchar()!='\n') continue;

        while(getchar()!='\n') continue;
    }
    puts("");
}

void getaverage(struct Student * student)
{
    float total = 0;
    for(int i = 0; i < GRADELEN; i++)
    {
        total+= student->grade[i];
    }
    student->average = (float)total/GRADELEN;
}

void showsinfo(struct Student * student)
{
    printf("%s %s %.2f %.2f %.2f %.2f\n", student->names.firstname, student->names.lastname,
            student->grade[0], student->grade[1], student->grade[2], student->average);
}
