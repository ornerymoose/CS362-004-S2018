/*
	Author: David Pardy
	OSU CS 362
	Spring 2018
	Assignment 4
*/

//adventurer test
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"


int main() {
  	srand(time(NULL)); //used for seeding
	struct gameState g;
  	int numTests = rand() % 80 + 21; //range is 80 and min is 21
	int seed = rand() % 80 + 21;
	int passed = 0, pass = 0, beforeHand = 0, afterHand = 0;
	int draw = 0, discard = 0;
	int player = 0, randDeck, randHand, randCard, randKCard;
	int copper, silver, gold;
	int beforeCoins = 0, afterCoins = 0;
	int i, j, n;
	//set array for cards
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, remodel, tribute, smithy, council_room };
	//iterate through number of tests
	for (i = 0; i < numTests; i++) {
		//set up game
		initializeGame(2, k, seed, &g);
		beforeCoins = 0, afterCoins = 0;
		randDeck = rand() % (500 + 1); //range of 500, min is 1 for decks
		randHand = rand() % (randDeck + 1);
		g.deckCount[0] = randDeck - randHand;
		g.handCount[0] = randHand;
		for (j = 0; j < 2; j++) {
			for (n = 0; n < g.deckCount[j]; n++) {
				randCard = rand() % 51; //randomize card
				//based on randCard value, set up the deck 
				if (randCard == 1)
					g.deck[j][n] = copper;
				else if (randCard == 2)
					g.deck[j][n] = silver;
				else if (randCard == 3)
					g.deck[j][n] = gold;
				else {
					randKCard = rand() % 10;
					g.deck[j][n] = k[randKCard];
				}
			}
		}
		for (j = 0; j < g.handCount[player]; j++) {
			if (g.hand[player][j] == copper || g.hand[player][j] == silver || g.hand[player][j] == gold)
				beforeCoins += 1;
		}
    printf("=====>\n");
    printf("| Before Coins: %d\n", beforeCoins);
    beforeHand = g.handCount[g.whoseTurn];
    printf("| Before Hand: %d\n", beforeHand);
		cardEffect(adventurer, 0, 0, 0, &g, 0, 0);
		for (j = 0; j < g.handCount[player]; j++) {
			if (g.hand[player][j] == copper || g.hand[player][j] == silver || g.hand[player][j] == gold)
				afterCoins += 1;
		}
    printf("| After Coins: %d\n", afterCoins);
    beforeHand = g.handCount[g.whoseTurn];
    printf("| After Hand: %d\n", afterHand);
    printf("=====>\n");
		copper = 0, silver = 0, gold = 0;
		for (j = 0; j < g.discardCount[player]; j++) {
			if (g.discard[player][j] == copper)
				copper += 1;
			else if (g.discard[player][j] == silver)
				silver += 1;
			else if (g.discard[player][j] == gold)
				gold += 1;
		}
		pass = 1;
		if (afterCoins != (beforeCoins + 2) || afterCoins < beforeCoins) {
			draw++;
			pass = 0;
		}
		if (gold != 0 || silver != 0 || copper != 0) {
			discard++;
			pass = 0;
		}
		if (pass == 1)
			passed++;
	}
	printf(" \n");
  printf("=====>\n");
	printf("| ADVENTURER: Test Results\n");
	printf("| Passed: %d\n", passed);
	printf("| Failed Draw: %d\n", draw);
	printf("| Failed Discard: %d\n", discard);
  printf("=====>\n");
	return 0;
}