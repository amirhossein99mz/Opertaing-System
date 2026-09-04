# Path Info Lister

## What it does
Accepts one or more file/directory paths as arguments and prints info for each:
- **If it's a regular file**: name, size (bytes), whether it's readable (`r`/`-`), and whether it's writable (`w`/`-`) — parsed from `ls -l`.
- **If it's a directory**: the directory's basename and the count of subdirectories it directly contains.
- **If it's neither** (doesn't exist, special file, etc.): skipped silently.

## Usage
```bash
chmod +x path_info_lister.sh
./path_info_lister.sh file1.txt /some/dir file2.log
```

## Notes
- Relies on parsing `ls -l` output (fields via `cut`), which is fragile — filenames with spaces or unusual characters can break the field extraction. A stat-based approach (`stat -c`) would be more robust.
- `read_perm`/`write_perm` only reflect the **owner's** permission bits (characters 2 and 3 of the `ls -l` permission string).
- The trailing `exit 0 0` passes an extra argument to `exit`, which is harmless (bash ignores extras) but non-standard; `exit 0` alone is preferred.
