/******************Chapter 12 Exercise********************/
//#06 生成1000个1～10范围内的随机数，不保存或打印这些数字。仅打印每个数字
//出现的次数。用10个不同的种子值运行，生成的数字出现的次数是否相等？
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 1000

void generate_and_show(int * num, int size);

int main(void)
{
	int num[1000];
	srand((unsigned int)time(0));

	generate_and_show(num, SIZE);

	return 0;

}

void generate_and_show(int * num, int size)
{
	int i = 0;

	//generate 1000 int array
	for(i=0; i<size; i++)
		num[i] = rand()%10+1;

	//计算每个数出现的次数
	int numcount[1000] = {0};
	//对num[1000]遍历一边
	//numcount 数组的下标代表num数组里的数字，该数字出现一次，对应的numcount数组+1
	for(i=0; i<size; i++)
		numcount[num[i]]++;

	//遍历numcount数组，pass值为0的元素，大于0的元素，下标代表num数组里的数字，对应值
	//代表该数字在num数组出现的频率
	for(i=0; i<size; i++)
	{
		if(numcount[i]>0)
		{
			printf("%4d show %4d times\n", i, numcount[i]);
		}
	}
}
