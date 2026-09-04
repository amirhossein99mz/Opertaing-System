# Path Info Lister (v2)

## What it does
Accepts multiple paths and, for each:
- **Regular file**: prints `FILE:<path>,<size>,<R if readable>,<W if writable>`.
- **Directory**: prints `<path>:<number of direct subdirectories>`.

## Usage
```bash
chmod +x path_info_lister_v2.sh
./path_info_lister_v2.sh file1.txt /some/dir file2.log
```

## Notes
- Uses `[ -r ]` / `[ -w ]` test operators directly (checks actual effective readability/writability for the current user) instead of parsing `ls -l` permission characters — more reliable than the batch-1 version.
- `for path in $*` is unquoted, so paths with spaces will be word-split; prefer `"$@"`.
- Paths that are neither a file nor a directory (broken symlinks, etc.) are silently skipped.
