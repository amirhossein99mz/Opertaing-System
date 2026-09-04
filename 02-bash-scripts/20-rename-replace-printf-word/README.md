# Rename & Replace "printf" Word

## What it does
Meant to find every file with a given extension (`$1`) in the current directory, and for each one: create a `.new` copy where every occurrence of the word `printf` is replaced with `write` (all other words copied unchanged), then delete the original file.

## Usage
```bash
chmod +x rename_replace_printf.sh
./rename_replace_printf.sh c
```

## ⚠️ Known issues (kept as originally written) — this script will not run correctly as-is
1. `if[ "$word"=="printf" ]` — missing space after `if`, missing spaces around `==` inside `[ ]`, and `==` isn't valid inside single `[ ]` (POSIX test uses `=`). Should be `if [ "$word" = "printf" ]`.
2. `echo n "$word"` — should be `echo -n "$word"` (missing dash; as written, `echo` prints the literal characters `n <word>`).
3. `done<$file>$new_filename` — redirections should be quoted (`done < "$file" > "$new_filename"`) to handle filenames with spaces/special characters safely.
4. No space is written between words in the output, so the rewritten file will have all words run together on one line per input line — add `echo -n " "` between words if spacing is desired.
5. The script deletes the original file (`rm $file`) — **destructive**; recommend testing on copies first.
