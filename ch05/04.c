//#4
//输入身高(cm), 并分别以厘米和英寸为单位显示该值，允许有小数部分，输入非正值退出
#include <stdio.h>

const float CM_PER_INCH = 2.54;
const int INCH_PER_FEET = 12;

int main(void)
{
    float height_cm;
    int height_feet;
    float height_inch;
    float inches;

    printf("Please enter your height(cm) (0 to quit): \n");
    scanf("%f", &height_cm);

    while(height_cm>0){
        height_inch = height_cm/CM_PER_INCH;
        height_feet = (int)(height_inch / INCH_PER_FEET);
        inches = height_inch - height_feet * INCH_PER_FEET;
        printf("%1.2f cm = %d feet, %1.2f inches.\n", height_cm, height_feet,  inches);

        printf("Please enter your height(cm) (0 to quit): \n");
        scanf("%f", &height_cm);
    }

    return 0;
}
