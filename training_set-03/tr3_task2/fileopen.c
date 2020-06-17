/*
NAME - YASH JAIN
ROLL.NO = 19UCS197
BATCH - CP(LAB-03) WEDNESDAY AFTERNOON
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void main()
{
    FILE *fp;
    fp = fopen("copiedprog.c", "r");
    assert(fp != NULL);
    char ch;
    ch = fgetc(fp);
    while (!feof(fp))
    {
        printf("%c", ch);
        ch = fgetc(fp);
    }
    fclose(fp);
    printf("\n");
}
