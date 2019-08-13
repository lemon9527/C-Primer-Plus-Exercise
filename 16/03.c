/***********************************Chapter 16***********************************************/
//03 极坐标用向量的模(即向量的长度)和向量相对x轴顺时针旋转的角度来描述该向量。
//   直角坐标用向量的x轴和y轴的坐标来描述, 编写一个程序，读取向量的模和角度，
//   然后显示x轴和y轴的坐标，如下是数学公式
//   x = r*cos A   y = r*sin A
//  需要一个函数来完成转换，该函数接受一个包含极坐标的结构，并返回一个包含直角坐标的结构

#include <stdio.h>
#include <math.h>
#define CLEARINPUT while(getchar()!='\n') continue

typedef struct polar_coordinates {
    double r;
    double A;
} Polar;

typedef struct Cartesian_coordinates{
    double x;
    double y;
} Cartesian;

Cartesian convert(Polar coords);

int main(void)
{
    Polar polar_coord;
    Cartesian cartesian_coord;

    puts("Please enter r:");
    scanf("%lf", &polar_coord.r);
    CLEARINPUT;
    puts("Please enter A (angel in radian):");
    scanf("%lf", &polar_coord.A);
    CLEARINPUT;

    cartesian_coord = convert(polar_coord);
    puts("cartesian_coordinates as below:");
    printf("x = %.2f\n", cartesian_coord.x);
    printf("y = %.2f\n", cartesian_coord.y);

    return 0;
}

Cartesian convert(Polar coords)
{
    Cartesian temp;

    temp.x = coords.r * cos(coords.A);
    temp.y = coords.r * sin(coords.A);

    return temp;
}
