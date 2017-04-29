/************************************************
 * File: unittest2.c
 * Author: Alannah Oleson
 * CS 362 Assignment 3
 * Description: A unit test for the updateCoins() function
 *    in dominion.c. Tests that the number of coins is 
 *    updated correctly.
 * *********************************************/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"


int main () {

   int i, j = 0;
   int randomCoin = 0;
   int coinCount = 0;
   time_t t;
   struct gameState *g = malloc(sizeof(struct gameState));

   srand((unsigned) time(&t));


   printf("\n UNIT TEST 2: updateCoins() \n");


   //Check that it works for each player
   for (i = 0; i < MAX_PLAYERS; i++) {

      coinCount = 0;
      randomCoin = rand() % 3;		//Resolves to copper/silver/gold choice

      //Fill the hand with coins, so the updateCoins function has something to work with
      for (j = 0; j < g->handCount[i]; j++) {

	 if (randomCoin == 0) {
	    g->hand[i][j] = copper;
	    coinCount += 1;
	 }

	 if (randomCoin == 1) {
	    g->hand[i][j] = silver;
	    coinCount += 2;
	 }

	 if (randomCoin == 2) {
	    g->hand[i][j] = gold;
	    coinCount += 3;
	 }

      }


      //Test out updateCoins to see if it works
      updateCoins(i, g, 0);

      printf("\t +0: Expected coin count: %d. Actual coin count: %d \n", coinCount, g->coins);
      assert(coinCount == g->coins);


      //Test again with an updated value (to see if the bonus works)
      coinCount += 1;
      updateCoins(i, g, 1);

      printf("\t +1: Expected coin count: %d. Actual coin count: %d \n", coinCount, g->coins);
      assert(coinCount == g->coins);


   }

   //If we got here, we're good!
   printf("UNIT TEST 2: updateCoins() - ALL TESTS PASSED!\n\n");

   return 0;

} 
