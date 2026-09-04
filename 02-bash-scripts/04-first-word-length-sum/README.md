# Diagonal Word Length Sum

## What it does
Takes a file as an argument and walks through it line by line (line index `i`, starting at 0). On each line, it walks through the words (word index `j`, starting at 0) and, **only when `i == j`** (i.e. word index equals line index — the "diagonal" word), adds that word's character length to a running total `tot`. Prints the final total.

Example: on line 0 it counts the length of word 0, on line 1 it counts the length of word 1, on line 2 the length of word 2, and so on.

## Usage
```bash
chmod +x first_word_length_sum.sh
./first_word_length_sum.sh data.txt
```

## Notes
- Validates that exactly one argument is given and that the path exists (`-e`), otherwise exits with status 1.
- If a line has fewer words than its line index, no word matches `i == j` for that line and nothing is added.
- Despite the original filename suggesting "first word", the logic actually sums a **diagonal** selection of words, not the first word of each line.
