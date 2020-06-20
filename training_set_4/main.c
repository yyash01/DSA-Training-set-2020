/*
NAME - YASH JAIN
ROLL.NO = 19UCS197
BATCH - CP(LAB-03) WEDNESDAY AFTERNOON
*/
#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"
char tmp[101];
int rollDice()
{
    int i = 1 + rand() % 6;
    return i;
}
int main(void)
{
    char *name;
    int dice;
    initDList();
    FILE *playerF = fopen("players.txt", "r");
    assert(playerF != NULL); // File is open

    while (fgets(tmp, 100, playerF)!=NULL)
    {
        // Get space filled with \0
        name = (char *)calloc(1, strlen(tmp) + 1);
        // Newline should not copied
        strncpy(name, tmp, strlen(tmp)-1);
        insertChair(name);
        printf("Added %s\n", name);
        //fgets(tmp, 100, playerF);
    }

    printf("\nAll palyers are in their chairs now. Game begins\n\n");

    while (!isEmpty())
    {
        printf("%s is in chair 0. ", whoInChair(0));
        dice = rollDice();
        if (dice % 2 == 1) // Odd numbers on left!
            dice *= -1;
        printf("\n\tRid chair %d.\t", dice);
        name = removeChair(dice);
        if (isEmpty())
            printf("\n\nWinner is %s\n", name);
        else
            printf("\tLosing player was %s.\n", name);
        free(name);
    }
    return 0;
}
