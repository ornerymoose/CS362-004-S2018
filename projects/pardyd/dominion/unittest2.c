#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>

/*
	UNIT TEST: kingdomCards()
*/

int main(){
	int items[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("UNIT TEST: kingdomCards() function\n");
    int *test = kingdomCards(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    for (int i = 0; i < 10; i++) {
        printf("POSITION %d\n", i);
		if (items[i] == *(test + i)){
			printf("PASSING\n");
		} else {
			printf("FAILED\n");
		}
    }
    return 0;
}