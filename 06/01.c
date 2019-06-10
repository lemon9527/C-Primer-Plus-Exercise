///************************************Exercise***************************************/
//#1
#include<stdio.h>
#define ALPHABET_LENGTH 26

//int main(void)
//{
//    char alphabet_lowcase[ALPHABET_LENGTH];
//    char letter;
//    int i;
//
//    for(letter = 'a'; letter<'a'+ALPHABET_LENGTH; letter++)
//    {
//        alphabet_lowcase[letter - 'a'] = letter;
//    }
//
//    for(i = 0; i<26; i++)
//    {
//        printf("%2c", alphabet_lowcase[i]);
//    }
//
//    return 0;
//}
int main(void)
{
    char alphabet_lowcase[ALPHABET_LENGTH];
    int i, letter;
    int j;

    for(i = 0, letter = 97; i<ALPHABET_LENGTH; i++, letter++)
    {
        alphabet_lowcase[i] = letter;
    }

    for(j = 0; j<26; j++)
    {
        printf("%2c", alphabet_lowcase[j]);
    }

    return 0;
}
