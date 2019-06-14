//#3
//编写程序，读取整数直到用户输入0. 输入结束后，报告用户输入的偶数(不包括0)个数，
//这些偶数的平均值。输入的奇数个数及奇数的平均值
#include <stdio.h>

int main(void)
{
	int input;
	int odd_num_cnt = 0;
	int even_num_cnt = 0;

	int odd_sum = 0, even_sum = 0;
	float odd_everage = 0, even_everage = 0.0;

	printf("Enter some integer numbers:\n");

	while(scanf("%d", &input) == 1 && input!= 0)
	{
		//判定input是否为偶数
		if(input%2 == 0)
		{
			even_num_cnt++;
			even_sum +=input;
		}
		else //input是奇数
		{
			odd_num_cnt++;
			odd_sum +=input;
		}
	}
	even_everage = (float) even_sum/even_num_cnt;
	odd_everage = (float) odd_sum/odd_num_cnt;

	printf("Total input %d even numbers, and average of even number is %.1f\n", 
		even_num_cnt, even_everage);
	printf("Total input %d odd numbers, and average of odd number is %.1f\n", 
		odd_num_cnt, odd_everage);

	return 0;

}
