# Process vs Thread — Theory Notes

This folder contains theory notes only (no source code), kept from the original exam material.

## Process
A **process** is a running program with its own memory/address space. It is slow but safe: when one process changes its memory, other processes cannot see the change or be affected by it. To share memory between processes, IPC/shared memory must be used explicitly. The kernel manages processes using a **PCB (Process Control Block)**. Processes are heavier than threads, communication between them is harder, and they follow a parent-child hierarchy.

## Thread
A **thread** is a small unit inside a process. A process can contain many threads that share its memory/address space — if one thread changes shared data, all other threads in the same process see the change immediately. Threads are fast and good for parallel work, but not inherently safe: shared memory can lead to race conditions, so synchronization (mutexes, semaphores, etc.) is needed. Threads share global variables, code, heap, and open files, while the program counter, registers, and stack are unique to each thread.

## Three thread models

1. **Kernel-level threads** — managed directly by the OS kernel. The kernel is aware of and schedules the threads individually. If one thread blocks, the others can still run. They allow true parallelism across multiple CPUs. They are slower because thread operations require system calls.

2. **User-level threads** — managed by a user-space library, not directly by the OS kernel. If one thread blocks, all the others may block too (since the kernel only sees one underlying process/thread). They are very fast to create and switch between, but not well-suited for real parallelism. All thread bookkeeping is stored inside the process itself.

3. **Hybrid model** — combines user-level and kernel-level threads, providing a balance between parallelism and speed. This is the model commonly used by modern operating systems.
