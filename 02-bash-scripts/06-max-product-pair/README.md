# Max Product Pair

## What it does
For each file given as an argument, reads it line by line, treats every line as a list of numbers, and finds the **pair of numbers (within the same line) whose product is the largest** across the whole file. Prints `<filename> <num1> <num2> <max_product>` for each file processed.

## Usage
```bash
chmod +x max_product_pair.sh
./max_product_pair.sh numbers1.txt numbers2.txt
```

## Notes
- Uses a brute-force double loop (`O(len^2)` per line) comparing every pair of numbers on each line.
- `max` starts at `-999999`, so it assumes all products will be greater than this; won't work correctly for extremely negative products beyond that bound.
- The pair search only compares numbers **within the same line**, not across different lines.
- `for file in $@` (unquoted) will word-split filenames containing spaces; use `"$@"` for safety.
