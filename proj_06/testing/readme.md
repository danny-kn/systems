# Signal Handling and Counting

In this exercise, I implement a robust signal handling system in C that manages and counts UNIX signals. The program uses POSIX-compliant signal handling mechanisms with `sigaction()` to safely count `SIGINT` signals while allowing graceful termination through `SIGQUIT`.

## Implementation Details

- __Signal Handlers & Synchronization:__
  - `sigint_handler`: Safely handles `SIGINT` signals (typically triggered by `ctrl + c`) by incrementing an atomic counter.
  - `sigquit_handler`: Handles `SIGQUIT` signals (typically triggered by `ctrl + \`) to initiate graceful program termination.
  - Uses `volatile sig_atomic_t` variables for thread-safe signal counting and flag management.

- __Key Components:__
  - __Signal Flags:__ Thread-safe flags using `volatile sig_atomic_t` to coordinate between signal handlers and the main program.
  - __Signal Counter:__ An atomic counter tracking the number of `SIGINT` signals received.
  - __Signal Registration:__ Uses `sigaction()` with `SA_RESTART` flag for reliable signal handling.

- __Key Functions:__
  - `setup_signal_handlers()`: Initializes signal handlers with comprehensive error checking.
  - `config_sigaction()`: Helper function that safely configures signal actions using `sigaction()`.

## Usage

Compile and run the program:
```bash
make clean
make -r
./signal_handling
```

__Program Behavior:__
- Press `ctrl + c` (`SIGINT`) to increment and display the signal counter.
- Press `ctrl + \` (`SIGQUIT`) to display the final count and terminate the program.

__Example Session:__
```bash
./signal_handling
^CSIGINT: ct = 1
^CSIGINT: ct = 2
^CSIGINT: ct = 3
^\SIGQUIT: ct = 3
```

## References

You may refer to the documentation for `sigaction()` and `pause()` system calls using the `man 2 sigaction` and `man 2 pause` commands, respectively.
