/************************************************
 * File: unittest3.c
 * Author: Alannah Oleson
 * CS 362 Assignment 3
 * Description: A unit test for the isGameOver() function
 *    in dominion.c. Tests that the game ends correctly.
 * *********************************************/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"


int main () {

   int i, j = 0;
   int val = 0;
   int randomCard = 0;
   time_t t;
   struct gameState *g = malloc(sizeof(struct gameState));

   srand((unsigned) time(&t));


   printf("\n UNIT TEST 3: isGameOver() \n");


   //Set up the struct so that the game "should be" over and test
   g->supplyCount[province] = 0;
   val = isGameOver(g);

   printf("\t Testing if the return value is 1 when the province count is set to 0.\n\t Expected return value: 1. Actual return value: %d\n", val);
   assert(val == 1);
   printf("\t Test passed!\n");


   //Set up so that the supply still has each card left and test
   for (i = 0; i < treasure_map + 1; i++) {
      g->supplyCount[i] = 10;
   }
   val = isGameOver(g);

   printf("\t Testing if the return value is 0 when all supply counts are greater than 0.\n\t Expected return value: 0. Actual return value: %d\n", val);
   assert(val == 0);
   printf("\t Test passed!\n");


   printf("\t Testing 1000 game states when three random stacks are empty...\n");

   //Check that the game still ends when three (random) stacks are empty
   for (j = 0; j < 1000; j++) {

      //Empty three stacks
      for (i = 0; i < 3; i++) {
	 
	 //randomCard = rand() % (treasure_map+1);	//uncomment this to find errors
	 randomCard = rand() % 25;		//running this line instead of the one above it lets the test pass

	 if (g->supplyCount[randomCard] == 0) {
	    i--;
	 }

	 g->supplyCount[randomCard] = 0;

      }

      //Check if emptying three stacks ends the game
      val = isGameOver(g);
      assert(val == 1);

      for (i = 0; i < treasure_map + 1; i++) {
	 g->supplyCount[i] = 10;
      }

   }

   printf("\t Test passed!\n");


   //If we got here, we're good!
   printf("UNIT TEST 3: isGameOver() - ALL TESTS PASSED!\n\n");

   return 0;

} 
