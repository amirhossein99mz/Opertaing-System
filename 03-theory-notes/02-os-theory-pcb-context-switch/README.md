# PCB, Context Switching & Process States — Theory Notes

This folder contains theory notes only (no source code), kept from the original exam material.

## PCB (Process Control Block)
A table/data structure used by the OS to store information about a process. It contains: program counter, memory limits, opened files, registers, process state, and PID.

## Context switching
Context switching means the OS stops one running process and starts another:
- The OS **saves** the PCB of the process that is being paused (e.g. P1).
- The OS **loads** the PCB of the process that is going to run next (e.g. P2).
- Later, to switch back, the same happens in reverse: save P2's PCB, load P1's PCB.

## Process state diagram
The basic process states are: **New → Ready → Running → Terminated**, with a **Waiting** state a running process can move into (and back to Ready) while it's blocked on I/O or another event.

## Orphan process
The parent process terminates while the child is still running. The child is then inherited/adopted by the OS/init system.

## Zombie process
The child process terminates, but the parent does **not** call `wait()` on it. The child's entry remains in the process table as a "zombie" until the parent eventually waits on it (or the parent itself terminates).

## Realizable vs non-realizable graph
A **realizable graph** is one where a parent can only wait for its **direct** children (not grandchildren or arbitrary descendants) — this constraint on `wait()`/`waitpid()` semantics is what makes a process-waiting graph "realizable" using standard fork/wait primitives. A graph requiring a process to wait on a non-direct descendant is **non-realizable** without extra IPC.
