/************************************************
 * File: cardtest1.c
 * Author: Alannah Oleson
 * CS 362 Assignment 3
 * Description: A unit test for the smithy card in dominion.c. 
 * *********************************************/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"


int main () {

   int allowed_cards[10] = {adventurer, embargo, village, minion, mine, cutpurse, remodel, tribute, smithy, council_room};
   int i = 0;
   int drawnCards = 3;
   int discardedCards = 1;
   int handPos = 0;
   int choice1 = 0, choice2 = 0, choice3 = 0;
   int bonus = 0;
   int success_flag = 1;

   struct gameState g, testMe;

   initializeGame(2, allowed_cards, 100, &g);

   printf("\nCARD TEST 1: SMITHY\n");


   //Test if the handcount goes up by 3 for the player who plays it
   memcpy(&testMe, &g, sizeof(struct gameState));

   cardEffect(smithy, choice1, choice2, choice3, &testMe, handPos, &bonus);

   if (testMe.handCount[0] != g.handCount[0] + drawnCards - discardedCards) {
      success_flag = 0;
      printf("\tFAIL: Hand count after playing smithy was not correct. Expected %d, got %d\n", g.handCount[0] + drawnCards - discardedCards, testMe.handCount[0]);
   }
   else {
      printf("\tPASS: Correct hand count after playing smithy (+3)\n");
   }


   //Test if the deckcount goes down by 3 for the 3 cards drawn
   if (testMe.deckCount[0] != g.deckCount[0] - drawnCards) {
      success_flag = 0;
      printf("\tFAIL: Deck count after playing smithy was not correct. Expected %d, got %d\n", g.deckCount[0] - drawnCards, testMe.deckCount[0]);
   }
   else {
      printf("\tPASS: Correct deck count after playing smithy (-3)\n");
   }


   //Test if the score changed - it should be the same as before
   if (scoreFor(0, &testMe) != scoreFor(0, &g)) {
      success_flag = 0;
      printf("\tFAIL: Score after playing smithy was not correct. Expected %d, got %d\n", scoreFor(0, &g), scoreFor(0, &testMe));
   }
   else {
      printf("\tPASS: Correct score after playing smithy (no change)\n");
   }


   //Test if the other player's state is the same - hand, deck, and score
   if (testMe.handCount[1] != g.handCount[1]) {
      success_flag = 0;
      printf("\tFAIL: Player 2's handcount changed after player 1 played smithy. Expected %d, got %d\n", g.handCount[1], testMe.handCount[1]);
   }
   else {
      printf("\tPASS: Player 2's handcount unchanged after player 1 played smithy\n");
   }

   if (testMe.deckCount[1] != g.deckCount[1]) {
      success_flag = 0;
      printf("\tFAIL: Player 2's deckcount changed after player 1 played smithy. Expected %d, got %d\n", g.deckCount[1], testMe.deckCount[1]);
   }
   else {
      printf("\tPASS: Player 2's deckcount unchanged after player 1 played smithy\n");
   }

   if (scoreFor(1, &testMe) != scoreFor(1, &g)) {
      success_flag = 0;
      printf("\tFAIL: Score for player 2 changed when player 1 played smithy. Expected %d, got %d\n", scoreFor(1, &g), scoreFor(1, &testMe));
   }
   else {
      printf("\tPASS: Player 2's score unchanged after player 1 played smithy\n");
   }


   //Test if victory cards piles are the same
   if (testMe.supplyCount[estate] != g.supplyCount[estate]) {
      success_flag = 0;
      printf("\tFAIL: Number of estate cards differed. Expected %d, got %d\n", g.supplyCount[estate], testMe.supplyCount[estate]);
   }
   else {
      printf("\tPASS: Number of estate cards the same after playing smithy\n");
   }

   if (testMe.supplyCount[duchy] != g.supplyCount[duchy]) {
      success_flag = 0;
      printf("\tFAIL: Number of duchy cards differed. Expected %d, got %d\n", g.supplyCount[duchy], testMe.supplyCount[duchy]);
   }
   else {
      printf("\tPASS: Number of duchy cards the same after playing smithy\n");
   }

   if (testMe.supplyCount[province] != g.supplyCount[province]) {
      success_flag = 0;
      printf("\tFAIL: Number of province cards differed. Expected %d, got %d\n", g.supplyCount[province], testMe.supplyCount[province]);
   }
   else {
      printf("\tPASS: Number of province cards the same after playing smithy\n");
   }


   //Test if kingdom card piles are the same
   for (i = 0; i < 10; i++) {

      if (testMe.supplyCount[allowed_cards[i]] != g.supplyCount[allowed_cards[i]]) {
	 success_flag = 0;
	 printf("\tFAIL: Kingdom card pile #%d did not contain the same number of cards\n", i);
      }
      else {
	 printf("\tPASS: Kingdom card pile #%d contained the same number of cards as before\n", i);
      }

   }


   if (success_flag) {
      printf("\nSMITHY: ALL TESTS SUCCESSFULLY COMPLETED!!\n\n");
   }
   else {
      printf("\nSMITHY: AT LEST ONE TEST FAILED. CHECK OUTPUT FOR MORE INFO\n\n");
   }


   return 0;

}
