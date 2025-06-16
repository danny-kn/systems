# Shell with Command History

In this exercise, I implement a custom shell program that maintains a command history with signal handling capabilities. The shell supports command execution, history display, and re-execution of previous commands using POSIX-compliant signal handling mechanisms.

## Implementation Details

- __Command History System:__
  - Maintains a circular buffer of the 10 most recent commands using a fixed-size array.
  - Implements persistent history storage using the `mysh.history` file in the current working directory.
  - Automatically loads previous session history on startup and saves history on exit.

- __Signal Handling:__
  - `SIGINT` handler: Displays the command history when triggered by `ctrl + c`.
  - Uses `sigaction()` with `SA_RESTART` flag for reliable signal handling.
  - Signal handler safely accesses history data without race conditions.

- __Command Features:__
  - __Standard Command Execution:__ Executes commands using the `system()` call.
  - __History Re-execution:__ Type `r` to re-execute the most recent command.
  - __Character-based Search:__ Type `r <char>` to re-execute the most recent command starting with the specified character.
  - __Graceful Exit:__ Type `exit` to terminate the shell and save history.

- __Key Functions:__
  - `save_hist()`: Stores commands in the circular history buffer.
  - `disp_hist()`: Signal handler that displays the command history.
  - `search_cmd()`: Searches for commands starting with a specific character.
  - `save_hist_to_fname()` / `load_hist_from_fname()`: Handles persistent history storage.

## Usage

Compile and run the shell:
```bash
gcc -o main main.c
./main
```

__Shell Commands:__
- Enter any valid system command to execute it.
- Press `ctrl + c` to display the command history.
- Type `r` to re-execute the most recent command.
- Type `r <char>` to re-execute the most recent command starting with `<char>`.
- Type `exit` to terminate the shell.

__Example Session:__
```bash
./main
COMMAND->ls -la
COMMAND->pwd
COMMAND->whoami
COMMAND->^C
1 ls -la
2 pwd
3 whoami
COMMAND->r p
pwd
COMMAND->exit
```

## References

You may refer to the documentation for `sigaction()` and `system()` system calls using the `man 2 sigaction` and `man 3 system` commands, respectively.