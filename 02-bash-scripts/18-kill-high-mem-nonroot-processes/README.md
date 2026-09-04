# Kill High-Memory Non-Root Processes

## What it does
Snapshots `ps -aux` into a temp file, then for every process line: extracts the owning user, PID, and (attempts to extract) memory usage, and if the user isn't `root` **and** memory usage is `>= 25`, kills that process with `kill -9`.

## Usage
```bash
chmod +x kill_high_mem_nonroot.sh
./kill_high_mem_nonroot.sh
```
⚠️ **Destructive**: this force-kills matching processes. Review carefully before running, and test on a non-critical system first.

## ⚠️ Known issues (kept as originally written)
1. The loop reads from `tmp.ext`, but the file was written to `tmp.txt` — **typo mismatch** means the `while read` loop reads from a file that was never created, so the loop body never executes as intended. Fix: change `done < tmp.ext` to `done < tmp.txt`.
2. `mem=$(... | cut -d "." -f 1)` cuts on the **entire line** at the first `.` character, not specifically the `%MEM` column — this does not reliably extract the memory percentage field. A correct version should first `cut -d " " -f 4` (the `%MEM` column in `ps aux` output) and then strip the decimal part.
3. `$user != "root"` and numeric comparisons on `$mem` should be quoted / bracketed carefully (e.g. `[[ "$user" != "root" ]]`) to avoid errors on unexpected input.
