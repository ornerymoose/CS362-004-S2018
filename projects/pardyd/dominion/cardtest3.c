#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
  Card Test 3: Village Card
*/

int main(){
	int seed = 1000;
	int numPlayers = 2;
	struct gameState gs, testgs;
	int k[10] = {copper, minion, mine, silver, gold, cutpurse, sea_hag, tribute, smithy, council_room};
	printf("BEGIN Card Test 3, cardtest3.c: Village\n");
	initializeGame(numPlayers, k, seed, &gs);
	memcpy(&testgs, &gs, sizeof(struct gameState));
	myNewVillageFunction(&testgs, 0, 1);
	printf("EXPECTED: %d, GOT: %d\n", gs.handCount[gs.whoseTurn] + 1, testgs.handCount[testgs.whoseTurn]);
	memcpy(&testgs, &gs, sizeof(struct gameState));
	myNewVillageFunction(&testgs, 0, 1);
	printf("EXPECTED: %d, GOT: %d\n", gs.numActions + 2, testgs.numActions);
	printf("BEGIN Card Test 3, cardtest3.c: Village\n");
	return 0;
}