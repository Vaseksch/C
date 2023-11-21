#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int getch(void);

int pos(int xx, int yy)
{
    COORD poscur;
    poscur.X = xx;
    poscur.Y = yy;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), poscur);
    return 0;
}

int main()
{
    srand(time(NULL));

    int inpt = 0;
    int xx = 10;
    int delay = 0;
    int pointx;
    int pointy;
    int yy = 10;
    int ARR[2][255];
    int lenght = 16;

    printf("pro pokracovani stisknete libovolnou klavesu\n");
    getch();
    system("cls");
    pos(xx, yy);
    for (int line = 0; line < 2; line++)
    {
        for (int step = 0; step < lenght; step++)
        {
            ARR[line][step] = 10 + step;
        }
    }

    pos(ARR[0][lenght - 1], ARR[1][lenght - 1]);
    while (inpt != 27)
    {
        pos(ARR[0][lenght - 1], ARR[1][lenght - 1]);
        printf(" ");
        for (int line = 0; line < 2; line++)
        {
            for (int move = lenght - 1; move > 0; move--)
            {
                ARR[line][move] = ARR[line][move - 1];
            }
        }

        pos(25, 26);
        printf("score: %d", lenght/2);

        inpt = getch();
        if (inpt == 72)
        {
            ARR[1][0]--;
        }
        if (inpt == 80)
        {
            ARR[1][0]++;
        }
        if (inpt == 75)
        {
            ARR[0][0]--;
        }
        if (inpt == 77)
        {
            ARR[0][0]++;
        }
        pos(ARR[0][0], ARR[1][0]);
        printf("x");
        if(delay == 150){
            pointx = rand() % 70;
            pointy = rand() % 30;
            pos(pointx, pointy);
            printf("o");
        }
        if(ARR[0][0] == pointx && ARR[1][0] == pointy){
            delay = 0;
            lenght += 2;
        }
        pos(ARR[0][0], ARR[1][0]);
        delay++;
    }
}