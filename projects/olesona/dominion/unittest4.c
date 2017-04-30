/************************************************
 * File: unittest4.c
 * Author: Alannah Oleson
 * CS 362 Assignment 3
 * Description: A unit test for the fullDeckCount() function
 *    in dominion.c. Tests that deck (the deck, the hand, and
 *    the discard) contains the right number of cards.
 * *********************************************/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"


int main () {

   int i, j, k = 0;
   int val = 0;
   int randomCard = 0;
   int randomChoice = 0;
   int count = 0;
   time_t t;
   struct gameState *g = malloc(sizeof(struct gameState));

   srand((unsigned) time(&t));


   printf("\n UNIT TEST 4: fullDeckCount() \n");


   //Test for each player
   for (j = 0; j < MAX_PLAYERS; j++) {

      for (i = 0; i < treasure_map + 1; i++) {

	 g->deckCount[j] = 0;
	 g->handCount[j] = 0;
	 g->discardCount[j] = 0;
	 count = 0;

	 //Fill up the deck randomly
	 for (k = 0; k < MAX_DECK; k++) {

	    randomCard = rand() % treasure_map+1;
	    if (randomCard == i) {
	       count++;		//Keep your own count to check against
	    }

	    //Put the card in a random pile
	    randomChoice = rand() % 3;

	    //To the deck
	    if (randomChoice == 0) {
	       g->deck[j][g->deckCount[j]] = randomCard;
	       g->deckCount[j]++;
	    }
	    
	    //To the hand
	    else if (randomChoice == 1) {
	       g->hand[j][g->handCount[j]] = randomCard;
	       g->handCount[j]++;
	    }

	    //To discard
	    else if (randomChoice == 2) {
	       g->discard[j][g->discardCount[j]] = randomCard;
	       g->discardCount[j]++;
	    }

	 }

	 val = fullDeckCount(j, i, g);
	 printf("\t Expected count: %d. Returned value: %d \n", count, val);
	 assert(val == count);
	 printf("\t Test passed!\n");

      }

   }




   //If we got here, we're good!
   printf("UNIT TEST 4: fullDeckCount() - ALL TESTS PASSED!\n\n");

   return 0;

} 
