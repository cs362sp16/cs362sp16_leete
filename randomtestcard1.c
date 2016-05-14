/*
 * Terrance Lee
 *
 * Assign3
 *
 * randomtestcard1.c
 *
 * testing mine card
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define NUM_TESTS 500
#define GAME_LIMIT 6

// Randomly test mine card
int main() {
    // Create array of cards in the game
    int k[10] = {adventurer, cutpurse, embargo, gardens, mine, 
                minion, sea_hag, smithy, tribute, village};

    // Create integers for misc use
    int i, j,
        players,
        seed,
        player = 0,
        retVal,
        count,
        failures,
        success;
		

    //struct gameState state;
    struct gameState * game;

    printf("Running Random Card Test for mine\n");

    // Runs NUM_TESTS.
    for( i=0, failures=0, success=0; i<NUM_TESTS ; i++ )
    {

        players = rand() % 4;
        seed = rand();		//pick random seed
        game = malloc(sizeof(struct gameState));

        //initialize Gamestate
        initializeGame(players, k, seed, game);

        //Initiate valid state variables
        //Pick random deck size out of MAX DECK size
        game->deckCount[player] = rand() % MAX_DECK; 
        game->discardCount[player] = rand() % MAX_DECK;
        game->handCount[player] = rand() % MAX_HAND;

        // Gather initial data to compare against later
        // Check for treasure cards
        count = 0;
        for( j=0 ; j<game->handCount[player]; j++ )
		{
        if (game->hand[player][j] == silver)
                count++;
        }


        //Run village card
        retVal = cardEffect(mine, copper, silver, 1, game, 0, 0); 
        // Print out failure details
        if( retVal != 0 )
        {
            // These are not in the scope of the test.
            if ((getCost(game->hand[player][copper])+3)
				> getCost(silver))
                   
            {
                printf("Test %i got cut short\n", i);
            } else {

                printf("Failure in test #%d\n", i);
                printf("cardEffect returned %d\n", retVal);
                failures++;
            }

        // Compare previous state to new state
        } else {
            // Check that we have at least one more copper in our hand
            for( j=0 ; j<game->handCount[player];  j++ )
            {
                if (game->hand[player][j] == copper )
                {
                    count--;
                }
            }

            if ( count < 0 ) {
                success++;
            }
        }

        // Memory leaks are super bad!
        free(game);

        printf("Completed test #%d\n", i);
    }

    printf("\n\n");
    printf("Status: %d failures and %d successful uses of the mine\n",
           failures,
           success);

    printf("%d games run\n",
           NUM_TESTS);

    printf("What happened to the rest of them?\n How many times do I have to tell you. Your the smart one I'm just here for the money. \n");
}