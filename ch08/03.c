//#03 统计输入的大小写字母的个数
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;
	int char_cnt = 0;
	int upper_cnt = 0;
	int lower_cnt = 0;

	printf("Enter some text.\n");
	while((ch=getchar()) != EOF)
	{
		if(isupper(ch))
			upper_cnt++;
		if(islower(ch))
			lower_cnt++;

		char_cnt++;
	}

	printf("\ncharacter Counts\n");
	printf("Total input %d characters.\n", char_cnt);
	printf("Uppercase letters: %d\n", upper_cnt);
	printf("Lowercase letters: %d\n", lower_cnt);
	return 0;
}
