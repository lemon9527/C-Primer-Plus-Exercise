/*****************************************************************/
//06.c
// 4 Jessie Joybat 5 2 1 1
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define PLEN 19
// #define NLEN 20

// struct player {
//     char fname[NLEN];
//     char lname[NLEN];
//     unsigned int playtimes;
//     unsigned int hits;
//     unsigned int walks;
//     unsigned int RBI;
//     float battingaverage;
// };

// struct player players[PLEN];

// void getbattingaverage(struct player *);
// void showteamdata(const struct player *, int number);


// int main(void)
// {
//     //把结构内容初始化为0
//     for(int i=0; i<PLEN; i++)
//     {
//         players[i] =(struct player) {"", "", 0, 0, 0, 0};
//     }

//     //读取文件
//     FILE * pplayer;
//     if((pplayer = fopen("players.txt", "r"))==NULL)
//     {
//         puts("Can not open players.txt file.");  
//         exit(1);
//     }
//     rewind(pplayer);
//     int number;
//     char firstname[NLEN];
//     char lastname[NLEN];
//     unsigned int playtimes;
//     unsigned int hits;
//     unsigned int walks;
//     unsigned int RBI;

//     //read data from player.txt
//     while(fscanf(pplayer, "%d %s %s %u %u %u %u", &number, firstname, 
//         lastname, &playtimes, &hits, &walks, &RBI) == 7)
//     {
//         if(players[number].fname[0] == '\0')
//         {
//             strcpy(players[number].fname, firstname);
//             strcpy(players[number].lname, lastname);
//         }
//         players[number].playtimes += playtimes;
//         players[number].hits += hits;
//         players[number].walks += walks;
//         players[number].RBI += RBI;
//     }

//     //caculate the batting averages for everyone
//     for(int i=0; i<PLEN; i++)
//     {
//         getbattingaverage(&players[i]);
//     }

//     //show team data
//     showteamdata(players, PLEN);

//     if(fclose(pplayer) != 0)
//     {
//         fprintf(stderr,"Error closing file\n");
//     }    
// }

// void getbattingaverage(struct player * pplayer)
// {
//     pplayer->battingaverage = pplayer->hits/(float)pplayer->playtimes;
// }

// void showteamdata(const struct player * pplayer, int number)
// {
//     for(int i=0; i<number; i++)
//     {
//         if(pplayer[i].fname[0] !='\0')
//         {
//             printf("%d %s %s %u %u %u %u\n", i, pplayer[i].fname, pplayer[i].lname,
//         pplayer[i].playtimes, pplayer[i].hits, pplayer[i].walks, pplayer[i].RBI);
//         }
//     }
    
// }
