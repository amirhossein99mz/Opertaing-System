# Circular Pipe — 3 Processes

## Task description (from the original notes)
Create 3 processes P1, P2, P3 connected in a circle using 3 pipes:
```
P1 ──p12──> P2 ──p23──> P3 ──p31──> P1
```
Each process: gets an integer, sleeps that many seconds, reads a new integer from the keyboard, sends it to the next process, and repeats forever. P1 must start first.

## What it does
Creates three pipes (`p12`, `p23`, `p31`), then forks twice to create P1, P2, and P3. Each process closes the pipe ends it doesn't need and enters a loop: wait for a number from its predecessor (P1 starts with `n = 0` and no wait), sleep that many seconds, prompt the user for a new number, and forward it to its successor.

## Usage
```bash
gcc circular_pipe_3_processes.c -o circular_pipe_3_processes
./circular_pipe_3_processes
# each process will prompt in turn; type an integer when asked
```

## Notes
- Working implementation: correctly closes every unused pipe end in every branch (this is the trickiest part of multi-pipe process topologies) so each process only has the read/write descriptors it actually needs.
- P1 is special-cased: it doesn't read from `p31` before its first iteration, matching the "P1 must start first" requirement.
