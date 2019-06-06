//#8
//编写一个程序，显示求模运算的结果
//Enter an integer to serve as the second operand: 256
//Now enter the first operand: 438
//438 % 256 is 182
#include <stdio.h>

int main(void)
{
    int First_operand;
    int Second_operand;

    printf("Enter an integer to serve as the second operand: \n");
    scanf("%d", &Second_operand);
    printf("Now enter the first operand: \n");
    scanf("%d", &First_operand);

    while(First_operand>0){
        printf("%d %% %d is %d\n\n", First_operand, Second_operand, First_operand%Second_operand);

        printf("Now enter next number as the first operand: \n");
        scanf("%d", &First_operand);
    }

    printf("Done.");

    return 0;
}
