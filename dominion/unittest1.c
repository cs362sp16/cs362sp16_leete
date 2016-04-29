/*Terrance Lee
 *
 * Assign 2 *
 * unittest1.c
 *
 * testing compare
 */

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"

#define FALSE 0
#define TRUE !(FALSE)

int compare(const void* a, const void* b); 

int main(int argc, char** argv){ 

        //creating variables
        int a, b;
                
        if(TRUE) {
                
        a = 15;
        b = 10;

        assert(compare(&a, &b) == 1);
        assert(compare(&b, &a) == -1);

        
        a = -5;
        b = -7;
        
        assert(compare(&a, &b) == 1);
        assert(compare(&b, &a) == -1);

        b = a;

        assert(compare(&a, &b) == 0);

       
                
        printf("compare() passed all test successfully\n");
        }

        else{
        printf("compare() failed a test\n");
        }

        return 0;
}
