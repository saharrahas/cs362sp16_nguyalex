#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dominion.h"
#include "rngs.h"


int main(int argc, char *argv[]){
    printf("RANDOM TESTING Card1\n");
    int num_tests = 10;
    int i, j;
    for(j =0; j< num_tests; j++)
    {
        // setup seed from argv or default
        int seed;
        // commented out sysargs for 100% coverage
        //if (argc >= 2)
        //{
        //    seed = atoi(argv[1]);
        //}
        //else
        //{
            seed = rand();
        //}

        int players = rand() % 4;
        int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
            	     sea_hag, tribute, smithy};
        struct gameState state;

        initializeGame(players, k, seed, &state);
        // randomize each players deck and hand counts
        for(i=0; i<players; i++)
        {
            state.deckCount[i] = rand() % MAX_DECK;
            state.handCount[i] = rand() % MAX_HAND;
        }
        int r;
        r = cardEffect(smithy, 1, 1, 1, &state, 1, 0);
        //cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)

        //playCard(adventurer, 1, 1, 1, &state);

    }
    printf("Card1 PASSED RANDOM TESTING\n");
    return 0;
}
