/*  
 *  Terrance Lee
 *
 *  Assign2 *
 *  Unittest3.c
 *  
 *  testing fullDeckCount
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"

#define MAX_DECK 500

int main(int argc, char** argv){

        struct gameState game;
		
		
		int testValue;
		int k[10] = {adventurer, cutpurse, embargo, gardens, mine, 
                minion, sea_hag, smithy, tribute, village};
		int decks = 4; 
		int maxDeck = Random() * MAX_DECK;
		int d = Random() * 3;	
							   
					   //starting test of fullDeckCount
                       initializeGame(decks, k, maxDeck, &game);
					   testValue = fullDeckCount(d, decks, &game);
					   
					   if(testValue == 0){
						   printf("fullDeckCount passed all test Successfully\n");
					   }
					   else{
						   printf("fullDeckCount failed a test\n");
					   }
					   
					 	   
					   
					   return 0;
}			   
						
						
						
						
						