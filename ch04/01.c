//1
#include <stdio.h>

int main(void)
{
    char firstname[20];
    char lastname[20];

//    printf("Please enter your first name:\n");
//    scanf("%s", firstname);
//    printf("Please enter your last name:\n");
//    scanf("%s", lastname);

    printf("Please enter your first name and last name (e.g.: Lemon Liu)\n");
    scanf("%s %s", firstname, lastname);

    printf("Hello, %s %s", firstname, lastname);

    return 0;
}
