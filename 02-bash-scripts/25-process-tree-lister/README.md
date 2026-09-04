# Process Tree Lister

## What it does (intended)
Reads a list of PIDs from an input file (`$1`), one per line. For each PID, looks it up via `ps -ef`, and prints the PID, its owner, and a list of its child processes' PIDs.

## Usage
```bash
chmod +x process_tree_lister.sh
./process_tree_lister.sh pids.txt
```

## ⚠️ Known issues (kept as originally written)
1. The shebang line is malformed: `#!\bin\bash` uses backslashes instead of forward slashes and is missing the leading `/` — should be `#!/bin/bash`.
2. `echo "$pid [$owner]: $ children"` has a stray space between `$` and `children` — this prints a literal `$` followed by the word `children` rather than the *value* of the `children` variable. Should be `"$pid [$owner]: $children"`.
3. The logic to find children (`ps -ef | ... | cut -d " " -f 2,3 | grep -e "$pid$" | ...`) greps for the PID as a **suffix** anchored at the end of the string (`$pid$`), which can accidentally match a PID that is a substring of a longer number (e.g. PID `12` matching `112`) if not carefully bounded — worth double-checking the exact field/format extracted by `ps -ef` on the target system before relying on this in practice.
4. No `exit 0` is present at the very end after the loop (though the script does have one) — actually present, kept as originally written.
