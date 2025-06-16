/* Author: Danny Kan */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

/* note: used valgrind to identify and manage memory leakage for this assignment. */
/* please refer to "valgrind-out.txt" for more information. */
Stack *newStack2() { /* constructor code -> returns Stack2. */
    Stack2 *stack_2 = malloc(sizeof(Stack2));
    Stack *stack = malloc(sizeof(Stack));
    if(stack_2 == NULL) {
        printf("error: malloc failed - cannot allocate memory.\n");
        exit(EXIT_FAILURE);
    } else {
        (*stack_2).length = 0;
        (*stack_2).arrSize = MIN_SIZE;
        /* alternatively, (*stack_2).entries = malloc(MIN_SIZE * sizeof(int)); */
        /* preferably use calloc to initialize each element to 0 instead of "garbage" values. */
        (*stack_2).entries = calloc(MIN_SIZE, sizeof(int));
        if((*stack_2).entries == NULL) {
            printf("error: calloc failed - cannot allocate memory.\n");
            exit(EXIT_FAILURE);
        }
    }
    if(stack == NULL) {
        printf("error: malloc failed - cannot allocate memory.\n");
        exit(EXIT_FAILURE);
    } else {
        (*stack).vars = stack_2;
        (*stack).push = pushStack2;
        (*stack).pop = popStack2;
        (*stack).length = lengthStack2;
        (*stack).del = delStack2;
    }
    return stack;
}

void delStack2(Stack *stack) { /* destructor code. */
    Stack2 *stack_2 = (*stack).vars;
    /* free block(s) of allocated memory. */
    free((*stack_2).entries);
    free(stack_2);
    free(stack);
}

/* source: https://www.geeksforgeeks.org/dynamically-growing-array-in-c/ */
/* section 16.4: dynamic tables in CLRS -> */
/* source: https://dl.ebooksworld.ir/books/Introduction.to.Algorithms.4th.Leiserson.Stein.Rivest.Cormen.MIT.Press.9780262046305.EBooksWorld.ir.pdf */
/* this func. pushes a node to the stack. */
void pushStack2(Stack *stack, int val) {
    Stack2 *stack_2 = (*stack).vars;
    (*stack_2).entries[(*stack_2).length] = val;
    (*stack_2).length += 1;
    if((*stack_2).length == (*stack_2).arrSize) {
        int *temp;
        (*stack_2).arrSize *= 2; /* double the size of the table. */
        temp = realloc((*stack_2).entries, (*stack_2).arrSize * sizeof(int));
        if(temp == NULL) {
            printf("error: realloc failed - cannot allocate memory.\n");
            exit(EXIT_FAILURE);
        }
        (*stack_2).entries = temp;
    }
}

/* source: https://www.geeksforgeeks.org/dynamically-growing-array-in-c/ */
/* section 16.4: dynamic tables in CLRS -> */
/* source: https://dl.ebooksworld.ir/books/Introduction.to.Algorithms.4th.Leiserson.Stein.Rivest.Cormen.MIT.Press.9780262046305.EBooksWorld.ir.pdf */
/* this func. pops a node from the stack. */
int popStack2(Stack *stack) {
    Stack2 *stack_2 = (*stack).vars;
    if((*stack_2).length == 0) {
        printf("error: attempting to pop from an empty stack.\n");
        return DEFAULT_RESULT;
    } else {
        int data_val = (*stack_2).entries[(*stack_2).length - 1];
        (*stack_2).length -= 1;
        if((*stack_2).length == (*stack_2).arrSize / 4) {
            int *temp;
            (*stack_2).arrSize /= 2; /* halve the size of the table. */
            temp = realloc((*stack_2).entries, (*stack_2).arrSize * sizeof(int));
            if(temp == NULL) {
                printf("error: realloc failed - cannot allocate memory.\n");
                exit(EXIT_FAILURE);
            }
            (*stack_2).entries = temp;
        }
        return data_val;
    }
}

/* this func. returns the size of the stack. */
int lengthStack2(Stack *stack) {
    Stack2 *stack_2 = (*stack).vars;
    return (*stack_2).length;
}
