# Broadcast Rendezvous

## What it does
A classic **generalized rendezvous / broadcast** synchronization pattern using semaphores:
- `br_rec()` — a receiver registers itself (increments `n` under `mutex`), then blocks on `sync` until a value is broadcast.
- `br_send(x)` — a sender sets the shared `value`, then wakes up **every currently-registered receiver** by posting to `sync` once per waiter, and resets the waiter count to 0.

This lets one sender deliver the same value to an arbitrary number of waiting receivers at once (a "broadcast").

## Usage
```bash
gcc broadcast_rendezvous.c -c
```
This file only defines the primitives (no `main`); call `initialization()` once, then use `br_rec()`/`br_send()` from your own threads.

## Notes
- Function prototypes `int br_rec(void)` / `void br_send(int x)` are declared without a trailing semicolon issue in the original — kept as-is (harmless duplicate declaration before the real definitions).
- There's a race if a new receiver calls `br_rec()` (and increments `n`) concurrently while `br_send()` is mid-broadcast — acceptable simplification for coursework.
- `sync` is a reserved-sounding identifier; consider renaming (e.g. `sync_sem`) to avoid clashes on some systems.
