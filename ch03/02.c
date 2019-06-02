//Chapter 3 Exercise 2:
// Write a program asks you enter an ASCII code value, such as 66, and
// then prints the character having that ASCII value.

#include <stdio.h>

int main(void)
{
    int ASCII_code;
    printf("Please Enter an ASCII code (from 0~127): \n");
    scanf("%d", &ASCII_code);

    printf("Character for %d is %c\n", ASCII_code, ASCII_code);

    return 0;
}
