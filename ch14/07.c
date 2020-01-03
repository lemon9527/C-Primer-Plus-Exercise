/*********************************Chapter 14 Exercise***************************/
//#07 修改14.14 booksave.c, 允许用户删除记录或修改记录
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  10

struct book{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char *s_gets(char * st, int n);
void modify(struct book *);

int main(void)
{
    struct book library[MAXBKS];    //结构数组
    int count = 0;
    int index, filecount, ch;
    FILE * pbooks;
    int size = sizeof(struct book);

    if((pbooks = fopen("book.dat", "rb")) == NULL)
    {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }

    rewind(pbooks); //定位到文件开始处
    while(count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n", library[count].title, library[count].author,
            library[count].value);
        printf("Please select an action:\n");
        printf("n) next\n");
        printf("d) delete\n");
        printf("m) modify\n");

        ch = tolower(getchar());
        while(getchar()!='\n') continue;
        switch (ch)
        {
            case ('n'):
                break;
            case ('m'):
                modify(&library[count]);   //按结构地址传递结构
                break;
            case ('d'):
                count--;
                break;
            default:
                break;
        }
        count++;
    }

    fclose(pbooks);

    if(count==MAXBKS)
        printf("The file 'book.dat' is full.\n");
    else
    {
        puts("Please add new book title.");
        puts("Press [enter] at the start of a line to stop.");
        while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
            && library[count].title[0] != '\0')
        {
            puts("Now enter the author.");
            s_gets(library[count].author, MAXAUTL);
            puts("Now enter the value.");
            scanf("%f", &library[count++].value);
            while(getchar()!='\n')
                continue;           //清理输入行
            if(count < MAXBKS)
                puts("Enter the next title.");
        }
    }

    if((pbooks = fopen("book.dat", "wb")) == NULL)
    {
        fprintf(stderr, "Could not open file 'book.dat' for write.\n");
        exit(EXIT_FAILURE);
    }

    if(count>0)
    {
        puts("Here is the list of your books:");
        for(index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n", library[index].title,
                library[index].author, library[index].value);
        }
        fwrite(library, size, count, pbooks);
    }
    else
        puts("No books? Too bad.\n");
    puts("Bye.\n");
    fclose(pbooks);

    return 0;
}

void modify(struct book * PBK)
{
    puts("Please enter the new title for this book.");
    s_gets(PBK->title, MAXTITL);
    puts("Now enter the new author for this book.");
    s_gets(PBK->author, MAXAUTL);
    puts("Now enter the new value for this book.");
    scanf("%f", &PBK->value);    //这里 PBK->value 即相当于 library[count].value, 是一个float变量，前面要加&
    while(getchar()!='\n')
        continue;

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
