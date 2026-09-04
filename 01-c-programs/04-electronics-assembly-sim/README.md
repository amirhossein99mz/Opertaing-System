# Electronics Assembly Sim (Producer-Consumer)

## What it does
Models a classic 3-producer/1-consumer synchronization problem with semaphores:
- `Electronics` thread produces **2 electronic cards per cycle** (waits twice on `empty_cards`, posts twice on `full_cards`).
- `Mechancis` (Mechanics) thread produces **1 chassis per cycle**.
- `Assembly` thread should consume **2 cards + 1 chassis** to assemble one final product, then release the corresponding "empty" slots back.

## Usage
```bash
gcc electronics_assembly.c -o electronics_assembly -lpthread
```

## ⚠️ Known issues (kept as originally written)
This file is **not compilable as-is** — preserved exactly as submitted for the exam. To make it build, you'd need to fix:
1. Missing `#include <semaphore.h>`.
2. `Assembly()` has bare `sem_wait` / `sem_post` statements with no semaphore argument or parentheses — needs e.g. `sem_wait(&full_cards); sem_wait(&full_cards); sem_wait(&full_chasis);` and matching `sem_post(&empty_cards)` (×2) + `sem_post(&empty_chasis)`.
3. `MAX_CHASIS` is used in `sem_init` but the macro is defined as `MAX_CHASSIS` — typo mismatch.
4. `phtead_t` should be `pthread_t`.
5. `sem_init(&full_cards, 0, 0)` is called **twice** instead of initializing `full_chasis` once.
6. `main()` destroys the semaphores and returns immediately without ever joining the threads — the program would exit before the threads do meaningful work.
