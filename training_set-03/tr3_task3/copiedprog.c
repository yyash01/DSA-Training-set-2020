/*
NAME - YASH JAIN
ROLL.NO = 19UCS197
BATCH - CP(LAB-03) WEDNESDAY AFTERNOON
*/
#include "deque1.h"

/* storage allocated here */
struct node hdr;

/* ADT interface functions */
/* THink of hdr as if it is on top 
of all member nodes of deque.
Left and right of header is not symmetric to
those of member nodes */
void init() {
	// unued 
	hdr.data = 0; 
	hdr.nextL = hdr.nextR = NULL;
}

void joinL(int d) {
	printf("Going to join %d on left\n", d);
	struct node *new = malloc(sizeof(struct node));
	assert(new!=NULL); // Stop if problem
	
	new->data = d;
        assert(new->data >=1); //-------------------This assert is add by me (YASH JAIN)-------------------------//

	//IF  DEQUE IS EMPTY OR NOT
                if (hdr.nextL == NULL) {
		assert(hdr.nextR == NULL); 
		hdr.nextL = hdr.nextR = new;
		new->nextL = new->nextR = NULL;
		printf("Joined %d on left\n", d);
		return;
	}
	
	assert(hdr.nextR != NULL);
	assert(hdr.nextL->nextL == NULL);
	hdr.nextL->nextL = new;
	new->nextR = hdr.nextL;
	new->nextL = NULL;
	hdr.nextL = new;
	printf("Joined %d on left\n", d);	
}

void joinR(int d) {
        printf("Going to join %d on Right\n", d);
	struct node *new = malloc(sizeof(struct node));
	assert(new!=NULL);// stop if problem-------------------this asser is added by me---------------------//
  
        new->data = d;
        //if DEQUE IS EMPTY
        if(hdr.nextR==NULL){
        assert(hdr.nextR==NULL);
        hdr.nextR = hdr.nextL=new;
        new->nextR = new->nextL = NULL;
        printf("joined %d on right\n",d);
        return;
        }
        assert(hdr.nextL != NULL);
        assert(hdr.nextR->nextR==NULL);
        hdr.nextR->nextR = new;
        new->nextL = hdr.nextR;
        new->nextR = NULL;
        hdr.nextL = new;
        printf("joined %d on right\n",d);      
} 

int leaveL() {
        struct node *tmp;
	printf("Someone leaving from LEFT\n");
	assert(hdr.nextR!= NULL && hdr.nextL != NULL);
	int d = hdr.nextL->data;
	tmp = hdr.nextL->nextR;
	if (tmp != NULL)
		tmp->nextL = NULL;
	free(hdr.nextL);
	hdr.nextL = tmp;
	printf("From left %d left\n", d);
	if (tmp == NULL)
		hdr.nextR = NULL;
	assert (tmp != NULL || hdr.nextR == NULL);	
	return d; 
}
int leaveR() {
	struct node *tmp;
	printf("Someone leaving from Right\n");
	assert(hdr.nextL != NULL && hdr.nextR != NULL);
	int d = hdr.nextR->data;
	tmp = hdr.nextR->nextL;
	if (tmp != NULL)
		tmp->nextR = NULL;
	free(hdr.nextR);
	hdr.nextR = tmp;
	printf("From right %d left\n", d);
	if (tmp == NULL)
		hdr.nextL = NULL;
	assert (tmp != NULL || hdr.nextL == NULL);	
	return d;
}
 
int size() {
	int i = 0;
	struct node *ptr = hdr.nextL;
	
	while (ptr != NULL) {
		i++; ptr = ptr->nextR;
	}
	return i;
}
