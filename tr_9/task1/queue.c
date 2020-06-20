#include <stdlib.h>
#include <assert.h>
#include "queue.h"

struct node *left, *right;


void initQueue()
{
	left = NULL;
	right = NULL;
}

/*Insertion from right*/
void joinQueue(int value)
{
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	newNode->value = value;
	newNode->next = NULL;

	if (left == NULL)
	{
		assert(right == NULL);
		left = newNode;
		right = newNode;
	}

	else
	{
		assert(right != NULL);
		right->next = newNode;
		right = newNode;
	}
}


/*Deletion from left*/
int leaveQueue()
{
	assert(!isQueueEmpty());
	struct node *temp = left;
	int value = temp->value;
	
	if (left == right)
		initQueue();
	else
		left = left->next;

	free(temp);
	return value;
}


/*To check whether queue is empty or not.*/
int isQueueEmpty()
{
	if (left == NULL)
	{
		assert(right == NULL);
		return 1;
	}

	assert(left!=NULL);
	assert(right != NULL);
	return 0;
}

