/*
    Author: David Pardy
    OSU CS 362
    Spring 2018
    Assignment 4
*/

//smithy test
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include "rngs.h"

//prototype
int assertTruthiness(int);

int main() {
    srand(time(NULL)); //use for randomizing
    int handSuccess = 0;
    int deckSuccess = 0;
    int i;
    //100 tests at the most
    for (i = 0; i < 100; i++) {    
        struct gameState state;
        int players = 2;
        int seed = rand();
        int choice1 = 0;    
        int choice2 = 0;    
        int choice3 = 0;    
        int handPos = 0;
        int bonus = 0; 
    	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
        //start game
        initializeGame(players, k, seed, &state);
        int handCountBefore = numHandCards(&state);
        int deckCountBefore = state.deckCount[0];
        //play smithy
        int played = (cardEffect(smithy, choice1, choice2, choice3, &state, handPos, &bonus) == 0);
        assertTruthiness(played);
        int handCountAfter = numHandCards(&state);
        int deckCountAfter = state.deckCount[0];
        // test against 2 because we played 1
        handSuccess += assertTruthiness((handCountAfter - handCountBefore) == 2);
    
        // test against 4 because we draw 3
        deckSuccess += assertTruthiness((deckCountBefore - deckCountAfter) == 4);
    }
    printf("Correct Number of Cards in Hand: %d of %d times.\n", handSuccess, 100);
    printf("Correct Number of Cards in Deck: %d of %d times.\n", deckSuccess, 100);
	printf("=====>\n");
    return 0;
}

int assertTruthiness(int statement) {
    if (statement) {
        return TRUE;
    } else {
        return FALSE;
    }
}