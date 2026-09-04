# Operating Systems — Exam Scripts & Programs

A collection of C programs and Bash scripts written for the "Linux / Operating Systems" exam, organized by category. Each program/script lives in its own folder together with a short `README.md` explaining what it does, how to run it, and (where relevant) any bugs kept intentionally as originally written, with an explanation of how to fix them.

## Structure

```
os-scripts/
├── 01-c-programs/       16 C programs (threads, semaphores, pipes, signals)
├── 02-bash-scripts/     25 Bash scripts (text processing, file/process utilities)
└── 03-theory-notes/     3 conceptual notes (no code)
```

## 01. C Programs
| # | Folder | Topic |
|---|--------|-------|
| 01 | record-parser | Low-level file I/O, parsing records |
| 02 | resource-allocator-semaphore | Bounded resource pool with semaphores |
| 03 | channel-sync-semaphore | Condition-variable-style channels |
| 04 | electronics-assembly-sim | Producer-consumer (⚠️ bugs documented) |
| 05 | process-sync-chain | Precedence graph via semaphores (pseudocode) |
| 06 | matrix-threads-read-write | One thread per matrix row, chained semaphores |
| 07 | broadcast-rendezvous | Generalized rendezvous / broadcast |
| 08 | parallel-array-adder | Recursive-doubling sum (⚠️ bugs documented) |
| 09 | matrix-semaphore-thread-io | Matrix I/O with threads (⚠️ bugs documented) |
| 10 | pipe-signal-handling-sketch | Pipe + signal draft (⚠️ does not compile) |
| 11 | pipe-basics | Basic parent→child pipe communication |
| 12 | pipe-word-case-swap | Pipe with per-character case swap |
| 13 | circular-pipe-3-processes | 3 processes in a pipe ring |
| 14 | abc-alternating-threads | Alternating-output threads (⚠️ bugs documented) |
| 15 | signal-handling-two-children | Two children signaling parent (⚠️ bugs documented) |
| 16 | readers-writers-semaphore | Readers-writers sketch (⚠️ bugs documented) |

## 02. Bash Scripts
| # | Folder | Topic |
|---|--------|-------|
| 01 | grep-posix-files | Find `.c` files containing "POSIX" |
| 02 | swap-columns | Swap two columns in a file |
| 03 | longest-word-finder | Longest word in a file |
| 04 | first-word-length-sum | Diagonal word-length sum |
| 05 | path-info-lister | File/dir info via `ls -l` parsing |
| 06 | max-product-pair | Max product pair per line |
| 07 | tab-file-summarizer | Aggregate `.tab` files by product (⚠️ syntax bug) |
| 08 | even-odd-case-toggle | Upper/lowercase by word-count parity |
| 09 | sum-product-two-numbers | Sum & product of two inputs |
| 10 | user-login-count | Count active logins for a user |
| 11 | word-length-counter | Length of one typed word |
| 12 | print-matrix-numbers | Print sequential numbers as a matrix |
| 13 | read-until-zero-reverse-print | Collect numbers, print reversed |
| 14 | longest-word-forloop-version | Longest word (for-loop variant) |
| 15 | diagonal-word-length-sum-v2 | Diagonal word-length sum (variant) |
| 16 | path-info-lister-v2 | File/dir info via test operators |
| 17 | parity-case-toggle-v2 | Upper/lowercase by parity (variant) |
| 18 | kill-high-mem-nonroot-processes | Kill high-memory non-root processes (⚠️ bug) |
| 19 | replace-pad-lines | Replace word + pad lines |
| 20 | rename-replace-printf-word | Rename files, replace a word (⚠️ bugs documented) |
| 21 | remove-user-home-passwd-v1 | Remove user's home + passwd entry (⚠️ heavily buggy draft) |
| 22 | remove-user-home-passwd-v2 | Remove user's home + passwd entry (cleaner) |
| 23 | ifdef-endif-preprocessor | `ifdef`/`endif`-style line filter (⚠️ bugs documented) |
| 24 | background-process-manager | Start/stop background jobs (⚠️ bug) |
| 25 | process-tree-lister | List a process and its children (⚠️ bugs documented) |

## 03. Theory Notes
| # | Folder | Topic |
|---|--------|-------|
| 01 | process-vs-thread-theory | Process vs thread, thread models |
| 02 | os-theory-pcb-context-switch | PCB, context switching, process states, orphan/zombie |
| 03 | filesystem-permissions-links-notes | Indexed allocation, permissions, soft/hard links |

## Notes on intentional bugs
Several files were submitted with syntax errors, typos, or logic bugs. These have been **kept exactly as originally written** rather than silently fixed, so the collection is an honest record of the exam material. Each affected folder's `README.md` documents the specific issues and how to fix them.
