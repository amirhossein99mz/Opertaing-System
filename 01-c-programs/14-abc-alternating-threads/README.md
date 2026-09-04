# ABC Alternating Threads

## What it does (intended)
Three threads `TA`, `TB`, `TC` are meant to coordinate via semaphores so that the printed output alternates predictably — the comment states the output must be `ABC` or `CBA`. `TA` and `TC` compete for `s1`; whichever runs first prints its letter, wakes `TB` (via `s2`), waits for `TB`'s acknowledgment (`s3`), then lets the other of `TA`/`TC` go next.

## Usage
```bash
gcc abc_alternating_threads.c -o abc_alternating_threads -lpthread
```

## ⚠️ Known issues (kept as originally written) — this file does not compile/run correctly as-is
1. `sem_inti(&s1,0,1)` — typo, should be `sem_init(&s1,0,1)`.
2. `TB` has **no loop** (`while(1)`) around its body, so it only ever prints `"B"` once and then the thread exits — it can't respond to more than one signal from `s2` over the program's lifetime.
3. No `main()` is included in this file — nothing calls `init()`, creates the `TA`/`TB`/`TC` threads, or joins them. A working version needs a `main()` with `pthread_create`/`pthread_join` calls for all three functions plus a call to `init()` beforehand.
4. Missing `#include <pthread.h>` for `pthread_create`/`pthread_t`, needed once `main()` is added.
