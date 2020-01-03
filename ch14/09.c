//09.c

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define SEATSQTY    12
#define NLEN        20
#define FLIGHT      4


struct seat {
    unsigned int seatnum;
    bool is_booked;
    bool is_confirmed;
    char fname[NLEN];
    char lname[NLEN];
};

struct Flight {
    unsigned int id;
    struct seat seats[SEATSQTY];
};

struct Flight flights[FLIGHT] ={
    {102, {}},
    {311, {}},
    {444, {}},
    {519, {}}
};

static struct Flight * flight;
int size = sizeof(struct Flight);
FILE *fp;

void print_top_menu(void);
char * s_gets(char *st, int n);
void countempty(void);
void listempty(void);
void showalphabetical(void);
void assigncustomer(void);
void deleteassignment(void);
void flightmenu();

int main(void)
{
    int ch = 0;
    extern struct Flight * flight;
    struct Flight tempflight;

    //初始化座位编号，并设置为没有预定
    for(int i=0; i<FLIGHT; i++)
    {
        for(int j=0; j<SEATSQTY; j++)
        {
            flights[i].seats[j].seatnum = j;
            flights[i].seats[j].is_booked = false;
        }
    }
    //打开文件流
    if((fp = fopen("assignment.dat", "a+b")) == NULL)
    {
        fprintf(stderr, "Could not open file 'assignment.dat'.\n");
        exit(EXIT_FAILURE);
    }
    rewind(fp); //定位到文件开始处
    //从文件里读取之前保存的信息到结构数组
    while(fread(&tempflight, size, 1, fp) == 1)
    {
        for(int i=0; i<FLIGHT; i++)
        {
            if(tempflight.id == flights[i].id)
            {
                flights[i] = tempflight;
                break;
            }
        }
    }

    //mainloop
    while(ch != 'e' && ch != 'E')
    {
        print_top_menu();
        if((ch=getchar())!= '\n')
            while(getchar() != '\n') continue;  //clear input stream
        switch (ch)
        {
        case 'a':
            flight = &flights[0];
            break;      
        case 'b':
            flight = &flights[1];
            break;      
        case 'c':
            flight = &flights[2];
            break;
        case 'd':
            flight = &flights[3];
            break;
        case 'e':
            goto Exit;
        default:
            puts("Invalid input, try again.");
            continue;
        }

        flightmenu();
    }

    Exit:
    fclose(fp);
    if((fp = fopen("assignment.dat", "wb")) == NULL)
    {
        fprintf(stderr, "Could not open file 'assignment.dat'.\n");
        exit(EXIT_FAILURE);
    }
    if (fwrite(flights, size, FLIGHT, fp) != FLIGHT)
	{
		fprintf(stderr, "Error writing to file 'assignment.dat'.\n");
	}
    puts("Bye.");
    return 0;
}

void flightmenu(void)
{
    int ch =0;
    extern struct Flight * flight;
    while(ch != 'f' && ch != 'F')
    {
        printf("You have selected flight number: %d.\n", flight->id);
        puts("To choose a function, enter its letter label:");
        puts("a) Show number of empty seats");
        puts("b) Show list of empty seats");
        puts("c) Show alphabetical list of seats");
        puts("d) Assign a customer to a seat assignment");
        puts("e) Delete a seat assignment");
        puts("f) Quit");
        if((ch = getchar()) != '\n')
            while(getchar() != '\n') continue;  //clear input stream
        switch(ch)
        {
            case 'a':
                countempty();
                break;
            case 'b':
                listempty();
                break;
            case 'c':
                showalphabetical();
                break;
            case 'd':
                assigncustomer();
                break;
            case 'e':
                deleteassignment();
                break;
            case 'f':
                break;
            default:
                puts("Invalid input, try again.");
        }
    }
}


void print_top_menu(void)
{
	puts("To choose a flight, enter its letter label:");
	puts("a) 102");
	puts("b) 311");
	puts("c) 444");
	puts("d) 519");
	puts("e) Quit");

	return;
}

void countempty(void)
{
    extern struct Flight * flight;
    unsigned int emptyqty = 0;
    for(int i=0; i<SEATSQTY; i++)
    {
        if(flight->seats[i].is_booked == false)
            emptyqty++;
    }
    printf("Total %d empty seats.\n", emptyqty);
}

void listempty(void)
{
    extern struct Flight * flight;
    unsigned int emptyqty = 0;
    printf("the list of empty seat on flight %d.\n", flight->id);
    for(int i=0; i<SEATSQTY; i++)
    {
        if(flight->seats[i].is_booked == false)
        {
            printf("seat num: %d\n", flight->seats[i].seatnum);
            emptyqty++;
        }  
    }
    if(!emptyqty)
        puts("Sorry, No empty seat.");
}

void showalphabetical(void)
{
    extern struct Flight * flight;
    printf("the alphabetical list of empty seat on flight %d.\n", flight->id);
    printf("%-*s %-*s %-12s\n", NLEN, "First Name", NLEN, "Last Name", "Seat Number");
    for(int i=0; i<SEATSQTY; i++)
    {
        if(flight->seats[i].is_booked)
            printf("%-*s %-*s %-12d %-12s\n", NLEN, flight->seats[i].fname, NLEN, flight->seats[i].lname, flight->seats[i].seatnum,
                flight->seats[i].is_confirmed? "Confirmed": "Unconfirmed");
    }
}

void assigncustomer(void)
{
    extern struct Flight * flight;
    puts("Please enter the number of seat:");
    int tempnum;
    while(scanf("%d", &tempnum) && (tempnum < 0 || tempnum > 12) )
    {
        puts("Invalid input, try again.");
    }
    while(flight->seats[tempnum].is_booked)
    {
        puts("taken, try another.");
        scanf("%d", &tempnum);
    }
    flight->seats[tempnum].seatnum = tempnum;
    while(getchar() != '\n')    continue;

    puts("Please enter first name:");
    s_gets(flight->seats[tempnum].fname, NLEN);
    puts("Please enter last name:");
    s_gets(flight->seats[tempnum].lname, NLEN);
    flight->seats[tempnum].is_booked = true;
    
}

void deleteassignment(void)
{
    extern struct Flight * flight;
    puts("Please enter which one you want to delete:");
    int tempnum;
    while(scanf("%d", &tempnum) && (tempnum < 0 || tempnum > 12) )
    {
        puts("Invalid input, try again.");
    }
    while(getchar()!='\n') continue;
    while(flight->seats[tempnum].is_booked == false)
    {
        puts("No booked, try another:");
        scanf("%d", &tempnum);
    }
    puts("Here is the seat assignment you selected:");
    printf("%-*s %-*s %-12d\n", NLEN, flight->seats[tempnum].fname, NLEN, flight->seats[tempnum].lname, flight->seats[tempnum].seatnum);
    puts("Are you sure to delete it? Enter [n/N] to abort ");
    puts("or other key to continue.");
    int ch = 0;
    if((ch = getchar()) !='\n')
        while(getchar() != '\n') continue;

    if(ch == 'n' || ch == 'N')
    {
        puts("Aborting delete.");
        return;
    }

    flight->seats[tempnum].is_booked = false;
    flight->seats[tempnum].is_confirmed = false;
    strcpy(flight->seats[tempnum].fname, "");
    strcpy(flight->seats[tempnum].lname, "");
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
