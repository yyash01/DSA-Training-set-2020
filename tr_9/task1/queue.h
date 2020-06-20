struct node
{
	int value;
	struct node *next;
};

void initQueue();
void joinQueue(int value);
int leaveQueue();
int isQueueEmpty();