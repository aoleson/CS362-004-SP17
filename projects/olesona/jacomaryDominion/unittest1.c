/************************************************
 * File: unittest1.c
 * Author: Alannah Oleson
 * CS 362 Assignment 3
 * Description: A unit test for the getCost() function
 *    in dominion.c. Tests each potential case of the switch.
 * *********************************************/

#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"


int main () {

   int i = 0;
   int val = 0;

   printf("\n UNIT TEST 1: getCost() \n");

   //Check each case in the range -5 to 30
   for (i = -5; i < 30; i++) {
      
      val = getCost(i);

      switch(i) {

	 case curse:
	    assert(val == 0);
	    break;

	 case estate:
	    assert(val == 2);
	    break;

	 case duchy:
	    assert(val == 5);
	    break;

	 case province:
	    assert(val == 8);
	    break;

	 case copper:
	    assert(val == 0);
	    break;

	 case silver:
	    assert(val == 3);
	    break;

	 case gold:
	    assert(val == 6);
	    break;

	 case adventurer:
	    assert(val == 6);
	    break;

	 case council_room:
	    assert(val == 5);
	    break;

	 case feast:
	    assert(val == 4);
	    break;

	 case gardens:
	    assert(val == 4);
	    break;

	 case mine:
	    assert(val == 5);
	    break;

	 case remodel:
	    assert(val == 4);
	    break;

	 case smithy:
	    assert(val == 4);
	    break;

	 case village:
	    assert(val == 3);
	    break;

	 case baron:
	    assert(val == 4);
	    break;

	 case great_hall:
	    assert(val == 3);
	    break;

	 case minion:
	    assert(val == 5);
	    break;

	 case steward:
	    assert(val == 3);
	    break;

	 case tribute:
	    assert(val == 5);
	    break;

	 case ambassador:
	    assert(val == 3);
	    break;

	 case cutpurse:
	    assert(val == 4);
	    break;

	 case embargo:
	    assert(val == 2);
	    break;

	 case outpost:
	    assert(val == 5);
	    break;

	 case salvager:
	    assert(val == 4);
	    break;

	 case sea_hag:
	    assert(val == 4);
	    break;

	 case treasure_map:
	    assert(val == 4);
	    break;

      }

      //If it didn't hit a switch case, it's invalid - 
      //Make sure it returns an error code
      if (i < 0 || i > 26) {
	 assert(val == -1);
      }


      //If the assert didn't fail - we passed this test
      printf("\t Test passed: Input i = %d. Returned value = %d \n", i, val);

   }

   //If we get to here - yay!
   printf("UNIT TEST 1: getCost() - ALL TESTS PASSED!\n\n");

   return 0;

}
