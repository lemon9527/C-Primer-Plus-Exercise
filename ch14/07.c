/*********************************Chapter 14 Exercise***************************/
//#07 修改14.14 booksave.c, 允许用户删除记录或修改记录
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  10  //最大书籍数量

char * s_gets(char *st, int n);

struct book{
   char title[MAXTITL];
   char author[MAXAUTL];
   float value;
};

void editbook(struct book *);

int main(void)
{
   struct book library[MAXBKS];    //结构数组
   int count = 0;
   int index, filecount, ch;
   FILE * pbooks;
   int size = sizeof(struct book);

   if((pbooks = fopen("book.dat", "a+b")) == NULL)
   {
       fputs("Can't open book.dat file\n", stderr);
       exit(1);
   }

   rewind(pbooks); //定位到文件开头
   //如下while循环每次把一个结构读取到结构数组中， 档数组满或者读完文件时停止
   while (count < MAXBKS &&fread(&library[count],size, 1, pbooks) == 1)
   {
       if(count == 0)
           puts("Current contents of book.dat:");
       printf("%s by %s: $%.2f\n", library[count].title,
              library[count].author, library[count].value);

       printf("Please select an action: \n"
       			"[n] next record [d] delete this record "
       			"[m] modify this record.\n");
       ch=getchar();
       while(getchar()!='\n') continue;
       switch(ch)
       {
       		case ('n'):
       		case ('N'):
       			break;
       		case ('m'):
       		case ('M'):
       			editbook(&library[count]);	//按结构地址传递结构
       			break;
       		case ('d'):
       		case ('D'):
       			count--;
       			break;
       		default:
       			break;
       }

       count++;
   }
   filecount = count;
   if(count == MAXBKS)
   {
       fputs("The book.dat file is full.", stderr);
       exit(2);
   }

   puts("Please add new book titles.");
   puts("Press [enter] at the start of a line to stop.");
   //这个while循环提示并接受用户的输入， 当数组已满或者用户在第一行开始按下enter时，循环结束
   while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
         && library[count].title[0] != '\0')
   {
       puts("Now enter the author.");
       s_gets(library[count].author, MAXAUTL);
       puts("Now enter the value.");
       scanf("%f", &library[count++].value);
       while(getchar()!='\n')
           continue;   //清理输入行
       if(count < MAXBKS)
           puts("Enter the next title.");
   }

   if(count > 0)
   {
       puts("Here is the list of your books:");
       for(index = 0; index < count; index++)
           printf("%s by %s: $%.2f\n", library[index].title,
                  library[index].author, library[index].value);

       //打印到文件
       fwrite(&library[filecount], size, count - filecount, pbooks);
   }
   else
       puts("No books? Too bad.\n");

   puts("Bye.\n");
   fclose(pbooks);

   return 0;
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

void editbook(struct book * BK)
{
	puts("Please enter new title for this book:");
	s_gets(BK->title, MAXTITL);
	puts("Please enter new author for this book:");
	s_gets(BK->author, MAXAUTL);
	puts("Please enter new value for this book:");
	scanf("%f", &BK->value);

	while(getchar()!='\n') continue;
}
