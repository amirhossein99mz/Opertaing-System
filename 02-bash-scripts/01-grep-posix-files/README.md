# Grep POSIX Files

## What it does
Scans the **current directory only** (no subdirectories) for `.c` files. For every `.c` file that contains the word `POSIX`, it prints (`cat`) the full content of that file to standard output.

## Usage
```bash
chmod +x grep_posix_files.sh
./grep_posix_files.sh
```
Run it from inside the directory you want to scan.

## Notes
- `find . -mindepth 1 -maxdepth 1` restricts the search to the top-level directory (non-recursive).
- `grep -q "POSIX"` silently checks for a match without printing it.
- Filenames with spaces could break the `for` loop (word-splitting); use `find ... -print0 | while read -r -d '' file; do ... done` for a more robust version if needed.
