#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>

/*
	UNIT TEST: buyCard()
*/

int main() {
  int passed = 0;
  int p1 = 1;
  int money1 = 4;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, great_hall};
  struct gameState g;
  initializeGame(2, k, 100, &g);
  printf("UNIT TEST: buyCard() function\n");
  g.whoseTurn = p1;
  g.coins = money1;
  buyCard(silver, &g);
  printf("Player 1 bought silver.\n");
  printf("Top of discard: %d.\n", g.discard[g.whoseTurn][g.discardCount[g.whoseTurn]]);
  if (g.discard[g.whoseTurn][g.discardCount[g.whoseTurn - 1]] == silver){
  	printf("PASSED\n");
  } else {
    printf("FAILED\n");
    passed = 1;
  }
  if (passed == 0)
    printf("PASSING: buyCard()\n");
  else
    printf("FAILED: buyCard()\n");
  return 0;
}