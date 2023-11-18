 /* COPYRIGHT (C) HARRY CLARK */

/* LEETCODE PROBLEMS AND SOLUTIONS */

/* THE FOLLOWING FILE PERTAINS TOWARDS THE PROBLEM OF TWO SUM */
/* GIVEN AN ARBITARY ARRAY, RETURN THE INDICES OF THE TWO NUMBERS IN THE ARRAY */
/* SUCH THAT THEY ADD UP TO THE TARGET */

/* NESTED INCLUDES */

#include <stdio.h>
#include <stdlib.h>

typedef struct NUMBER
{
    int* NUMS;
    int NUM_SIZE;
    int* TARGET;
    int* RETURN;
    int* RESULT;

} NUMBER;

static NUMBER *NUM;

/* MALLOC THE CORRESPONDENCE TO CREATE A STORE OF EACH ELEMENT IN THE ARRAY */

int* TWO_SUM(int *TARGET, int *RETURN)
{
    /* ASSUMING THE ARBITARY VALUE, SEE IF THE SIZE OF THE RESULT */
    /* MATCHES BASED ON THE ELEMENTS */

    for (int i = 0; i < NUM->NUM_SIZE; i++)
    {
        int* NUM_STORE = (int *)malloc(NUM->NUM_SIZE * sizeof(int));
        int CORRESPONDENCE = *TARGET - NUM->NUMS[i];

        if (NUM_STORE[CORRESPONDENCE] != 0)
        {
            NUM->RESULT = (int*)malloc(2 * sizeof(int));
            NUM->RESULT[0] = NUM_STORE[CORRESPONDENCE] - 1;
            NUM->RESULT[1] = i;
            NUM->RETURN += 2;
            return NUM->RESULT;
        }

        NUM_STORE[NUM->NUMS[i]] = i;
    }

    return NULL;
}

/* THIS WILL CREATE A MOCK ARRAY ASSOCIATED WITH THE QUESTION */
/* FROM THE TWO ELEMENTS IN THE ARRAY, THEY NEED TO ADD UP TO THE TARGET */

/* THIS IS THROUGH DETERMINING THE ALLOCATED SIZE OF THE ARRAY IN RELATION */
/* TO IT'S ORDERED PAIRS */

int main(int argc, char *argv[])
{
    int NUMBER_LIST[] = {2, 7, 11, 15};
    int TARGET = 9;

    NUM = (NUMBER*) malloc(sizeof(NUMBER));
    NUM->NUMS = NUMBER_LIST;
    NUM->NUM_SIZE = sizeof(NUMBER_LIST) / sizeof(NUMBER_LIST[0]);
    NUM->TARGET = &TARGET;
    NUM->RETURN = (int*)malloc(sizeof(int));

    NUM->RESULT = TWO_SUM(NUM->NUMS, NUM->RETURN);

    if (NUM->RESULT != NULL)
    {
        printf("[%d, %d]\n", NUM->RESULT[0], NUM->RESULT[1]);
        free(NUM->RESULT);
    }
    else
    {
        printf("No valid elements add up to equal the target.\n");
    }

    free(NUM->RETURN);
    free(NUM);

    return 0;
}