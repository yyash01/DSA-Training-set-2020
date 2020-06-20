#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h> 
#include "rajasthanGeography.h"
#include "queue.h"


char *squeeze(char *begin, char *end) 
{ 
	/* Squeeze out superflous white spaces */ 
	char *last, *start = begin; 
	int first = 0; 

	/* Set start to the first non space */ 
	while (isspace(*start)) 
		start++; 

	/* locate last non space */ 
	while (isspace(*end) || *end == '\0') 
		*(end--) = '\0'; 

	last = end; 

	while (last >= start) 
	{ 
		while (first && isspace(*last)) 
			last--; 

		first = isspace(*last); 
		*(end--) = *(last--); 
	} 

	return end+1; 

} 


/*Code for breadth first search(BFS) for a graph*/
void BFS(struct town *origintown)
{
	/*We make a visited array so as to check whether we have 
	visited that town or not.
	Initially visited is initialised as zero for all the towns.
	As we visit a town we mark visisted as 1 for that town.
	*/
	int *visited=(int *) malloc(towns*sizeof(int)); 
	assert(visited!=NULL);
	for (int i=1;i<=towns;i++)
		visited[i]=0;

	visited[origintown->townIdx]=1;
	initQueue();

	joinQueue(origintown->townIdx);
	printf("The towns which were visited during BFS are:\n");
	while (!isQueueEmpty())
	{
		struct town *town=townships[leaveQueue()];
		printf("%s\n",town->name);
		struct link *road=getLink2newestNeighbour(town);

		while (road!=NULL)
		{
			struct town *neighbour=getOtherTown(town,road);
			if (!visited[neighbour->townIdx])
			{
				visited[neighbour->townIdx]=1;
				joinQueue(neighbour->townIdx);
			}

			road=getLink2earlierNeighbour(town,road);
		}
	}
}


void setUpGraph(void) 
{ 
	int i, distance; 

	FILE *cities = fopen("cities", "r"); 
	FILE *roads = fopen("roads", "r"); 
	assert(cities != NULL && roads != NULL); 

	char name[100]; 
	char *roadStart, *roadEnd, *kms; 
	struct link *ll; 

	while (fgets(name, 99, cities)) 
	{ 
		if (strlen(name) < 2) 
			break;

		name[strlen(name)-1] = '\0'; //Enter key is replaced by '\0'

		if (makeTown(squeeze(name, name+strlen(name)))== NULL) 
			break; // Data structure full 

	} 

	while (fgets(name, 99, roads)) 
	{ 
		if (strlen(name) < 4) 
			break; 

		name[strlen(name)-1] = '\0';  //Enter key is replaced by '\0'

		roadStart = kms = name; 

		while (!isdigit(*kms)) 
			kms++; 

		*(kms-1) = '\0'; 

		sscanf(kms, "%d", &distance); 
		roadEnd = kms; 

		while (!isspace(*roadEnd)) 
			roadEnd++; 

		linkTowns(squeeze(roadStart,roadStart+strlen(roadStart)), 
				squeeze(roadEnd, roadEnd+strlen(roadEnd)), distance); 

	}

	fclose(cities);
	fclose(roads); 

} 

void findShortestDistances(struct town *here) 
{ 
	/* Distances to other towns from HERE */ 
	int townsIdx, update = 0; 

	if (here == NULL) 
		return; 

	int nextDist; 
	struct town *newFound, *there;

	/*< 20 Lines of C code removed. Student to add code here for Task 03 >*/
	
	/* recursive call from town closest to the starting town 
	Whose distance is not yet final */ 
	findShortestDistances(there); 

} 


int main(void) 
{
	struct town *rupaNangal; 

	setUpGraph(); 

	rupaNangal = getTown("Rupa ki Nangal"); 
	assert(rupaNangal != NULL); 

	BFS(rupaNangal);

	/*
	setFinalDist(rupaNangal, 0); 

	findShortestDistances(rupaNangal); 

	// Print distances.  
	for (townsIdx = 0; townsIdx < towns; townsIdx++) 
	{ 
		printf("Town %s is ", getName(townships[townsIdx])); 

		if (isDistanceFinal(townships[townsIdx])) 
			printf("%d kms from LNMIIT\n", getDistFromStart(townships[townsIdx])); 

		else 
			printf("unconnected to LNMIIT in this graph\n"); 
	} 
	*/

	return 0; 

} 
