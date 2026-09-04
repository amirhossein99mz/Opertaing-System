# Pipe Word Case Swap

## What it does
Parent process (`P1`) repeatedly reads words from the keyboard and sends each one, character by character plus a null terminator, through a pipe — stopping after sending the literal word `"STOP"`. The child process (`P2`) reads characters from the pipe, reconstructs each word, and **swaps the case of every letter** (uppercase becomes lowercase and vice versa) before printing it, stopping when it receives `"STOP"`.

## Usage
```bash
gcc pipe_word_case_swap.c -o pipe_word_case_swap
./pipe_word_case_swap
# type words, e.g. "Hello" -> prints "hELLO"; type STOP to end
```

## Notes
- Correct, working implementation: closes the unused pipe end in each process, reconstructs words from a byte stream using `'\0'` as the delimiter, and uses `isalpha`/`islower`/`toupper`/`tolower` for the case swap.
- The parent additionally calls `wait(NULL)` to reap the child before exiting.
