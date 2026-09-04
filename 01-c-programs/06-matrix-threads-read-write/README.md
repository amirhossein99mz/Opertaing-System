# Matrix Threads Read/Write

## What it does
Reads and later prints a `10x10` matrix using **one thread per row**. A chain of `R-1` semaphores forces the threads to proceed **in row order** (thread `i` waits for thread `i-1` to finish before it can run), so even though multiple threads exist, rows are actually read/printed strictly sequentially — this guarantees the input/output order matches row order despite using threads.

The same pattern is run twice: once with `readd` (populate the matrix via `scanf`) and once with `writee` (print it via `printf`), each with its own fresh set of semaphores.

## Usage
```bash
gcc matrix_threads.c -o matrix_threads -lpthread
./matrix_threads
# then type 100 integers (10x10), separated by whitespace/newlines
```

## Notes
- `sem[R-1]` semaphores act as a "baton" passed from thread `i-1` to thread `i`.
- Semaphores are destroyed and re-initialized between the read phase and the write phase — correct, since a used (non-zero) semaphore can't simply be reused.
- Thread `i`'s row-read/print order is enforced, but `pthread_create` calls themselves still happen in a simple `for` loop, so total wall-clock benefit over a single-threaded loop is minimal here — the exercise is about *demonstrating* semaphore-based thread ordering, not about performance.
