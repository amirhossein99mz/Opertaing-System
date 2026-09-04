# Even/Odd Case Toggle

## What it does
Reads a file (path passed as `$1`) line by line. If a line has an **even** number of words, it's printed in UPPERCASE; if **odd**, it's printed in lowercase.

## Usage
```bash
chmod +x even_odd_case_toggle.sh
./even_odd_case_toggle.sh myfile.txt
```

## Notes
- Word count via `wc -w`.
- Uses `tr 'a-z' 'A-Z'` / `tr 'A-Z' 'a-z'` for case conversion (ASCII-range only, not locale-aware — fine for plain English text).
