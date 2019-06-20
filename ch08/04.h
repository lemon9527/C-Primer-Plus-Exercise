//8.4 把输入作为字符流读取，报告平均每个单词的字母数，不应该包含空格。
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define SPACE ' '

int main(void)
{
    char ch;
    int letter_count = 0;
    int word_count = 0;
    bool is_in_word = false;

    printf("Enter some text.\n");
    while((ch=getchar()) != EOF)
    {
        if(isalpha(ch))
        {
            letter_count++;
            if(!is_in_word)
            {
                is_in_word = true;
                word_count++;
            }
        }
        else
        {
            is_in_word = false;
        }
    }
    printf("Number of input words: %d\n", word_count);
    printf("Average number of letters per word: %.2f.\n", (float)letter_count/word_count);
    return 0;
}
