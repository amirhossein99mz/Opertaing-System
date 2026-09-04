# Replace & Pad Lines

## What it does
Takes 6 arguments: `fileIn str1 str2 N str3 fileOut`. For every line in `fileIn`: prints `str3` `N` times, then prints each word (replacing any word equal to `str1` with `str2`), then prints `str3` `N` more times — writing the result to `fileOut`.

## Usage
```bash
chmod +x replace_pad_lines.sh
./replace_pad_lines.sh input.txt old new 2 PAD output.txt
```

## Notes
- Validates that exactly 6 arguments are given and that the input file exists.
- All output for a line is built with `echo -n` (no newline) until the final bare `echo`, which adds the line break — correct approach for building a padded line piece by piece.
