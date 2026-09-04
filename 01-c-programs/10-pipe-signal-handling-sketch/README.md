# Pipe + Signal Handling Sketch

## What it does (intended)
This file appears to combine **two separate exercise drafts** copy-pasted into one:
1. A signal-handling program where two child processes periodically send `SIGUSR1`/`SIGUSR2` to the parent, and the parent stops both children once it receives the **same signal twice in a row**.
2. A basic pipe program where a parent reads a string from the keyboard and writes it to a child through a pipe, and the child reads and prints it.

## ⚠️ Known issues (kept as originally written) — this file does not compile as-is
This is a rough sketch/draft, not a finished program. Notably:
1. **Two `main()` functions** exist in the same file — a C program can only have one `main()`. These need to be split into two separate programs (see `34-pipe-basics` for a cleaned-up, working version of the pipe part, and `40-signal-handling-two-children` for a separate attempt at the signal part).
2. `signal(SIGUSR1, signal_handler())` **calls** `signal_handler()` immediately (note the parentheses) instead of passing the function pointer `signal_handler` — this is a very common mistake; it should be `signal(SIGUSR1, signal_handler)`.
3. Missing `#include <signal.h>` for `signal()`, `kill()`, `SIGUSR1/2`, and `#include <sys/wait.h>`/`#include <unistd.h>` particulars used across the file (`unistd.h` is included, but `signal.h` is not).
4. `pid1` and `pid2` are declared **inside** the `if(!fork())` blocks (local to those blocks), but are referenced later inside the `while(1){ pause(); ... }` loop where they're out of scope — they need to be declared once at the top of `main()`, as in `40-signal-handling-two-children`.
5. Missing semicolons after both `sprintf(...)` calls.
6. In the second `main()`: `N` (buffer size) is used but never defined (no `#define N ...`), and there's a stray unmatched `{`/missing `}` around the `if(fork())/else` block making the braces unbalanced.
7. This file is kept as an illustrative "draft/sketch" for reference — treat `34-pipe-basics`, `35-pipe-word-case-swap`, `37-circular-pipe-3-processes`, and `40-signal-handling-two-children` as the working reference implementations for these two topics.
