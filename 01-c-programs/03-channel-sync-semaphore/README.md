# Channel Sync (Semaphores)

## What it does
Implements up to 10 independent **"channels"**, each acting like a simplified condition variable built from semaphores:
- `wait_ch(x)` — a thread calls this to wait on channel `x`. It registers itself in `n_wait[x]` and blocks on `sync[x]`.
- `signal_ch(x)` — wakes up **all** threads currently waiting on channel `x` (broadcast-style signal), by posting to `sync[x]` once per waiting thread.
- `mutex[x]` protects `n_wait[x]` from concurrent updates.

## Usage
```bash
gcc channel_sync.c -o channel_sync -lpthread
```
This file only defines the primitives; call `wait_ch()`/`signal_ch()` from your own threads to synchronize them on a shared channel index.

## Notes
- `sync` is used both as the semaphore array name and is a reserved-ish identifier — some compilers/headers may warn or conflict; consider renaming to `sync_sem` for portability.
- `main()` initializes all 10 channels but never joins/uses threads or cleans up (`sem_destroy` is missing).
- `signal_ch` reads `n_wait[x]` and then posts `n` times — if a new thread calls `wait_ch` concurrently between the read and the loop, there's a small race; acceptable for coursework but not production-grade.
