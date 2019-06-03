/************************Exercise 7***************************/
//1英寸相当于2.54cm, 编写一个程序，提示用户输入年龄，身高(inch),然后以厘米为单位显示身高
int main(void)
{
    float height;
    float CM_PER_INCH = 2.54;

    printf("Please enter your height by inch:");
    scanf("%f", &height);

    printf("Your height is %f cm.\n",height*CM_PER_INCH);

    return 0;
}
