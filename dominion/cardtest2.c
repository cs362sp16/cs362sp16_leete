/*
 * Terrance Lee
 *
 * Assign2
 * cardtest2.c
 *
 * testing salvager
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
        int myCard = salvager;
        int myChoice1 = -1;        
        int myChoice2 = -1;
        int myChoice3 = -1;
        int myHandPos = -1;

        // tracks coins gained from the actions
        int* myBonus = 0;
		int testNumBuys;
		int testCoins;
				
		
        for(i = MIN_PLAYERS; i <(MAX_PLAYERS + 1); i++){

                //initialize 9 game states for each possible number of players
                for(j = 1; j < 10; j++){

                        //initalize a game with 2 to 4 and seeds between 1-9 as 
                        //specified in rngs.c
                        initializeGame(i, k, j, &game);

						//Get base game -> numBuys to compare later
                        testNumBuys = game.numBuys;                
						testCoins = game.coins;
						
						testValue = cardEffect(myCard, myChoice1, myChoice2, myChoice3, &game, myHandPos, myBonus);
						
						
						if(testValue == -1){
							printf("Salvager failed a test\n");
							testSwitch = 1;
							
							
			       }else if (testValue == 0){
					if (game.numBuys != (testNumBuys + 1)){
						printf("testNumBuys[%d], game.numBuys[%d]\n", testNumBuys, game.numBuys);
						testSwitch = 1;
					}
					
					//returns the value of the card select and adds it into the testCard
					//testCoins = testCoins + getCost(handCard(myChoice1, game));
					if(testCoins != game.coins){
						printf("testCoins[%d], game.coins[%d]\n", testCoins, game.coins);
						testSwitch = 1;
						}
						
					}
		
		}
}
	if(testSwitch == 0)
		printf("Salvager passed all test successfully\n");

	
	return 0;
	
}
						
					
				