#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>

/*
	UNIT TEST: whosTurn()
*/

int main (int argc, char** argv)	{
    struct gameState g;
    int a;
	int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
	
	printf("UNIT TEST: whoseTurn() function\n");
	printf("INIT GAME WITH 2 PLAYERS: UP TO 4\n");
    for (int i = 2 ; i < 5 ; i++)	{
        a = initializeGame(2, k, 5, &g);
        a = whoseTurn(&g);
        assert(a == g.whoseTurn);
		printf("PASSING\n");		
	}
	return 0;
}