# ifdef/endif Preprocessor

## What it does (intended)
A tiny, C-preprocessor-like filter: reads an input file (`$2`) line by line. Normal lines are copied straight to the output (also `$2` — see issue below). When a line starts with `ifdef <flag>`, the following lines (until a line starting with `endif`) are only kept in the output if `<flag>` equals `1`.

## Usage
```bash
chmod +x ifdef_endif.sh
./ifdef_endif.sh input.c output.txt
```

## ⚠️ Known issues (kept as originally written) — this script will not run correctly as-is
1. `[ #$ -lt 2 ]` — `#$` is not valid syntax for "number of arguments"; it should be `$#` (the variable name and the `#` are swapped).
2. `[ ! -f $1 ]` checks that `$1` (the input file) exists, but the script actually **reads from `$2`** (`done < $2`) — the source/destination arguments seem swapped somewhere; based on the usage comment this needs a consistent convention (e.g. input as `$1`, output as `$2`, and read `done < "$1"`).
3. `"$first"=="ifdef"` / `"$flag"==1` — same issue as in script 28: no spaces around `==`/`=` inside `[ ]`, and single `[ ]` should use `=` not `==`. Should be `[ "$first" = "ifdef" ]`.
4. `if[ "$flag"==1 ]` is also missing the space after `if`.
5. Because the script reads from `$2` and also appends (`>>`) to `$2`, it reads and writes the **same file** in the same loop — this is unsafe and can produce corrupted or infinite behavior. Input and output should be different files (or written to a temp file first, then moved).
