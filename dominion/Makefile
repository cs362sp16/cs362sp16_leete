CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM

	
u1: unittest1.c dominion.o rngs.o
	gcc -o u1 unittest1.c -g dominion.o rngs.o -Wall -std=c99 -fpic -coverage -lm

u2: unittest2.c dominion.o rngs.o
	gcc -o u2 unittest2.c -g dominion.o rngs.o -Wall -std=c99 -fpic -coverage -lm

u3: unittest3.c dominion.o rngs.o
	gcc -o u3 unittest3.c -g dominion.o rngs.o -Wall -std=c99 -fpic -coverage -lm

u4: unittest4.c dominion.o rngs.o	
	gcc -o u4 unittest4.c -g dominion.o rngs.o -Wall -std=c99 -fpic -coverage -lm

c1: cardtest1.c dominion.o rngs.o
	gcc -o c1 cardtest1.c -g dominion.o rngs.o -Wall -std=c99 -fpic -coverage -lm

c2: cardtest2.c dominion.o rngs.o
	gcc -o c2 cardtest2.c -g dominion.o rngs.o -Wall -std=c99 -fpic -coverage -lm

c3: cardtest3.c dominion.o rngs.o
	gcc -o c3 cardtest3.c -g dominion.o rngs.o -Wall -std=c99 -fpic -coverage -lm

c4: cardtest4.c dominion.o rngs.o
	gcc -o c4 cardtest4.c -g dominion.o rngs.o -Wall -std=c99 -fpic -coverage -lm


unittestresults.out:  u1 u2 u3 u4 c1 c2 c3 c4 dominion.c rngs.c 
		
	./u1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
		
	./u2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	./u3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	./u4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	./c1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	./c2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	./c3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	./c4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	
	