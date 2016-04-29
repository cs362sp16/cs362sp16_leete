/*
 * Terrance Lee
 *
 * Assign *
 * unittest2.c
 *
 * test kingdomCards
 */

#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"

#define FALSE 0
#define TRUE !(FALSE)

int main(int argc, char** argv) {
        
		int* kingdomCards();
		
        //creating k variable
        int* k = kingdomCards(adventurer, council_room, cutpurse, embargo, gardens,
                        mine, minion, outpost, steward, tribute);
        
        if(TRUE){
        assert(k != NULL);
        assert(k[0] == adventurer);
        assert(k[1] == council_room);
        assert(k[2] == cutpurse);
        assert(k[3] == embargo);
        assert(k[4] == gardens);
        assert(k[5] == mine);
        assert(k[6] == minion);
        assert(k[7] == outpost);
        assert(k[8] == steward);
        assert(k[9] == tribute);

        free(k);
        
        printf("kingdomCards() passed all test successfully\n");
        }

        else{
        printf("kingdomCards() failed a test\n");
        }

        return 0;

}
