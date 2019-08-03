/*********************************Chapter 14 Exercise***************************/
//#08 巨人航空公司座位预定
//a. 使用一个内含12个结构的数组，每个结构包括：座位编号，座位是否预定，预定人名，预定人姓
//b. 显示如下菜单
//
//c. 程序能成功执行上面菜单，选择d或者e要提示用户额外输入，每个选项都能让用户中止输入
//d. 执行特定程序后，再次显示菜单，除非用户选择f
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SEATSIZE 12
#define MAXNAME 20

struct Seat {
	int number;
	bool isresvere;
	char firstname[MAXNAME];
	char lastname[MAXNAME];
};

int size = sizeof(struct Seat);
struct Seat seats[SEATSIZE];
FILE *fp;

void printmenu(void);
void countempty(void);
void listempty(void);
void showalphabetical(void);
void assigncustomer(void);
void deleteassignment(void);

char * s_gets(char *, int n);

int main(void)
{
	int ch = 0;

	struct Seat tmp;

	//初始化所有座位id号及是否预定
	for(int i = 0; i < SEATSIZE; i++)
	{
		seats[i].number = i;
		seats[i].isresvere = false;
	}

	//打开文件流
	if((fp = fopen("assignment.dat", "a+b")) == NULL)
	{
		fprintf(stderr, "Could not open file 'assignment.dat'.\n");
		exit(EXIT_FAILURE);
	}

	rewind(fp);
	//read saved data into seats array
	while(fread(&tmp, size, 1, fp) == 1)
	{
		seats[tmp.number] = tmp;
	}

	// main loop
	while( ch != 'f' && ch != 'F')
	{
		printmenu();
		if((ch = getchar()) != '\n')
			while(getchar()!='\n') continue;
		switch(ch)
		{
			case 'a':
			case 'A':
				countempty();
				break;
			case 'b':
			case 'B':
				listempty();
				break;
			case 'c':
			case 'C':
				showalphabetical();
				break;
			case 'd':
			case 'D':
				assigncustomer();
				break;
			case 'e':
			case 'E':
				deleteassignment();
				break;
			default:
				puts("Invalid input, try again!");
		}
		puts("");
	}

	fclose(fp);
	puts("Bye.");
	
	return 0;
}

void printmenu(void)
{
	puts("To choose a function, enter its letter label:");
	puts("a) Show number of empty seats");
	puts("b) Show list of empty seats");
	puts("c) Show alphabetical list of seats");
	puts("d) Assign a customer to a seat assignment");
	puts("e) Delete a seat assignment");
	puts("f) Quit");
}

void countempty(void)
{
	int emptycount = 0;
	for(int i = 0; i < SEATSIZE; i++)
	{
		if(seats[i].isresvere == false)
			emptycount++;
	}
	printf("now %d empty seats.\n", emptycount);
}
void listempty(void)
{
	int freeseatcnt = 0;
	puts("the list of empty seats:");
	for(int i = 0; i < SEATSIZE; i++)
	{
		if(seats[i].isresvere == false)
		{
			printf("seat number: %d\n", seats[i].number);
			freeseatcnt++;
		}
	}
	if(!freeseatcnt)
		puts("Sorry, no empty seat.");
}
void showalphabetical(void)
{
	printf("%-*s %-*s %-12s\n", MAXNAME, "Last Name", MAXNAME, "First Name", 
		"Seat Number");
	for(int i = 0; i < SEATSIZE; i++)
	{
		if(seats[i].isresvere == true)
			printf("%-*s %-*s %-12d\n", MAXNAME, seats[i].lastname, MAXNAME, 
				seats[i].firstname,	seats[i].number);
	}
}
void assigncustomer(void)
{
	puts("please enter the seat number:");
	int tempnum;
	while(scanf("%d", &tempnum) && (tempnum < 0 || tempnum >= 12))
	{
		puts("Invalid number, (0~11); try another:");
	}
	while(seats[tempnum].isresvere == true)
	{
		puts("taken, try another:");
		scanf("%d", &tempnum);
	}
	seats[tempnum].number = tempnum;
	while(getchar()!='\n') continue;

	puts("please enter customer's firstname:");
	s_gets(seats[tempnum].firstname, MAXNAME);
	puts("please enter customer's lastname:");
	s_gets(seats[tempnum].lastname, MAXNAME);

	seats[tempnum].isresvere = true;
	//save data to file, printf to file
	fwrite(&seats[tempnum], size, 1, fp);


	puts("customer seat reservaration is done!");
}
void deleteassignment(void)
{
	puts("please enter the number of seat that you want to delete:");
	int tempnum;
	while(scanf("%d", &tempnum) && (tempnum < 0 || tempnum >= 12))
	{
		puts("Invalid number, (0~11); try another:");
	}
	while(getchar()!='\n') continue;
	if(!seats[tempnum].isresvere)
	{
		puts("This seat is not currently assigned. Aborting.");
		return;
	}
	puts("Here is the seat assignment you have selected:");
	printf("FIRST NAME: %s LAST NAME: %s Seat Number: %d\n",
		seats[tempnum].firstname, seats[tempnum].lastname, seats[tempnum].number);
	puts("Do you want to delete it? Enter [n/N] to abort "
		"or any other key to continue.");
	int ch = 0;
	if((ch=getchar()) != '\n')
		while(getchar()!='\n') continue;
	if(ch == 'n' || ch == 'N')
	{
		puts("Aborting seat delete.");
		return;
	}
	seats[tempnum].isresvere = false;
	seats[tempnum].firstname[0] = '\0';
	seats[tempnum].lastname[0] = '\0';

	//save data to file, printf to file
	fwrite(&seats[tempnum], size, 1, fp);
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
