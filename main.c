#include <stdio.h>
#include <stdlib.h>

int main()
{
    int aa;
    int bb;
    int num;
    int test;

    int *ptraa = &aa;
    int *ptrbb = &bb;
    int *ptrnum = &num;

    printf("zadejte 2x int\n");

    test = scanf("%d %d", ptraa, ptrbb);

    if(test != 2){
        printf("chyba");
        return 0;
    }

     if(*ptrbb == 0){
        printf("nelze delit nulou");
        return 0;
    }

    *ptrnum = *ptraa + *ptrbb;
    printf("%d\n", *ptrnum);
    *ptrnum = *ptraa - *ptrbb;
    printf("%d\n", *ptrnum);
    *ptrnum = *ptraa * *ptrbb;
    printf("%d\n", *ptrnum);
    *ptrnum = *ptraa / *ptrbb;
    printf("%d\n", *ptrnum);
    return 0;
}
