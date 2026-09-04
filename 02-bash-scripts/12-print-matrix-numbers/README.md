# Print Matrix Numbers

## What it does
Prints an increasing sequence of numbers (starting from 0) arranged conceptually as an `r x c` matrix. Rows/columns can be supplied as arguments (`$1 $2`) or, if missing, requested interactively.

## Usage
```bash
chmod +x print_matrix_numbers.sh
./print_matrix_numbers.sh 3 4
# or, interactively:
./print_matrix_numbers.sh
```

## Notes
- Numbers are printed with `echo -n`, all on one line with no separators between them — for a visually separated matrix, add a space after `$num` and an `echo` (newline) at the end of each row.
