/*
	Author: David Pardy
	OSU CS 362
	Spring 2018
	Assignment 4
*/

//village test
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	//set up cards
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int i, r, players, player, seed, fail = 0;
	struct gameState state;
	struct gameState temp; 
	srand(time(NULL)); //use for randomizing
	//100 tests max
	for (i = 0; i < 100; i++) {
		do {
			players = rand() % 4;
		} while (players < 2);

		seed = rand(); 
		//set up the game
		initializeGame(players, k, seed, &state);

		do {
			player = rand() % players; 
		} while (player == 0);	

		//set up valid states
		state.whoseTurn = player;
		state.deckCount[player] = rand() % 100;
		state.discardCount[player] = rand() % 100;
		state.handCount[player] = rand() % 100;
		state.hand[player][0] = village;
		state.numActions = rand() % 10; 
		//copy state memory to temp to temp, size will be of struct gameState
		memcpy(&temp, &state, sizeof(struct gameState));
		//run village card
		r = cardEffect(village, 0, 0, 0, &state, 0, 0);		
		assert (r == 0);
		if (state.deckCount[player] != (temp.deckCount[player] - 1)){ 
			fail++; 
		}
		//+2 Actions for Village
		if (state.numActions != (temp.numActions + 2)) { 
			fail++; 
		}		

	}	
	printf("Failures: %d\n", fail);
	return 0;
}