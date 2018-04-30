#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
  Card Test 2: Smithy Card
*/

int main(){
	int seed = 1000;
  	int numPlayers = 2;
	struct gameState gs, testgs;
	int k[10] = {copper, minion, mine, silver, gold, cutpurse, sea_hag, tribute, smithy, council_room};
	printf("BEGIN Card Test 2, cardtest2.c: Smithy\n");
	initializeGame(numPlayers, k, seed, &gs);
	memcpy(&testgs, &gs, sizeof(struct gameState));
	mySmithyFunction(&testgs, 0, 1);
	printf("Card Count --> EXPECTED: %d, GOT: %d\n", gs.handCount[gs.whoseTurn] + 3, testgs.handCount[testgs.whoseTurn]);
	gs.discardCount[gs.whoseTurn] = 4;  
	memcpy(&testgs, &gs, sizeof(struct gameState));
	mySmithyFunction(&testgs, 0, 1);
	discardCard(0, gs.whoseTurn, &gs, 0);
	printf("Card Count --> EXPECTED: %d, GOT: %d\n", gs.discardCount[gs.whoseTurn], testgs.discardCount[testgs.whoseTurn]);
	printf("BEGIN Card Test 2, cardtest2.c: Smithy\n");
	return 0;
}