/*********************Exercise********************/
//#2
#include <stdio.h>

//int main(void)
//{
//    int input;
//    int j = 0;
//    printf("Please enter an integer: \n");
//    scanf("%d", &input);
//
//    while(j<=10){
//        printf("%5d\n",input+j);
//        j++;
//    }
//
//
//    return 0;
//}

int main(void)
{
    int i, j;
    printf("Please enter an integer: \n");
    scanf("%d",&i);
    j = 0;

    while(j<=10)
    {
        printf("%5d\n",i++);
        //i++;
        j++;

    }
    return 0;
}
