#include "rajasthanGeography.h"
#include <ctype.h>
#include <string.h>

struct town *townships[TOWNS]; 
int towns = 0; 


struct town *makeTown(char *name) 
{ 
	struct town *tn = (struct town *)malloc(sizeof(struct town)); 
	if (tn == NULL || towns == TOWNS) 
	{ 
		return NULL; 
	} 

	assert(towns<TOWNS);

	townships[towns] = tn; 
	tn->name = (char *)malloc(strlen(name)+1); 
	strcpy(tn->name, name); 
	tn->edges = NULL; 
	tn->townIdx = towns++; 
	tn->finalisedDist = 0; 
	tn->distance = INT_MAX/TOWNS; 
	return tn;
} 


/* Get town from NAME */ 
struct town *getTown(char *name) 
{ 
	int i; 
	for (i= 0; i < towns; i++) 
		if (strcmpi(townships[i]->name, name) == 0) 
			return townships[i]; 
	return NULL; 
} 


/* Get name for TOWN */ 
char *getName(struct town *town) 
{ 
	return town->name; 
} 


/* Get name for IDX */ 
static char *getNamebyIdx(int idx)
{ 
	return townships[idx]->name; 
} 


/* Get the count of towns*/
int getcountoftowns()
{
	return towns;
}


/* Get town connected to HERE by ROAD */ 
struct town *getOtherTown(struct town *here, struct link *road) 
{ 
	/* the road goes from *HERE to the other town */ 

	if (road == NULL || here == NULL) 
		return NULL; 
	if (townships[road->highIdx] == here) 
		return townships[road->lowIdx]; 
	else if (townships[road->lowIdx] == here) 
		return townships[road->highIdx]; 
	else 
		return NULL; 
} 


/* Get name of town connected to HERE by ROAD */ 
char *neighbour(struct town *here, struct link *road) 
{ 
	struct town *t = getOtherTown(here, road); 
	if (t != NULL) 
		return t->name; 
	return "Ghost town"; 
} 


static struct link *nextRoadOutofHere(struct town *here, struct link *road) 
{ 
	/* Return next road out of *HERE after *ROAD */ 

	struct link *nextRoad; 
	assert(here != NULL); 

	if (here==NULL || road==NULL)
		return NULL;

	if (townships[road->highIdx]==here)
		return road->nxtHighEdge;
	
	else if (townships[road->lowIdx]==here)
		return road->nxtLowEdge;
	 
	else
		return NULL;
} 

/*
We have used the adjacency lit representation for graph.
*/

static struct link *insertLink(struct town *town1, struct town *town2) 
{ 
	struct link *link = malloc(sizeof(struct link)); 
	assert(link != NULL);

	if (town1->townIdx>town2->townIdx) 
	{ 
		link->highIdx = town1->townIdx; 
		link->lowIdx = town2->townIdx; 
		link->nxtHighEdge = town1->edges; 
		town1->edges = link; 
		link->nxtLowEdge = town2->edges; 
		town2->edges = link; 
	} 

	else 
	{
		link->highIdx = town2->townIdx; 
		link->lowIdx = town1->townIdx; 
		link->nxtHighEdge = town2->edges; 
		town2->edges = link; 
		link->nxtLowEdge = town1->edges; 
		town1->edges = link; 
	} 

	return link; 

} 


void linkTowns(char *thisTown, char *thatTown, int distance) 
{ 	
	
	/* Links two towns by road */ 
	struct town *here, *there; 
	struct link *here2there, *exists;

	here = getTown(thisTown); 
	there = getTown(thatTown);

	if (here == there) 
		return; // No self loops

	assert(here != NULL); 
	assert(there != NULL); 

	/* Does a road exist previously */ 
	exists = here->edges;

	here2there = NULL; 

	while (here2there == NULL && exists != NULL) 
	{ 
		/* Search if the towns are already connected */ 
		if (getOtherTown(here, exists) == there) 
			here2there = exists; 
		else 
			exists = nextRoadOutofHere(here, exists); 
	} 

	if (here2there != NULL) 
	{ 
		if (here2there->length > distance) 
			here2there->length = distance; 
		return; 
	} 

	here2there = insertLink(here, there); 
	here2there->length = distance; 

} 


/* get link that connects HERE to the last neighbour connected to it */ 
struct link *getLink2newestNeighbour(struct town *here) 
{ 
	return here->edges;
} 


/* Get link that connects HERE to the neighbour before 
the one connected by LINK. */ 
struct link *getLink2earlierNeighbour(struct town *here, struct link *link) 
{ 
	return nextRoadOutofHere(here,link);
} 


/* Get length of ROAD */ 
int length(struct link *road) 
{ 
	return road->length; 
}


