# Systems Programming Projects

This repository contains a collection of systems programming projects implemented in C, covering fundamental concepts in operating systems, concurrent programming, and system-level programming.

## Projects Overview

### proj_01 - Process Creation
Basic C program demonstrating process creation using the `fork()` system call. The child process retrieves and displays its process ID using `getpid()`.

### proj_02 - Simple UNIX Shell Interface
Implementation of a basic UNIX shell interface that can execute system commands and handle user input through a command-line interface.

### proj_03 - Concurrent Threads
Multi-threaded program using `pthread_create()` to create two concurrent child threads that increment a shared global variable, demonstrating basic thread synchronization concepts.

### proj_04 - File Processing and Data Structures
Implementation of file processing operations with focus on data structure manipulation and file I/O operations in C.

### proj_05 - Producer-Consumer (Bounded-Buffer) Problem
Solution to the classic bounded-buffer problem using producer and consumer threads. Implements synchronization using semaphores and mutex locks with a circular buffer of 5 elements.

### proj_06 - Signal Handling and Counting
Robust signal handling system that manages and counts UNIX signals using POSIX-compliant mechanisms. Handles `SIGINT` for counting and `SIGQUIT` for graceful termination.

### proj_07 - Encryption/Decryption System
Complete encryption and decryption scheme that processes characters in batches of 8, using bit manipulation techniques. Includes comprehensive testing with multiple input scenarios.

### proj_08 - Stack Implementation and Performance Analysis
Two different stack implementations: one using singly-linked lists (Stack1) and another using dynamic table resizing (Stack2). Includes performance analysis, timing tests, and profiling with gprof.

### proj_09 - Shell with Command History
Advanced shell program with command history functionality. Features persistent history storage, signal handling for history display, and command re-execution capabilities.
