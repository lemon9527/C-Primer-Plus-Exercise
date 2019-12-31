//03.c 
//修改程序14.2中的图书目录程序，使其按照输入图书的顺序输出图书的信息，
//然后按照标题字母的顺序输出图书信息，最后按照价格升序输出图书的信息。
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  100

struct book{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char *s_gets(char *st, int n);
void title_sort(struct book *[], int count);
void value_sort(struct book *[], int count);

int main(void)
{
    struct book * library[MAXBKS];//声明book结构类型的指针数组, 需要用malloc分配内存

    char temp[MAXTITL];
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to quit.\n");
    while(count < MAXBKS && s_gets(temp, MAXTITL) != NULL
        && temp[0] != '\0')
    {
        printf("Now enter the author.\n");
        //library[count], count = 0 时，即第一个结构指针
        library[count] = (struct book *)malloc(sizeof(struct book));
        strcpy(library[count]->title, temp);
        s_gets(library[count]->author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count]->value);
        count++;
        while(getchar()!='\n')
            continue;       //clear input stream
        if(count < MAXBKS)
            printf("Enter the next title.\n");
    }

    if(count > 0)
    {
        //print books by input sequence
        printf("Here is the list of your books by input sequence:\n");
        for(index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index]->title, 
                library[index]->author, library[index]->value);
        
        //print books by title
        printf("Here is the list of your books by 1st letter of title:\n");
        title_sort(library, count);
        for(index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index]->title, 
                library[index]->author, library[index]->value);

        //print books by value
        printf("Here is the list of your books by value:\n");
        value_sort(library, count);
        for(index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index]->title, 
                library[index]->author, library[index]->value);
    }
    else
        printf("No books? Too bad.\n");    
}

void title_sort(struct book * books[], int count)
{
    int i, j;
    struct book * temp;
    for(i = 0; i < count; i++)
    {
        for(j = i+1; j < count; j++)
        {   //两个title 首字母比较，较大的说明顺序靠后，
            if(tolower(books[i]->title[0]) > tolower(books[j]->title[0]))
            {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}

void value_sort(struct book * books[], int count)
{
    int i, j;
    struct book * temp;
    for(i = 0; i < count; i++)
    {
        for(j = i+1; j < count; j++)
        {   //两个value 比较，books[i] 与value小的交换
            if(tolower(books[i]->value) > tolower(books[j]->value))
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
