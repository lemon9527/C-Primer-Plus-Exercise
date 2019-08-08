/******************************Chapter 15 Exercise********************************/
//#6
//设计一个位字段结构，以存储一下信息
/*
    字体ID: 0~255 之间的一个数
    字体大小: 0~127之间的一个数
    对齐: 0~2之间的一个数，左对齐，居中，右对齐
    加粗: 开(1) 或 闭(0)
    斜体: 开(1) 或 闭(0)
    下划线: 开(1) 或 闭(0)
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define CLEARINPUT while (getchar() != '\n') continue
#define ALIGMENT_STR(a1) a1?(a1==1?"center":"right"):"left"
#define ONOFF(status) status?"ON":"OFF"
#define ON  1
#define OFF 0


#define LEFT   0
#define CENTER 1
#define RIGHT  2

struct Font{
    unsigned int font_id         : 8;
    unsigned int font_size       : 7;
    unsigned int alignment       : 2;
    unsigned int bold            : 1;
    unsigned int italic          : 1;
    unsigned int underline       : 1;
};

void display_font(struct Font*);
void print_menu(void);
void set_font(struct Font*);
void set_size(struct Font*);
void setalignment(struct Font*);
void togglebold(struct Font*);
void toggleitalic(struct Font*);
void toggleunderline(struct Font*);

int main(void)
{
    struct Font font = {1, 12, 1, 0, 0, 0};

    while(1)
    {
        display_font(&font);
        print_menu();

        int ch = getchar();
        if(ch != '\n')
            CLEARINPUT; //清空输入流
        if(ch == EOF || ch == 'q')  //退出程序
            break;
        else if(ch == 'f')
            set_font(&font);
        else if(ch == 's')
            set_size(&font);
        else if(ch == 'a')
            setalignment(&font);
        else if(ch == 'b')
            togglebold(&font);
        else if(ch == 'i')
            toggleitalic(&font);
        else if(ch == 'u')
            toggleunderline(&font);
    }

    puts("Bye.");
    return 0;
}

void display_font(struct Font * font)
{
    putchar('\n');
    puts("ID  SIZE     ALIGMENT    B    I    U");
    printf("%2d%5d%13s%7s%5s%5s\n", font->font_id, font->font_size,
           ALIGMENT_STR(font->alignment), ONOFF(font->bold), ONOFF(font->italic), ONOFF(font->underline));
    putchar('\n');
}

void print_menu(void)
{
    putchar('\n');
    puts("f)change font                s)change size                a)change alignment");
    puts("b)toggle bold                i)toggle italic              u)toggle underline");
    puts("q)quit");
}

void set_font(struct Font* font)
{
    unsigned int fontid = 0;
    puts("Enter font id (0~255):");
    while(scanf("%d", &fontid) !=1)
    {
        CLEARINPUT;
        puts("Invalid input, try again: ");
        puts("Enter font id (0~255):");
    }
    font->font_id = fontid;
    CLEARINPUT;
}

void set_size(struct Font* font)
{
    unsigned int size = 0;
    puts("Enter font size (0~127):");
    while(scanf("%d", &size) != 1)
    {
        CLEARINPUT;
        puts("Invalid input, try again: ");
        puts("Enter font id (0~127):");
    }
    font->font_size = size;
    CLEARINPUT;
}

void setalignment(struct Font* font)
{
    puts("Please select an alignment:");
    puts("l)left     c)center      r)right");
    int ch;
    while(!((ch = getchar()) == 'l' || ch == 'c' || ch == 'r'))
    {
        puts("");
        puts("Invalid input, try again:");
        puts("Please select an alignment:");
        puts("l)left     c)center      r)right");
    }
    if(ch == 'l')
        font->alignment = 0;
    else if(ch == 'c')
        font->alignment = 1;
    else if(ch == 'r')
        font->alignment = 2;

    CLEARINPUT;
}

void togglebold(struct Font* font)
{
    font->bold = font->bold ? OFF : ON;
}

void toggleitalic(struct Font* font)
{
    font->italic = font->italic? OFF : ON;
}

void toggleunderline(struct Font* font)
{
    font->underline = font->underline? OFF : ON;
}
