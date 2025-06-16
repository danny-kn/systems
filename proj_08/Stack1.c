/* Author: Danny Kan */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

/* note: used valgrind to identify and manage memory leakage for this assignment. */
/* please refer to "valgrind-out.txt" for more information. */
Stack *newStack1() { /* constructor code -> returns Stack1. */
    Stack1 *stack_1 = malloc(sizeof(Stack1));
    Stack *stack = malloc(sizeof(Stack));
    if(stack_1 == NULL) {
        printf("error: malloc failed - cannot allocate memory.\n");
        exit(EXIT_FAILURE);
    } else {
        (*stack_1).length = 0;
        (*stack_1).firstNode = NULL;
        (*stack_1).lastNode = NULL;
    }
    if(stack == NULL) {
        printf("error: malloc failed - cannot allocate memory.\n");
        exit(EXIT_FAILURE);
    } else {
        (*stack).vars = stack_1;
        (*stack).push = pushStack1;
        (*stack).pop = popStack1;
        (*stack).length = lengthStack1;
        (*stack).del = delStack1;
    }
    return stack;
}

void delStack1(Stack *stack) { /* destructor code. */
    Stack1 *stack_1 = (*stack).vars;
    LLNode *traverse_ptr = (*stack_1).firstNode;
    while(traverse_ptr != NULL) {
        LLNode *next_node = (*traverse_ptr).next;
        free(traverse_ptr);
        traverse_ptr = next_node;
    }
    /* free block(s) of allocated memory. */
    free(stack_1);
    free(stack);
}

/* this func. pushes a node to the stack. */
void pushStack1(Stack *stack, int val) {
    Stack1 *stack_1 = (*stack).vars;
    LLNode *new_node = malloc(sizeof(LLNode));
    if(new_node == NULL) {
        printf("error: malloc failed - cannot allocate memory.\n");
        exit(EXIT_FAILURE);
    } else {
        (*new_node).data = val;
        (*new_node).next = (*stack_1).firstNode;
        (*stack_1).firstNode = new_node;
        /* if the stack is empty (i.e., if pushing a node to the empty stack). */
        if((*stack_1).length == 0)
            (*stack_1).lastNode = new_node;
        (*stack_1).length += 1;
    }
}

/* this func. pops a node from the stack. */
int popStack1(Stack *stack) {
    Stack1 *stack_1 = (*stack).vars;
    if((*stack_1).length == 0) {
        printf("error: attempting to pop from an empty stack.\n");
        return DEFAULT_RESULT;
    } else {
        LLNode *node = (*stack_1).firstNode;
        int val = (*node).data;
        (*stack_1).firstNode = (*node).next;
        /* free block(s) of allocated memory. */
        free(node);
        (*stack_1).length -= 1;
        if((*stack_1).length == 0)
            (*stack_1).lastNode = NULL;
        return val;
    }
}

/* this func. returns the size of the stack. */
int lengthStack1(Stack *stack) {
    Stack1 *stack_1 = (*stack).vars;
    return (*stack_1).length;
}
