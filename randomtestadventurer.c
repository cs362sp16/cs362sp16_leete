/*
 * Terrance Lee
 *
 * Assign3
 *
 * randomtestadventurer.c
 *
 * testing adventurer card
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define NUM_TESTS 500
#define GAME_LIMIT 6

// Randomly test adventurer card
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

    printf("Running Random Card Test for Adventure\n");

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
            if((game->hand[player][j] == copper) ||
               (game->hand[player][j] == silver) ||
               (game->hand[player][j] == gold))
                count++;
        }

        //Run adventure card
        cardEffect(adventurer, 1, 1, 1, game, 0, 0); 

        // Test that the card did a thing
        for( j=0 ; j<game->handCount[player]; j++ )
        {
            if((game->hand[player][j] == copper) ||
               (game->hand[player][j] == silver) ||
               (game->hand[player][j] == gold))
                count--;
        }
        if( count < 0 )
        {
            success++;
        } else {
            failures++;
        }

        // Memory leaks are super bad!
        free(game);

        printf("Completed test #%d\n", i);
    }

        printf("Status: %d failures and %d successful uses of the adventurer\n",
           failures,
           success);

    printf("%d games run\n",
           NUM_TESTS);

    printf("Why are we getting failures are they bad? I don't know you tell me your the smart one.\n");
}