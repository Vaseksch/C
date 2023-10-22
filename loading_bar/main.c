#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int delay(int mil)
{
    clock_t start = clock();

    while (clock() < start + mil)
    {
    }
}

void clear()
{
    system("cls");
}

int main()
{
    int num;
    int step;

    clear();

    delay(1000);

    for (int pos = 0; pos < 60; pos++)
    {
        clear();
        printf("nahravani: ");
        for (step = 0; step < pos; step++)
        {
            printf("%c", 219);
        }
        for (int notloaded = 0; notloaded < 59 - step; notloaded++)
        {
            printf("\xB0");
        }

        delay(300);
    }
    return 0;
}
