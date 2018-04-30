#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>

/*
	UNIT TEST: isGameOver()
*/

int main(){
    printf("UNIT TEST: isGameOver() function\n");
    struct gameState state;
    int players = 2;
    int seed = 100;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	
    initializeGame(players, k, seed, &state);
    state.supplyCount[province] = 0; 
    printf("\nNO PROVINCES LEFT:\n");
    if (isGameOver(&state)){
		printf("PASSING\n");
	} else {
		printf("FAILED\n");
	}
    state.supplyCount[province] = 1;
 
    for(int card = curse; card <= treasure_map; card++) {
    	if (card < 3) {
    		state.supplyCount[card] = 0;
    	} else {
    		state.supplyCount[card] = 5;
    	}
    }
    
    printf("\nFIRST THREE EMPTY PILES:\n");
    if (isGameOver(&state)){
		printf("PASSING\n");
	} else {
		printf("FAILED\n");
	}
	
    for(int card = curse; card <= treasure_map; card++) {
        if (card > treasure_map - 3) {
        	state.supplyCount[card] = 0;
        } else {
        	state.supplyCount[card] = 5;
        }   
    }

    printf("\nLAST 3 EMPTY PILES:\n");
    if (isGameOver(&state)){
		printf("PASSING\n");
	} else {
		printf("FAILED\n");
	}
    return 0;
}

