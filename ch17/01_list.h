//list.h --简单链表类型的头文件

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <stdbool.h>

#define TSIZE   45  //储存电影名的数组大小

struct film{
    char title[TSIZE];
    int rating;
};

typedef struct film Item;

typedef struct node{
    Item item;
    struct node * prev;
    struct node * next;
} Node;

typedef Node * List;    //定义List为指向 struct node结构类型的指针

//函数原型

//操作：       初始化一个列表
//前提条件：   plist指向一个链表
//后置条件：   链表初始化为空
void InitializeList(List * plist);

//plist指向一个已经初始化的链表
bool ListIsEmpty(const List *plist);

bool ListIsFull(const List *plist);

unsigned int ListItemCount(const List *plist);

bool AddItem(Item item, List * plist);

void Traverse(const List *plist, void(*pfun)(Item item));
void Traverse_R(const List *plist, void(*pfun)(Item item));

void EmptyTheList(List *plist);


#endif // LIST_H_INCLUDED
