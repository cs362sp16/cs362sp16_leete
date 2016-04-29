/*
 * Terrance Lee
 *
 * Assign2
 * cardtest1.c
 *
 * testing outpost_fn
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define DEBUG 0
#define MIN_PLAYERS 2


int main(int argc, char const *argv[]){
        
        //create game state
       struct gameState game;

        //create variables;
        int i, j, testValue;
        int testSwitch = 0;
        int k[10] = {adventurer, cutpurse, embargo, gardens, mine, 
                minion, sea_hag, smithy, tribute, village};
        
        //set the flag for the current card
        int myCard = outpost;
        int myChoice1 = -1;        
        int myChoice2 = -1;
        int myChoice3 = -1;
        int myHandPos = -1;

        
        int* myBonus = 0;
				
        for(i = MIN_PLAYERS; i < MAX_PLAYERS + 1; i++){

                //initialize 9 game states for each possible number of players
                for(j = 1; j < 10; j++){

                        //initalize a game with 2 to 4 and seeds between 1-9 as 
                        //specified in rngs.c
                        initializeGame(i, k, j, &game);

                        
                        //Get outpostcard flag
                        int testOutpostCardPlayed = game.outpostPlayed;
						
						                     
                        //choices 1-3, and handPos currently reflect the values hard coded from the playDom
                        testValue = cardEffect(myCard, myChoice1, myChoice2, myChoice3, &game, myHandPos, myBonus);

						if(testValue == -1){
							printf("outpost failed a test\n");
							testSwitch = 1;
														
						}else if(testValue == 0){
							if(game.outpostPlayed == (testOutpostCardPlayed + 1)){
								testSwitch = 1;
								
							}
							
						
						}
				}
		
		}
		if(testSwitch == 0)
		printf("Outpost passed all test successfully\n");

	
	return 0;
	
}
                        
                       