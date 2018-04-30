#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
	Card Test 1: Adventurer Card
*/

int main()
{	
	int cardDrawn;
	//treasure counts
	int treas = 0;
	int treas1 = 0;
	int treas2 = 0;
	int temp[MAX_HAND];
	int seed = 1000;
	int numPlayers = 2;
	struct gameState gs, testgs;
	
	//set up array for cards
	int k[10] = {minion, mine, adventurer, great_hall, cutpurse,
	sea_hag, tribute, smithy, council_room, copper};

	printf("BEGIN Card Test 1, cardtest1.c: Adventurer\n");

	initializeGame(numPlayers, k, seed, &gs);
	memcpy(&testgs, &gs, sizeof(struct gameState));
	testgs.hand[testgs.whoseTurn][0] = minion;
	
	myAdventurerFunction(&testgs, 0);
	printf("Card Count --> EXPECTED: %d, GOT: %d\n", gs.handCount[gs.whoseTurn] + 2, testgs.handCount[testgs.whoseTurn]);

	gs.discardCount[gs.whoseTurn] = 5;	
	memcpy(&testgs, &gs, sizeof(struct gameState));
	myAdventurerFunction(&testgs, 0);
	
	int z = 0;
	do {
		drawCard(gs.whoseTurn, &gs);
		cardDrawn = gs.hand[gs.whoseTurn][gs.handCount[gs.whoseTurn]-1];
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold){
	  		treas++;
		} else {
	  		temp[z]=cardDrawn;
	  		gs.handCount[gs.whoseTurn]--; 
	  		z++;
		}
    } while (treas < 4);
	printf("Card Count --> EXPECTED: %d, GOT: %d\n", gs.discardCount[gs.whoseTurn] + z, testgs.discardCount[testgs.whoseTurn]);

	for(int i = 0; i < gs.handCount[gs.whoseTurn]; i++){
		if (gs.hand[gs.whoseTurn][i] == copper || gs.hand[gs.whoseTurn][i] == silver || gs.hand[gs.whoseTurn][i] == gold){
			treas1++;
		}		
	}
	
	for(int i = 0; i < testgs.handCount[testgs.whoseTurn]; i++){
		if (testgs.hand[testgs.whoseTurn][i] == copper || testgs.hand[testgs.whoseTurn][i] == silver || testgs.hand[testgs.whoseTurn][i] == gold){
			treas2++;
		}		
	}
	
	printf("Treasure Count --> EXPECTED: %d, GOT: %d\n", treas1, treas2);
	printf("END Card Test 1, cardtest1.c: Adventurer\n");

	return 0;
}