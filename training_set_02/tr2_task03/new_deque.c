/* An implementation of Deque  */
#include "deque.h"
#include<stdlib.h>
#include<stdio.h>

int data[SIZE];
int left = 8;
int right = 9;

int insertLeft(int d)
{
	if (size() == SIZE - 1)
    {
        return 0;
    }
    data[left] = d;
	left = (left - 1 + SIZE) % SIZE;
	return 0;
}

void insertRight(int d)
{
	if (size() == SIZE-1)
    {
        return;
    }
	data[right] = d;
    right = (right + 1) % SIZE;
}

int removeLeft()
{
	int d, s;
	s = size();
	if (s == 0)
	{
//errorr message
        return ERR_DATA;
    }
    left = (left + 1) % SIZE;
	d = data[left];
}

int removeRight()
{
	int d, s;
    s = size();
    if (s == 0)
	{
        return ERR_DATA;
    }
    right = (right - 1 + SIZE) % SIZE;
	d = data[right];
}

int isEmpty()
{
	return size() == 0;
}

void init()
{
	left = 8;
    right=9;
}

int size()
{
	if (right==(left+1)%SIZE)
		return 0;
	return ((right + SIZE - left-1) % SIZE);
}
