# Diagonal Word Length Sum (v2)

## What it does
Same logic as the earlier "diagonal word length sum" script: walks through a file line by line (index `i`), and for each line only counts the length of the word whose position `j` equals `i` (the "diagonal" word), summing these lengths across the whole file.

## Usage
```bash
chmod +x diagonal_word_length_sum.sh
./diagonal_word_length_sum.sh data.txt
```

## Notes
- Validates argument count and file existence before processing.
- Functionally equivalent to the version from the previous batch, written with `[ ]` test syntax and `let` instead of `[[ ]]` and `$(( ))`.
