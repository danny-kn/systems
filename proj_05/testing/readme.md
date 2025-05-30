# Producer-Consumer (Bounded-Buffer) Problem

In this exercise, I implement a solution to a classic bounded-buffer problem using producer and consumer threads. The solution uses standard counting semaphores and a binary mutual exclusion (i.e., mutex) lock to synchronize access to a shared circular buffer, following the algorithms outlined in _Operating System Concepts (8th Edition) by Silberschatz, Galvin, and Gagne_.

## Implementation Details

- __Central Buffer:__ A fixed-size circular buffer of type `buf_item` (defined as `int`) with a capacity of 5 elements. The buffer is implemented as a circular queue using modular arithmetic for efficient wraparound.

- __Synchronization Primitives:__
  - `num_full`: Tracks the number of filled slots in the buffer (initialized to 0).
  - `num_empty`: Tracks the number of empty slots in the buffer (initialized to `BUF_SIZE`).
  - `mutex`: Protects the critical section during buffer manipulation.

- __Thread Management:__
  - __Producer Threads:__ Generates random integers and inserts them into the buffer using `insert_item()`.
  - __Consumer Threads:__ Removes items from the buffer in first-in-first-out (i.e., FIFO) order using `remove_item()`.
  - __Thread Creation:__ A custom `thread_create()` function with comprehensive error handling.

- __Key Functions:__
  - `insert_item(buf_item item)`: Synchronizes producer access to buffer insertion.
  - `remove_item(buf_item *item)`: Synchronizes consumer access to buffer removal.

## Usage

Run the program with three command-line arguments:
```bash
./bounded_buf <sleep_time> <num_pthreads> <num_cthreads>
```

__Parameters:__
- `sleep_time`: Duration (in seconds) for the program to execute before terminating.
- `num_pthreads`: Number of producer threads to create.
- `num_cthreads`: Number of consumer threads to create.

__Example:__
```bash
./bounded_buf 6 3 2
```

This runs the program for 6 seconds with 3 producer threads and 2 consumer threads.

## References

_Operating System Concepts (8th Edition) by Silberschatz, Galvin, and Gagne_.
