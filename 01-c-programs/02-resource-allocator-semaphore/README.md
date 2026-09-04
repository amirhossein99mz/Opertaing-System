# Resource Allocator (Semaphores)

## What it does
Implements a classic **bounded resource pool** of `M = 10` slots using two POSIX semaphores:
- `empty` — counts how many resources are currently free (initialized to `M`).
- `mutex` — a binary semaphore protecting the shared `resources[]` array from concurrent access.

Two operations are provided:
- `request()` — blocks until a resource is free, marks it as used, and returns its index.
- `release(i)` — marks resource `i` as free again and wakes up one waiting thread (if any).

## Usage
```bash
gcc resource_allocator.c -o resource_allocator -lpthread
./resource_allocator
```
`main()` only initializes the semaphores; to see it in action, spawn threads that call `request()` and `release()`.

## Notes
- Correct producer/consumer-style pattern: `empty` limits concurrency to `M`, `mutex` ensures mutual exclusion on the array scan/update.
- Semaphores are never destroyed with `sem_destroy()` — should be added before program exit for cleanliness.
- `request()` assumes a free slot is always found once `empty` is decremented — this holds as long as `resources[]` is only modified through `request`/`release`.
