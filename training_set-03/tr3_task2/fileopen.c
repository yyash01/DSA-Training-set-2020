/*
NAME - YASH JAIN
ROLL.NO = 19UCS197
BATCH - CP(LAB-03) WEDNESDAY AFTERNOON
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
getc() returns EOF when end of file is reached. getc() also returns EOF when it fails. So, only comparing the value returned by getc() with EOF is not sufficient to check for actual end of file. To solve this problem, C provides feof() which returns non-zero value only if end of file has reached, otherwise it returns 0.
*/
void main()
{
    FILE *fp;
    fp = fopen("copiedprog.c", "r");
    assert(fp != NULL);
    char ch;
    ch = fgetc(fp);
    while (!feof(fp))//means end of file is not reached jb tk ye while loop chlana hai
    {
        printf("%c", ch);
        ch = fgetc(fp);
    }
    fclose(fp);
    printf("\n");
}
