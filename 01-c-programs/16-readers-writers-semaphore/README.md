# Readers-Writers (Semaphore-based sketch)

## Background (from the original notes)
Classic readers-writers synchronization: **many readers** may read together concurrently, but **only one writer** may write at a time, and readers and writers cannot access the resource together.

```
             Writer
     Reader1  Reader2  Reader3
             Writer
             .....
```

## What it does (intended)
`writer()` should exclusively lock the resource while writing; `reader()` should allow multiple concurrent readers but still block out any writer while at least one reader is active, tracked via a reader count `nR`.

## ⚠️ Known issues (kept as originally written) — this is not a correct readers-writers solution
1. `sem_init(&meR,0,0)` initializes the "readers" semaphore to **0**, but `meR` is used here as if it were a **mutex** protecting `nR` — a mutex-style semaphore protecting a counter should normally start at **1** (available), not 0. As written, the very first `sem_wait(&meR)` in either `reader()` or `writer()` would block forever since nothing has posted to it yet.
2. `writer()` calls `sem_wait(&meW)` (correctly, to get exclusive access) but posts `sem_post(&meR)` afterwards instead of `sem_post(&meW)` — it should release the semaphore it acquired (`meW`), not the reader-count mutex.
3. `reader()` uses `meR` both as the mutex protecting `nR` **and** conceptually as something writers should also respect — in the classic solution, a **separate mutex** (distinct from any writer-blocking semaphore) is used purely to protect `nR`, while `meW` is the semaphore that actually excludes writers, and is only posted to by the *last* reader leaving (which this code does attempt to do at the end, when `nR` reaches 0).
4. `WRITE()` and `READ()` are placeholder function calls (not defined) — meant to represent "the actual writing/reading work" and would need real implementations.
5. No `main()`, `#include <stdio.h>`/`#include <stdlib.h>`, or thread-creation code is present — this file only sketches the reader/writer critical-section logic.

A corrected version needs: a `mutex` semaphore starting at 1 (protects `nR`), and `meW` starting at 1 (exclusive writer access), with the classic pattern:
```
reader(): wait(mutex); nR++; if(nR==1) wait(meW); post(mutex);
          READ();
          wait(mutex); nR--; if(nR==0) post(meW); post(mutex);
writer(): wait(meW); WRITE(); post(meW);
```
