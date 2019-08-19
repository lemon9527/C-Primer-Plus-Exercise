 /***************************Chapter 17 Exercise ********************************/
//01 修改程序清单17.2 使其能正序也能逆序显示电影列表, 一种方法是修改链表定义，可以用
//双向列表，一种是用递归, 本例使用递归方法
#include <stdio.h>
#include <stdlib.h>     //提供malloc()原型
#include <string.h>     //提供strcpy()原型
#define TSIZE 45

struct film{
    char title[TSIZE];
    int rating;
    struct film * next; //指向链表中的下一个结构
};

char * s_gets(char *st, int n);
void list_films(struct film * film_ptr);
void reverse_list_films(struct film * film_ptr);

int main(void)
{
    struct film * head = NULL;
    struct film * prev, * current;
    char input[TSIZE];

    //收集并储存信息
    puts("Enter first movie title:");
    while(s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *) malloc(sizeof(struct film));
        if(head == NULL)
            head = current;
        else
            prev->next = current;   //每个结构的指针存在上一个结构的next成员中
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while(getchar()!='\n')
            continue;
        puts("Enter next movie title (empty line to quit):");
        prev = current;
    }

    //显示电影列表
    if(head == NULL)
        printf("No data entered. \n");
    else
        printf("Here is the movie list:\n");

    current = head;
    list_films(current);
    printf("Here is the movie list (Reversed):\n");
    current = head;
    reverse_list_films(current);


    //完成任务，释放分配的内存
    current = head;
    while(current != NULL)
    {
        current = head;
        head = current->next;
        free(current);
    }
    printf("Bye!\n");

    return 0;
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

 void reverse_list_films(struct film * film_ptr)
{
    if(film_ptr == NULL)
        return;
    else
    {
        reverse_list_films(film_ptr->next);
        printf("Movie: %s Rating: %d\n", film_ptr->title, film_ptr->rating);
    }
}

void list_films(struct film * film_ptr)
{
    while(film_ptr!=NULL)
    {
        printf("Movie: %s Rating: %d\n", film_ptr->title, film_ptr->rating);
        film_ptr = film_ptr->next;
    }
}
