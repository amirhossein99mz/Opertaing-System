# Record Parser

## What it does
Reads a text file **byte by byte** using low-level `open()`/`read()`/`close()` system calls, splits it into lines, and parses each line into a `record_t` struct containing:
- `i` — an integer
- `s` — a string (max 99 chars)
- `f` — a float

Each line in the input file is expected to have the format:
```
<int> <string> <float>
```

## Usage
```bash
gcc record_parser.c -o record_parser
./record_parser input.txt
```

## Notes
- Uses POSIX I/O (`fcntl.h`, `unistd.h`) instead of buffered `stdio` file access.
- Array size is capped at `N = 100` (max 100 records, max 99 chars per line).
- No bounds checking is performed on `n` or `position` — the input file must not exceed the array limits.
- Parsed records are stored in the `records[]` array but not printed or used further; extend `main()` to make use of them (e.g. print or process).
