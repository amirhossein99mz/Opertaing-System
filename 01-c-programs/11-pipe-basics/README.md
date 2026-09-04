# Pipe Basics

## Background (from the original notes)
A pipe is a communication channel between two processes. It is usually **half-duplex** (one direction): one side (parent) writes, the other side (child) reads. For full-duplex (two-way) communication, two pipes are needed. A pipe has 2 file descriptors: `fd[0]` for reading (usually the child) and `fd[1]` for writing (usually the parent).
- `close(fd[0])`: close the read end when a process only writes.
- `close(fd[1])`: close the write end when a process only reads.
- Full pipe + write → write **blocks**. Empty pipe + read → read **blocks**.
- No reader + write → `SIGPIPE`. No writer + read → `EOF`.

## What it does
Creates a pipe, forks once. The **parent** repeatedly reads a word from the keyboard (`scanf`) and writes it into the pipe. The **child** repeatedly reads from the pipe and prints what it receives.

## Usage
```bash
gcc pipe_basics.c -o pipe_basics
./pipe_basics
# type words; each one is sent from parent to child through the pipe and printed back out
```

## Notes
- This is a clean, working baseline example — correctly closes the unused end of the pipe in each process.
- Uses `strlen(line) + 1` when writing, to include the string's null terminator.
