# Tab File Summarizer

## What it does
Given a directory, finds every `.tab` file smaller than 100MB. For each one (skipping the header line), it reads rows of `product quantity unit_price`, computes `quantity * unit_price` per row, and accumulates the total per product. Writes the results (`product total`) into a new file with the same name but `.sum` extension.

## Usage
```bash
chmod +x tab_file_summarizer.sh
./tab_file_summarizer.sh /path/to/directory
```

## ⚠️ Known issue (kept as originally written)
The redirection `done < < (tail -n +2 "$file")` has a **stray space** between the two `<` characters. In real Bash, this must be written with no space as process substitution: `done < <(tail -n +2 "$file")`. As written, Bash will try to interpret `<` `(tail ...)` as separate tokens and fail (or behave unexpectedly). Fix by removing the space before running.

## Notes
- `declare -A dict` (associative array) is redeclared fresh inside the loop for each file, so totals don't leak between files — correct behavior.
- `-size -100M` excludes files 100MB or larger from processing.
- Assumes the first line of each `.tab` file is a header (skipped via `tail -n +2`).
