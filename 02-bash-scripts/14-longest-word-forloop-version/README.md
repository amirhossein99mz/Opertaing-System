# Longest Word (for-loop version)

## What it does
Reads a hardcoded `file.txt` in the current directory using `$(cat file.txt)` word-splitting, and finds the single longest word (counted with `wc -c`, which includes the trailing newline `echo` would add if `-n` weren't used — here `echo -n` avoids that). Prints the word and its length.

## Usage
```bash
chmod +x longest_word_forloop.sh
# make sure file.txt exists in the current directory
./longest_word_forloop.sh
```

## Notes
- Filename is hardcoded to `file.txt`.
- Uses `for word in $(cat file.txt)` rather than a `while read` loop — works for simple whitespace-separated text but is less robust than reading line by line (e.g. breaks on filenames with globbing characters).
- On ties, the first longest word found is kept.
