# Matrix Semaphore Thread I/O

## Task description (from the original notes)
> By using threads and semaphores, write a C program that reads numbers of an `R x C` matrix from the keyboard and writes them back out. Thread 0 reads row 0, thread 1 reads row 1, ..., thread n reads row n. The bridge between each pair of threads is a semaphore (a shared counter used to prevent a critical section overlap).

## What it does
Same "chained semaphore" pattern as `13-matrix-threads-read-write`: one thread per row, with `sem[R-1]` semaphores forcing row `i` to wait for row `i-1` before reading/printing, guaranteeing rows are processed in order despite being handled by separate threads.

## Usage
```bash
gcc matrix_semaphore_thread_io.c -o matrix_semaphore_thread_io -lpthread
```

## ⚠️ Known issues (kept as originally written) — this file does not compile as-is
1. `int i=*(*int)arg;` — invalid cast syntax; should be `int i = *(int *)arg;` (the `*` and `int` are swapped/misplaced).
2. **Both** the read function and the write function are named `read_row` — a duplicate function definition, which won't compile. The second one (meant to print the matrix) should be renamed to `write_row`.
3. `main()` calls `write_row` in the second phase, but (once the duplicate above is fixed and renamed) that function must actually exist with that name and use `printf` instead of `scanf`, matching the pattern in `13-matrix-threads-read-write`.
4. No `sem_t` array bound check issue, but as with the other matrix example, semaphores must be destroyed and freshly re-initialized between the read phase and the write phase (this part is done correctly here).
