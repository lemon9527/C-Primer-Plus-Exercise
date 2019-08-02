/*********************************Chapter 14 Exercise***************************/
//#03
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  100

struct book {       //建立book 结构模板
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char *s_gets(char * st, int n);
void titlesort(struct book * books[], int count);
//void valuesort(struct book *, int count);

int main(void)
{
    struct book * library[MAXBKS];    //声明book结构模板类型的指针数组
    //结构体指针其实是一个指针，它存储的是指向某个结构体的“地址”，
    //所以结构体指针数组存储的其实是指向一组结构体的“地址”数组，
    //它本身并不包含结构体的具体内容（没有被分配内存）
    /****************************/
    //所以当用到他们时，要么重定向，比如：
	//d=&b; //让d指向b，d存储的是b的地址，这样就能通过d来调用b了
	//要么用malloc为他们分配内存：
	//d=(struct h *)malloc(sizeof(struct h));
	//这样d就指向系统为其分配的一块内存，其内容就是struct h中的东西

    char temp[MAXTITL];
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while(count < MAXBKS && s_gets(temp, MAXTITL) != NULL
          && temp[0] != '\0')
    {
    	//结构体指针数组存储的其实是指向一组结构体的“地址”数组， 没有分配内存，需要重定向
    	//library[count]， count =0 时，即时第一个结构指针
    	library[count] = (struct book *) malloc(sizeof (struct book));
    	strncpy(library[count]->title, temp, MAXTITL);

        printf("Now enter the author.\n");
        s_gets(library[count]->author, MAXAUTL);

        printf("Now enter the value.\n");
        scanf("%f", &library[count]->value);    //获取输入的value后，递增count
        while(getchar()!='\n')
            continue;       //清理输入行
        if(count < MAXTITL)
            printf("Enter the next title.\n");

        count++;
    }

    //output list of books
    if(count > 0)
    {
        //by input order
        printf("Here is the list of your books (in the order of input):\n");
        for(index = 0; index < count; index++)
            printf("%s by %s : $%.2f\n", library[index]->title, library[index]->author,
                   library[index]->value);

        //sorted by title
        printf("Here is the list of your books (in the order of title):\n");
        titlesort(library, count);
        for(index = 0; index < count; index++)
            printf("%s by %s : $%.2f\n", library[index]->title, library[index]->author,
                   library[index]->value);

    }
    else
        printf("No books? Too bad.\n");

    return 0;
}

void titlesort(struct book * books[], int count)	//也可以写作void titlesort(struct book ** books, int count)
{
    struct book * temp;
    for(int i = 0; i < count; i++)
    {
        for(int j = i+1; j < count; j++)
        {
            if(tolower(books[i]->title[0]) > tolower(books[j]->title[0]))
            {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
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
