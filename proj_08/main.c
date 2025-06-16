/* Author: Danny Kan */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab4.h"

void StackTest(int type) {
    Stack *newStack = type == 1 ? newStack1() : newStack2();
    int i, removed, errors;
    clock_t start, end;
    double cpu_time_used;
    errors = 0;
    start = clock();
    for(i = 0; i < NUM_ENTRIES; i++) {
        newStack -> push(newStack, i);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The time taken to push to Stack%d is %f seconds.\n", type, cpu_time_used);
    start = clock();
    for(i = 0; i < NUM_ENTRIES; i++) {
        removed = newStack -> pop(newStack);
        if(removed != NUM_ENTRIES - i - 1) {
            printf("Expected %i, removed %i.\n", NUM_ENTRIES - i - 1, removed);
            errors++;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The time taken to pop from Stack%d is %f seconds.\n", type, cpu_time_used);
    newStack -> del(newStack);
    printf("Ended with %i errors.\n", errors);
}

void QueueTest(int type) {
    /* TODO: something goes here... */
}

int main(int argc, char *argv[]) {
    /* source: https://www.gnu.org/software/libc/manual/html_node/CPU-Time.html */
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    StackTest(1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    /* testing the Stack1 implementation. */
    printf("\tThe time taken for Stack1 is %f seconds.\n", cpu_time_used);
    start = clock();
    StackTest(2);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    /* testing the Stack2 implementation. */
    printf("\tThe time taken for Stack2 is %f seconds.\n", cpu_time_used);
    return EXIT_SUCCESS;
}
