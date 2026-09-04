# Swap Columns

## What it does
Reads a file where each line has two space-separated fields (`var1 var2`) and rewrites the file **in place**, swapping the order of the two fields on every line (`var2 var1`).

## Usage
```bash
chmod +x swap_columns.sh
./swap_columns.sh data.txt
```
`data.txt` is modified directly (its original content is overwritten with the swapped columns).

## Notes
- Uses a temporary file (`temp.txt`) and `mv` to safely overwrite the original file.
- If a line has more than two fields, only the first two are captured by `read` (`var2` will contain the rest of the line, `read` does not split further since there are only two variables).
- No argument validation — if `$1` is missing or not a valid file, the script will fail.
