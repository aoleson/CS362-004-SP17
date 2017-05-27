/* **********************************************
 * File: randomtestcard1.c
 * Author: Alannah Oleson
 * CS 362, Assignment 4
 * Description: A random test generator for the smithy card.
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
   int deckSize, handSize, startDeck, currDeck, startHand, currHand, startDiscard, currDiscard;
   int failedDeckCount = 0, failedHandCount = 0, failedDiscardCount = 0;
   int i = 0;
   int choice1 = 0, choice2 = 0, choice3 = 0, handPos = 0, bonus = 0;

   int allowedCards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

   srand(time(NULL));


   for (i = 0; i < 123456; i++) {

      //Randomly intialize the game state. Then make sure the needed variables are sane.
      initializeGame(numPlayers, allowedCards, seed, &g);

      deckSize = rand() % (MAX_DECK + 1);
      handSize = rand() % (deckSize + 1);

      g.deckCount[0] = deckSize - handSize;
      g.handCount[0] = handSize;
      handPos = g.hand[currPlayer][g.handCount[currPlayer]-1];


      //Note the current state before playing the card
      startDeck = g.deckCount[0];
      startHand = g.handCount[0];
      startDiscard = g.playedCardCount;


      //Play the card
      cardEffect(smithy, choice1, choice2, choice3, &g, handPos, &bonus);


      //Note the state after playing the card
      currDeck = g.deckCount[0];
      currHand = g.handCount[0];
      currDiscard = g.playedCardCount;


      //NOW... the moment of reckoning... the tests
      passedAllTestsFlag = 1;

      printf("Testing Smithy card...\n");

      if (currDeck != (startDeck - 3)) {
	 printf("\tDeck count - FAIL\n");
	 failedDeckCount++;
	 passedAllTestsFlag = 0;
      }
      else {
	 printf("\tDeck count - PASS\n");
      }

      if (currHand != (startHand + 2)) {
	 printf("\tCards drawn - FAIL\n");
	 failedHandCount++;
	 passedAllTestsFlag = 0;
      }
      else {
	 printf("\tCards drawn - PASS\n");
      }

      if (currDiscard != (startDiscard + 1)) {
	 printf("\tCards discarded - FAIL\n");
	 failedDiscardCount++;
	 passedAllTestsFlag = 0;
      }
      else {
	 printf("\tCards discarded - PASS\n");
      }


      if (passedAllTestsFlag == 1) {
	 printf("All tests passed!!\n");
	 numTestsPassed++;
      }

   }

      
   printf("Smithy tests summary:\n");
   printf("\tPASSED: %d\n", numTestsPassed);
   printf("\tFAILED (deck): %d\n", failedDeckCount);
   printf("\tFAILED (hand): %d\n", failedHandCount);
   printf("\tFAILED (discard): %d\n\n", failedDiscardCount);

   

   return 0;

}
