//#7
//编写一个程序，提示用户输入一周工作的总时数，然后打印工资总额，税金数及净收入。
//a. 基本工资 = 10美元/小时
//b. 加班(超过40hrs) = 1.5倍的时间
//c. 税率:   前300美元， 15%
//          续150美元为 20%
//          余下为      25%
#include <stdio.h>
#define BASE_PAY_PERHOUR	 10
#define OT_PAY_PERHOUR		 BASE_PAY_PERHOUR*1.5
#define TAX_LEVEL1 300
#define TAX_LEVEL2 450
#define TAX_rate_1 0.15		//300美元以内
#define TAX_rate_2 0.20		//300～450美元以内
#define TAX_rate_3 0.25		//450美元以上
#define WEEK_HOURS 40

float caculate_tax(float grossypay)
{
	if(grossypay>TAX_LEVEL2)
		return TAX_LEVEL1*TAX_rate_1 + (TAX_LEVEL2-TAX_LEVEL1)*TAX_rate_2 + (grossypay-TAX_LEVEL2)*TAX_rate_3;
	else if (grossypay>TAX_LEVEL1)
		return TAX_LEVEL1*TAX_rate_1 + (grossypay - TAX_LEVEL1)*TAX_rate_2;
	else
		return grossypay * TAX_rate_1;
}

int main(void)
{
	int working_hrs = 0;
	int working_hrs_actually = 0;
	float income_total = 0;
	float tax_total = 0;
	float income_net = 0;
	float tax_1 = 0.0, tax_2 = 0.0, tax_3 = 0.0;

	printf("Enter your working hours this week.\n");
	if(scanf("%d", &working_hrs)==1)
	{
		//求出实际有效的工作时数(算上加班)
		if((working_hrs<=WEEK_HOURS))
		{
			working_hrs_actually = (float)working_hrs;
		}
		else
		{
			working_hrs_actually = (float)((working_hrs-WEEK_HOURS)*1.5 + WEEK_HOURS);
		}

		//求出 income_total
		income_total = (float)working_hrs_actually * BASE_PAY_PERHOUR;

		//用函数求出税金
		tax_total = caculate_tax(income_total);
		income_net = income_total - tax_total;

		// //求出税金
		// if(income_total >= TAX_LEVEL2)
		// {
		// 	tax_3 = (income_total-TAX_LEVEL2) * TAX_rate_3;
		// 	tax_2 = (TAX_LEVEL2-TAX_LEVEL1)*TAX_rate_2;
		// 	tax_1 = TAX_LEVEL1*TAX_rate_1;
		// 	tax_total = tax_1 + tax_2 + tax_3;
		// 	income_net = income_total - tax_total;
		// }
		// else if(income_total >= TAX_LEVEL1)
		// {
		// 	tax_2 = (income_total-TAX_LEVEL1)*TAX_rate_2;
		// 	tax_1 = TAX_LEVEL1*TAX_rate_1;
		// 	tax_total = tax_1 + tax_2;
		// 	income_net = income_total - tax_total;
		// }
		// else
		// {
		// 	tax_1 = income_total * TAX_rate_1;
		// 	tax_total = tax_1;
		// 	income_net = income_total - tax_total;
		// }

		printf("total income is %.1f.\n", income_total);
		printf("Total tax is %.1f.\n", tax_total);
		printf("Total net income is %.1f.\n", income_net);
	}
	else
	{
		printf("Wrong input.\n");
	}

	return 0;
}
