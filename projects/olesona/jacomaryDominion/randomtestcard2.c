/* **********************************************
 * File: randomtestcard2.c
 * Author: Alannah Oleson
 * CS 362, Assignment 4
 * Description: A random test generator for the great hall card.
 * *********************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>


int main () {

   struct gameState g;

   int seed = 1000;
   int numTestsPassed = 0, passedAllTestsFlag = 0;
   int numPlayers = 2, currPlayer = 0;
   int deckSize, handSize, startHand, currHand, startNumActions, currNumActions;
   int failedHandCount = 0, failedActionsCount = 0;
   int i = 0;
   int choice1 = 0, choice2 = 0, choice3 = 0, handPos = 0, bonus = 0;

   int allowedCards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

   srand(time(NULL));


   for (i = 0; i < 123456; i++) {

      //randomly intialize the game state. then make sure the needed variables are sane.
      initializeGame(numPlayers, allowedCards, seed, &g);

      deckSize = rand() % (MAX_DECK + 1);
      handSize = rand() % (deckSize + 1);

      g.deckCount[0] = deckSize - handSize;
      g.handCount[0] = handSize;
      g.numActions = rand() % 10;
      handPos = g.hand[currPlayer][g.handCount[currPlayer]-1];


      //Note the current state before playing the card
      startHand = g.handCount[0];
      startNumActions = g.numActions;


      //Play the card
      cardEffect(great_hall, choice1, choice2, choice3, &g, handPos, &bonus);


      //Note the state after playing the card
      currHand = g.handCount[0];
      currNumActions = g.numActions;
      if (rand() % 100 == 1) {	//Test for an intentionally bad condition
	 currNumActions += 1;
      }


      //NOW... the moment of reckoning... the tests
      passedAllTestsFlag = 1;

      printf("Testing Great Hall card...\n");

      if (currHand != startHand) {
	 printf("\tCards drawn - FAIL\n");
	 failedHandCount++;
	 passedAllTestsFlag = 0;
      }
      else {
	 printf("\tCards drawn - PASS\n");
      }

      if (currNumActions != startNumActions + 1) {
	 printf("\tActions - FAIL\n");
	 failedActionsCount++;
	 passedAllTestsFlag = 0;
      }
      else {
	 printf("\tActions - PASS\n");
      }


      if (passedAllTestsFlag == 1) {
	 printf("All tests passed!!\n");
	 numTestsPassed++;
      }

   }

      
   printf("Great Hall tests summary:\n");
   printf("\tPASSED: %d\n", numTestsPassed);
   printf("\tFAILED (hand): %d\n", failedHandCount);
   printf("\tFAILED (actions): %d\n\n", failedActionsCount);

   

   return 0;

}
