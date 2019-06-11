//#13
//创建一个包含8个元素的int类型数组，分别把元素设置为2的前8次幂。
//for 循环设置数组元素的值，do while循环显示数组元素的值
#include<stdio.h>
#include<math.h>

int main(void)
{
    int array[8];
    int power = 1;
    int j =0;

//    for(int i=0; i<8; i++)
//    {
//        array[i] = pow(2,i);
//    }
//
//
//    do{
//        printf("%d ", array[j]);
//        j++;
//    }while(j<8);

    for(int i = 0; i<8; i++)
    {
        power*=2;
        array[i] = power;
    }

    do{
        printf("%d ", array[j]);
        j++;
    }while(j<8);

    return 0;
}
