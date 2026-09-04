# Filesystem: Indexed Allocation, Permissions & Links — Theory Notes

This folder contains theory notes only (no source code), kept from the original exam material.

## Indexed allocation in UNIX/Linux
- A **directory block** contains directory entries, each mapping a filename to an **i-node** (which acts as a hard link).
- A **data block** contains the actual file data that gets read.
- Every file has **one i-node**, which contains pointers to its data block(s) plus other metadata.

## Permission string format
```
- --- --- ---
1  2   3   4
```
- **1**: file type — `-` for a regular file, `d` for a directory.
- **2**: owner permissions.
- **3**: group permissions.
- **4**: other (everyone else) permissions.
- `r` = read, `w` = write, `x` = execute.

## Common commands
- `chmod 755 file` — change a file's permission bits.
- `chgrp group file` — change a file's group.
- `chown user file` — change a file's owner.

## Soft links vs hard links
- `ln -s file link` — creates a **soft (symbolic) link**: a pointer to the file **by its path**. If the original file is removed, the soft link becomes broken.
- `ln file link` — creates a **hard link**: a second directory entry pointing to the **same i-node** as the original. If the original file is removed, the hard link still works (the data persists as long as at least one hard link references the i-node).

### Worked example (from the notes)
Given `s1` = soft link to `s`, `h1` = hard link to `h`, `d` = directory:
- `cp s1 s2` — copies the *content* that `s1` points to into a new regular file `s2`.
- `cp h1 h2` — copies the *content* that `h1` points to into a new regular file `h2`.
- `rm s` — removes `s`; `s1` becomes a **broken** soft link.
- `rm h` — removes `h`; `h1` remains **accessible** (still points to valid data via the shared i-node), as long as other hard links to that i-node exist.
- `mkdir d/d1` — creates directory `d1` inside `d`.
- `mkdir d/d2` — creates directory `d2` inside `d`.
