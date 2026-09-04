# Longest Word Finder

## What it does
Reads a fixed file called `file.txt` (in the current directory) line by line, splits each line into words, and finds the **single longest word** in the whole file. Prints it (without a trailing newline) to standard output.

## Usage
```bash
chmod +x longest_word_finder.sh
# make sure file.txt exists in the current directory
./longest_word_finder.sh
```

## Notes
- The input filename is hardcoded to `file.txt`; edit the `FILE=` variable to point elsewhere.
- If multiple words tie for the longest length, the **first one found** is kept (`-gt`, not `-ge`).
- Word splitting uses the default `IFS` (spaces/tabs/newlines), so punctuation attached to a word counts as part of its length.
