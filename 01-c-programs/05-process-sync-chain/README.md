# Process Sync Chain (Precedence Graph via Semaphores)

## What it does
Describes 7 processes (`P1`...`P7`), each printing its own name (`S1`...`S7`), synchronized by 7 semaphores (`s1`...`s7`) so they respect a **precedence graph**:
- `P1` runs first (`s1` starts at 1), then unlocks `P2` and `P3`.
- `P2` unlocks `P4` and `P5`.
- `P3` unlocks `P5` and `P6`.
- `P5` needs **two** signals (`wait(s5)` twice) before running — it depends on both `P2` and `P3`.
- `P4` and `P6` each unlock `P7`.
- `P7` needs **three** signals (`wait(s7)` three times) — it depends on `P4`, `P5`, and `P6` — then loops back and unlocks `P1` again, restarting the cycle.

This is effectively a repeating task graph: `P1 → {P2, P3} → {P4, P5(needs both), P6} → P7(needs all three) → P1 → ...`

## ⚠️ Note — this is pseudocode, not compilable C
As originally written, this uses generic `init`, `wait`, `signal`, `destroy` calls with no `#include`s, no `main()`, and no real semaphore type (`sem_t`) — this is the standard textbook notation for semaphores, not real POSIX C. It is kept exactly as submitted.

To turn it into real, compilable code you would need to:
1. Add `#include <semaphore.h>`, `#include <pthread.h>`, `#include <stdio.h>`.
2. Declare `sem_t s1, s2, ..., s7;` and replace `init(sX, v)` with `sem_init(&sX, 0, v)`.
3. Replace `wait(sX)` / `signal(sX)` with `sem_wait(&sX)` / `sem_post(&sX)`.
4. Replace `destroy(sX)` with `sem_destroy(&sX)`.
5. Add a `main()` that spawns one `pthread_create` per process function and joins them (or destroys semaphores only after joining, e.g. via a signal handler, since the loops never terminate on their own).
