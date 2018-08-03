#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 500 


int main() {
    
    //declare variables
    struct gameState game;
    int players; 
    int player; 
    int k[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int seed;  
    int coinBonus;
    int handPos;
    int choice1 = 0;
    int choice2 = 0; 
    int choice3 = 0; 
    int test_failed = 0; 	
    srand(time(NULL));
    int test_status = 1; 	

printf("/*********************** Randomly Testing Smithy Card **************************/\n");

    for (int i = 0; i < MAX_TESTS; i++) {

	//randomly initialize variables
        players = rand() % (MAX_PLAYERS - 2) + 2;
        seed = rand();
        coinBonus = 0;
        handPos = rand() % 4;
        player = i % (players);

        initializeGame(players, k, seed, &game); //initialize game

        // Initiate valid state variables
        game.deckCount[player] = rand() % MAX_DECK;   //Pick random deck size out of MAX DECK size
        game.discardCount[player] = rand() % MAX_DECK;
        game.handCount[player] = rand() % MAX_HAND;
       
	//grab hand count numbers before calling the card
	int handCount1 = numHandCards(&game);
 
	//check if cardEffect is working properly
        if(cardEffect(smithy, choice1, choice2, choice3, &game, 0, 0) == 0){

	//grab hand count after calling card
	int handCount2 = numHandCards(&game); 

		//check to see if hand count changed properly
		if(handCount2 != (handCount1 + 3 - 1)) {
			printf("Error: Incorrect number of cards drawn\n"); 	
			printf("Hand count before: %d. Hand count after %d.\n", handCount1, handCount2 ); 
			test_failed++; 
			test_status= 0; //set test state to failed
		}
		
	}
	// if card effect failed, print error
	else {
		printf("Error: card could not be properly played\n"); 
		test_status = 0; //set test state to failed
		test_failed++; 
	}

	if(test_status == 0){
                printf("Iteration %d: test failed\n", i);
        }
        else {
                printf("Iteration %d: test passed \n", i);
        }
	


    }	
    if(test_failed > 0){
	printf("Smithy card failed %d random tests\n", test_failed);	
    }		
    else {
	printf("Smithy card passed all random tests\n"); 
    }	

    return 0;
}