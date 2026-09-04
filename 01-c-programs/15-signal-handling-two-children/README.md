# Signal Handling with Two Child Processes

## Context (from the original notes)
The parent process receives signals from two children and stops them after receiving **3 identical signals in a row**.

## What it does (intended)
Forks two child processes: one repeatedly sleeps a random 0-1 seconds then sends `SIGUSR1` to the parent; the other sleeps a random 0-2 seconds then sends `SIGUSR2`. The parent installs a signal handler that tracks the last two received signals; if a third identical signal arrives in a row, it sets a `finish` flag, and the parent's main loop then kills both children and exits.

## Usage
```bash
gcc signal_handling_two_children.c -o signal_handling_two_children
./signal_handling_two_children
```

## ⚠️ Known issues (kept as originally written) — this file does not compile as-is
1. Header typos: `<stding.h>` should be `<stdio.h>` (or is simply a duplicate/typo — `stdio.h` is what's needed), `<sys/type.h>` should be `<sys/types.h>`, `<undistd.h>` should be `<unistd.h>`.
2. `if(sig==last_last_sig ==last_sig)` — chained comparison bug: in C this evaluates as `(sig == last_last_sig) == last_sig`, i.e. it compares a boolean (`0` or `1`) against `last_sig`, which is almost never what's intended. It should check that the **current signal equals both** of the last two remembered signals, e.g. `if (sig == last_sig && sig == last_last_sig)`.
3. There's a stray, invalid line inside the `else` block (`- A : becones A - and enter B : [A B]`) — looks like a leftover comment/note that isn't valid C syntax and needs a `//` prefix or removal entirely.
4. `signal(SIGUSR1, sig_handler())` — same bug as in the pipe/signal sketch: calls `sig_handler()` immediately instead of passing the function pointer; should be `signal(SIGUSR1, sig_handler)`.
5. `if(!pid1())` and `if(!pid2())` — `pid1`/`pid2` are `pid_t` **variables** (holding the return value of `fork()`), not functions; calling them with `()` is invalid. Should simply be `if (!pid1)` / `if (!pid2)`.
6. Missing `#include <stdio.h>` proper spelling (see #1) for `printf`.
