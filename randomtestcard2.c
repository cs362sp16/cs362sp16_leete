/*
 * Terrance Lee
 *
 * Assign3
 *
 * randomtestcard2.c
 *
 * testing salvager card
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define MAX_TESTS 1000

int main(int argc, char* argv[]) {

  srand(time(NULL));
  int k[10] = {adventurer, cutpurse, embargo, gardens, mine, 
                minion, sea_hag, smithy, tribute, village};
  int i, players; 
  int handPos, choice, currentPlayer, deckCount, randSeed, returnVal;
  int totalFailures = 0;
  struct gameState game;
  printf("Testing Salvager card \n");
  
  for (i = 0; i < MAX_TESTS; i++) {
    randSeed = rand();		
    printf("Test number: %d \n", i+1);
    players = (rand() % 4) + 1;
    currentPlayer = (rand() % players) + 1;
    printf("Players: %d\tCurrent: %d\n", players, currentPlayer);
    
    
    initializeGame(players, k, randSeed, &game);
    
    game.deckCount[currentPlayer] = (rand() % MAX_DECK) + 1;
    game.handCount[currentPlayer] = 5;
    game.discardCount[currentPlayer] = 0;
    handPos = (rand() % 5) + 1;
    choice = (rand() % 5) +1;
    
    deckCount = game.deckCount[currentPlayer];
    
    if (randSeed % 3 == 0) {
      
      printf("Testing with deck count of 0\n");
      game.deckCount[currentPlayer] = 0;
    }
    
    printf("Card returned: '%d'\n", returnVal);
    if (game.discardCount[currentPlayer] == 0){
      printf("Failure \n Current Player did not Discard \n");
      totalFailures++;
    }
    if (game.handCount[currentPlayer] >= 5){
      printf("Failure \n Hand Count is wrong \n Current Player: %d\n", game.handCount[currentPlayer]);
      totalFailures++;
    }
  }
  
  
  printf("Failure Count Total: %d\n", totalFailures);
  
  printf("Test is Finished.\n");
  
  return 0;
}
