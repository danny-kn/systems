# Concurrent Threads

In this exercise, I implement a simple C program which creates two concurrent child threads from the main thread using the `pthread_create()` function. Each child thread increments a global variable (i.e., `shared_ct`) a specified number of iterations. When both child threads complete their execution, the main thread will output the final value of the global variable to standard output (1).

You may refer to the documentation for the `pthread_create()` and `pthread_join()` functions using the `man pthread_create` and `man pthread_join` commands, respectively.
