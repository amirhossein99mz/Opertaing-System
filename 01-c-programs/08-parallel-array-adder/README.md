# Parallel Array Adder (Recursive Doubling Sum)

## What it does
Intends to sum an array of `N` numbers in parallel using a **recursive-doubling / reduction-tree** approach: pairs of elements `(i, i+k)` are added together with `k` halving each round, until the whole array collapses into `vet[0]`. Semaphores would coordinate which thread should wait for its partner to finish a round before proceeding.

## Usage
```bash
gcc parallel_array_adder.c -o parallel_array_adder -lpthread
```

## ⚠️ Known issues (kept as originally written) — this file does not compile as-is
Preserved exactly as submitted. To make it build and run correctly you would need to fix:
1. `sum_wait` → should be `sem_wait`.
2. `k` and `n` are used in `adder()` but never declared/initialized (should be derived from the thread's `i` and passed-in `N`).
3. `sem`, `tid` arrays used in `array_sum()` are never declared (only `pthread_t th[N/2]` is declared, but `tid` is used instead of `th`).
4. `sem_destory` → should be `sem_destroy`.
5. Each thread is created with `&i` where `i` is the **loop variable**, which changes before the thread reads it — classic race condition; each thread needs its own private copy of the index (e.g. an `id[]` array, as done in the matrix examples).
6. `array_sum()` never returns the final result to the caller.
