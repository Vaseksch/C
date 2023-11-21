#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>



int deck(int lenght, int height)
{
    for (int pos = 0; pos < height; pos++)
    {
        printf("+");
        for (int step = 0; step < lenght; step++)
        {
            printf("---+");
        }
        printf("\n|");
        for (int step = 0; step < lenght; step++)
        {
            printf("   |");
        }
        printf("\n");
    }
    printf("+");
    for (int step = 0; step < lenght; step++)
    {
        printf("---+");
    }
    return 0;
}

int move(int xx, int yy)
{
    COORD poscur;
    poscur.X = xx;
    poscur.Y = yy;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), poscur);
    return 0;
}

void text(int height){
    move(0, height * 2 + 2);
    printf("pro ukonceni - ESC\npesak - p\nvez - v");
}

int getch(void);

int main()
{
    int lenght;
    int height;
    int xx = 2;
    int yy = 1;
    int inpt = 0;
    int posx = 0;
    int posy = 0;

    printf("zadejte delku (max. 16): ");
    if (scanf("%d", &lenght) != 1)
    {
        printf("chybny vstup");
        getch();
        return 0;
    }

    printf("zadejte vysku (max. 16): ");
    if (scanf("%d", &height) != 1)
    {
        printf("chybny vstup");
        getch();
        return 0;
    }

    if (height < 1 || lenght < 1 || height > 16 || lenght > 16)
    {
        printf("chybny vstup");
        getch();
        return 0;
    }

    system("cls");

    deck(lenght, height);

    text(height);

    move(xx, yy);
    while (inpt != 27)                                                      //zadefinovani jednotlivych inputu
    {
        inpt = getch();
        if (inpt == 72)
        {
            if (posy - 1 >= 0)
            {
                yy -= 2;
                posy--;
            }
        }
        if (inpt == 80)
        {
            if (posy + 1 < height)
            {
                yy += 2;
                posy++;
            }
        }
        if (inpt == 75)
        {
            if (posx - 1 >= 0)
            {
                xx -= 4;
                posx--;
            }
        }
        if (inpt == 77)
        {
            if (posx + 1 < lenght)
            {
                xx += 4;
                posx++;
            }
        }
        if(inpt == 112){
            printf("i");
        }
        if(inpt == 118){
            printf("#");
        }
        if(inpt == 8){
            printf(" ");
        }
        move(xx, yy);
    }
}
