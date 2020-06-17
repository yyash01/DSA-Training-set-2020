#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deque1.h"

void main()
{
    FILE *fp;
    fp = fopen("copiedprog.c", "r");
    assert(fp != NULL);
    char ch1, ch2;
    ch1 = fgetc(fp);
    while (!feof(fp))
    {
        ch1 = fgetc(fp);
        if (ch1 == '(' || ch1 == '{' || ch1 == '[')
            joinL(ch1);
        else if (ch1 == ')' || ch1 == '}' || ch1 == ']')
        {
            ch2 = leaveL();
            assert((ch1 == ')' && ch2 == '(') || (ch1 == '}' && ch2 == '{') || (ch1 == ']' && ch2 == '['));
        }
    }
    assert(hdr.nextL == NULL && hdr.nextR == NULL);
    printf("Program has well balanced Parantheses, Braces and Brackets.\n");
    fclose(fp);
}
