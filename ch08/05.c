//8.5 猜数字游戏(1~100)，每次询问用户是猜大了还是猜小了。二分法
#include <stdio.h>

int main(void)
{
    int min = 0, max = 100;
	int guess = (min+max)/2;
	char ch;

	printf("Pick a number from 1 to 100, I will try to guess ");
	printf("it. \nResponse with y if my guess is right.\n");
	printf("Response with H when guess is Higher, and Response with L when guess is lower.\n");

	printf("Uh... is your number %d?\n", guess);
	while((ch=getchar())!='y')
	{
		if(ch=='H')
		{
		    max = guess;
			guess = (min+max)/2;
		}
		else if(ch=='L')
		{
		    min = guess;
			guess = (min+max)/2;
		}
		else
		{
			printf("Wrong input! Try again.\n");
			continue;
		}

		printf("Uh... is your number %d?\n", guess);

		while(getchar() != '\n')    //clear input stream
            continue;
	}

	printf("Haha, I know i can do it!\n");

	return 0;
}
