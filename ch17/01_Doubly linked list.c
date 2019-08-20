/***************************Chapter 17 Exercise ********************************/
//01 修改程序清单17.2 使其能正序也能逆序显示电影列表, 一种方法是修改链表定义，可以用
//双向列表，一种是用递归, 本例使用双向链表
#include <stdio.h>
#include <stdlib.h>     //提供malloc()原型
#include <string.h>     //提供strcpy()原型
#include "list.h"
#define TSIZE 45

char *s_gets(char *st, int n);
void showmovie(Item item);

int main(void)
{
    List movies;
    Item temp;

    //初始化
    InitializeList(&movies);
    if(ListIsFull(&movies))
    {
        fprintf(stderr, "No memory available! Bye!\n");
        exit(1);
    }

    //获取用户输入并存储
    puts("Enter first movie title:");
    while(s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {
        puts("Enter your rating <0~10>:");
        scanf("%d", &temp.rating);
        while(getchar()!='\n')
            continue;
        if(AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        if(ListIsFull(&movies))
        {
            puts("The list is now full.");
            break;
        }
        puts("Enter next movie title (empty line to quit):");
    }

    //显示
    if(ListIsEmpty(&movies))
        printf("No data entered. ");
    else
    {
        //正序显示
        printf("Here is the movie list(正序显示):\n");
        Traverse(&movies, showmovie);
        printf("Here is the movie list(逆序显示):\n");
        Traverse_R(&movies, showmovie);
    }

    //清理
    EmptyTheList(&movies);
    printf("Bye!\n");
    return 0;
}

void showmovie(Item item)
{
    printf("Movie: %s Rating: %d\n", item.title, item.rating);
}

 char * s_gets(char *st, int n)
 {
 	char * ret_val;
 	char * find;

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
