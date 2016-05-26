/*
 * Terrance Lee
 *
 * Assign4
 *
 * testdominion.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define NUM_GAMES 20
#define RAND_SEED 4

struct cards cardsCounter(struct gameState * g);
char * cardStr(int card);
int cardPos(int c, struct gameState * g);

struct cards {
    int copper, silver, gold, adventurer, cutpurse, embargo, gardens, 
	mine, minion, sea_hag, smithy, tribute, village;
    };

int main()
{
    int j, k, m, seed, randomNumber, moves;
    struct gameState* game;
	

    seed = RAND_SEED;
    srand(seed);
    printf("Random seed is %i \n", seed);

    for (j=0 ; j<NUM_GAMES ; j++)
    {
        printf("initializing game #%i \n", j);

        randomNumber = rand();
        printf("Random number is %i \n", randomNumber);

        int numPlayers = randomNumber % 2 + 2;
        printf("Number of players is %i \n", numPlayers);

        
        game = malloc(sizeof(struct gameState));
        int kingdomCards[10] = {adventurer, cutpurse, embargo, gardens, mine, 
		minion, sea_hag, smithy, tribute, village};

       
        initializeGame(numPlayers, kingdomCards, randomNumber, game);

       
        int * pref;
        int prefEven[3] = {duchy, village, copper};
        int prefOdd[3] = {mine, silver, copper};

        moves = 0;
        
        while (!isGameOver(game))
        {
            moves += 1;
            
            struct cards cCount = cardsCounter(game);

            
            if (whoseTurn(game) % 2 == 0)
                pref = prefEven;
            
            else
                pref = prefOdd;

            
            k = 0;

            
            int money = cCount.silver + cCount.gold + cCount.copper;
            
            while( numHandCards(game) > k )
            {
                for( m=0 ; m<3 ; m++ )
                {
                    
                    if( handCard(m, game) == pref[m] )
                    {
                        
                        if( pref[m] == mine )
                        {
                            int count1, count2;
                            
                            if( cardPos(copper, game) > 0 )
                            {
                                
                                count1 = fullDeckCount(whoseTurn(game), copper, game);
                                count2 = fullDeckCount(whoseTurn(game), silver, game);
                                playCard(k, cardPos(copper, game), silver, -1, game);
                                printf("Player %i played a %s from position %i \n", whoseTurn(game),
                                                                                    cardStr(pref[m]),
                                                                                    k);
                                
                                assert(fullDeckCount(whoseTurn(game), copper, game) == count1-1);
                                assert(fullDeckCount(whoseTurn(game), silver, game) == count2+1);
                            }
                            else if( cardPos(silver, game) > 0 )
                            {
                                count1 = fullDeckCount(whoseTurn(game), silver, game);
                                count2 = fullDeckCount(whoseTurn(game), gold, game);
                                playCard(k, cardPos(silver, game), gold, -1, game);
                                printf("Player %i played a %s from position %i \n", whoseTurn(game),
                                                                                    cardStr(pref[m]),
                                                                                    k);
                                assert(fullDeckCount(whoseTurn(game), silver, game) == count1-1);
                                assert(fullDeckCount(whoseTurn(game), gold, game)   == count2+1);
                            }
                        }
                        else
                        {
                            
                            playCard(k, -1, -1, -1, game);
                            printf("Player %i played a %s from position %i \n", whoseTurn(game),
                                                                                cardStr(pref[m]),
                                                                                k);
                        }
                        break;
                    }
                }
                k += 1;
            }

            
            while( money > 0 )
            {
                
                if( money >= 5 )
                {
                    printf("Player %i bought a %s \n", whoseTurn(game), cardStr(pref[2]));
                    buyCard(pref[2], game);
                    money -= 5;
                }

                
                if( money >= 3 )
                {
                    printf("Player %i bought a %s \n", whoseTurn(game), cardStr(pref[1]));
                    buyCard(pref[1], game);
                    money -= 3;
                }

               
                if( money >= 0 )
                {
                    printf("Player %i bought a %s \n", whoseTurn(game), cardStr(pref[0]));
                    buyCard(pref[0], game);
                    money = 0;
                }
            }

            printf("Scores:\n");
            for( k=0 ; k<numPlayers ; k++ )
            {
                printf("Player %i, score %i \n", k, scoreFor(k, game));
            }

            
            endTurn(game);
            printf("%i has ended their turn \n", whoseTurn(game));
        }

        printf("Final Scores:\n");
        for( k=0 ; k<numPlayers ; k++ )
        {
            printf("Player %i, score %i \n", k, scoreFor(k, game));
        }
        printf("%i moves played \n", moves);

       
        free(game);
       
    }
    return 0;
}


struct cards cardsCounter(struct gameState * g)
{
    struct cards c;
    int i;

    c.copper = c.silver = c.gold = c.adventurer = c.gardens = c.embargo =
    c.village = c.minion = c.mine = c.cutpurse = c.sea_hag = c.tribute =
    c.smithy = 0;    

    for (i = 0; i < numHandCards(g); i++) {
        if (handCard(i, g) == copper)
            c.copper += 1;
        else if (handCard(i, g) == silver)
            c.silver += 1;
        else if (handCard(i, g) == gold)
            c.gold += 1;
        else if (handCard(i, g) == adventurer)
            c.adventurer += 1;
        else if (handCard(i, g) == gardens)
            c.gardens += 1;
        else if (handCard(i, g) == embargo)
            c.embargo += 1;
        else if (handCard(i, g) == village)
            c.village += 1;
        else if (handCard(i, g) == minion)
            c.minion += 1;
        else if (handCard(i, g) == mine)
            c.mine += 1;
        else if (handCard(i, g) == cutpurse)
            c.cutpurse += 1;
        else if (handCard(i, g) == sea_hag)
            c.sea_hag += 1;
        else if (handCard(i, g) == tribute)
            c.tribute += 1;
        else if (handCard(i, g) == smithy)
            c.smithy += 1;
    }

    return c;
}


char * cardStr(int card)
{
    char * strs[27] = {"curse", "estate", "duchy", "province", "copper", "silver",
    "gold", "adventurer", "council_room", "feast", "gardens", "mine",
    "remodel", "smithy", "village", "baron", "great_hall", "minion", "steward",
    "tribute", "ambassador", "cutpurse", "embargo", "outpost", "salvager",
    "sea_hag", "treasure_map"};

    return strs[card];
}


int cardPos(int c, struct gameState * g)
{
    int i;
    for( i=0 ; i<numHandCards(g) ; i++ )
    {
        if( handCard(i, g) == c )
        {
            return i;
            break;
        }
    }
    return 0;
}