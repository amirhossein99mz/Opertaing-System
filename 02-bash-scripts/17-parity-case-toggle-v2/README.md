# Parity Case Toggle (v2)

## What it does
Reads a file given as `$1`. For each line: if the word count is **odd**, prints it lowercased; if **even**, prints it uppercased.

## Usage
```bash
chmod +x parity_case_toggle_v2.sh
./parity_case_toggle_v2.sh myfile.txt
```

## Notes
- This is functionally the **opposite convention** of `14-even-odd-case-toggle` (which uppercases on *even* count) but with matching logic here (odd → lowercase, even → uppercase) — same rule, just written with `[ ]`/`tr '[:upper:]' '[:lower:]'` POSIX character classes instead of `[[ ]]`/`a-z A-Z` ranges. Both scripts implement the same "even words → uppercase" rule.
- Validates argument count and file existence before processing.
