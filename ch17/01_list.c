//list.c --支持链表操作的函数
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//局部函数原型
static void CopyToNode(Item item, Node * node);

//接口函数

//把链表设置为空
void InitializeList(List *plist)
{
    *plist = NULL;
}

//如果链表为空，返回true
bool ListIsEmpty(const List *plist)
{
    if(*plist == NULL)
        return true;
    else
        return false;
}

//如果链表已满，返回true
//尝试为新项分配空间，如果失败，说明链表已满
bool ListIsFull(const List *plist)
{
    Node * pt;
    bool full;

    pt = (Node *)malloc(sizeof(Node));
    if(pt == NULL)
        full = true;
    else
        full = false;
    free(pt);

    return full;
}

//返回节点的数量
unsigned int ListItemCount(const List *plist)
{
    unsigned int count = 0;
    Node * pnode = *plist;    //设置链表的开始

    while(pnode != NULL)
    {
        ++count;
        pnode = pnode->next;
    }
    return count;
}

//创建储存项的节点，并添加至由plist指向的链表结尾, 双向链表
bool AddItem(Item item, List *plist)
{
    Node * pnew;
    Node * scan = *plist;

    pnew = (Node *)malloc(sizeof(Node)); //为新节点分配空间
    if(pnew == NULL)
        return false;

    CopyToNode(item, pnew);
    pnew->prev = NULL;
    pnew->next = NULL;

    if(scan == NULL)
    {
        *plist = pnew;  //空链表，所以把pnew放在链表开头
    }

    else
    {
        while(scan->next != NULL)
            scan = scan->next;
        scan->next = pnew;
        scan->next->prev = scan;
    }
    return true;
}

//顺序访问每个节点并执行pfun指向的函数
void Traverse(const List *plist, void(*pfun)(Item item))
{
    Node * pnode = *plist;   //设置链表的开始

    while(pnode!=NULL)
    {
        (*pfun)(pnode->item);   //把函数应用到链表中的项
        pnode = pnode->next;
    }
}

//逆序访问每个节点并执行pfun指向的函数
void Traverse_R(const List *plist, void(*pfun)(Item item))
{
    Node * pnode = *plist;   //设置链表的开始
    Node * pnode_end;

    //找到链表结尾
    while(pnode!=NULL)
    {
        pnode_end = pnode;
        pnode = pnode->next;
    }

    while(pnode_end!=NULL)
    {
        (*pfun)(pnode_end->item);   //把函数应用到链表中的项
        pnode_end = pnode_end->prev;
    }
}

//释放有malloc()分配的内存
//设置链表指针为NULL
void EmptyTheList(List *plist)
{
    Node * psave;

    while(*plist != NULL)
    {
        psave = (*plist)->next;
        free(*plist);
        *plist = psave;
    }
}

//局部函数定义，把一个项拷贝到节点中
static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item; //拷贝结构
}

