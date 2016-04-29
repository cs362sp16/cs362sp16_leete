/*
 * Terrance Lee
 *
 * Assign2 
 * unittest4.c
 *
 * testing isGameOver
 */

#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"

#define FALSE 0
#define TRUE !(FALSE)


int main(int argc, char** argv){
	
						
        struct gameState* game = newGame();
		
		int k[10] = {adventurer, cutpurse, embargo, gardens, mine, 
                minion, sea_hag, smithy, tribute, village};
				
		
		if(TRUE){
		initializeGame(2, k, 3, game);
		
		assert(isGameOver(game) == 0);
		
		//testing the supply piles
		game->supplyCount[0] = 0;
		assert(isGameOver(game) == 0);
		
		game->supplyCount[1] = 0;
		assert(isGameOver(game) == 0);
		
		game->supplyCount[10] = 0;
		assert(isGameOver(game) == 1);
		
		game = newGame();
		
		initializeGame(2, k, 3, game);
		
		assert(isGameOver(game) == 0);
		
		//testing province deck 
		game->supplyCount[province] = 0;
		assert(isGameOver(game) == 1);
		printf("isGameOver passed all test successfully\n");
		
		}else{
        printf("isGameOver failed a test\n");
        }

        return 0;

}

			
		
				
				
			
