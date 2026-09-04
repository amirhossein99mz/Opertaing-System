# Remove User Home & Passwd Entry (v1 — heavily buggy draft)

## What it does (intended)
Given a username, is meant to look up the user's home directory in `/etc/passwd`, delete that home directory, and remove the user's line from the passwd file.

## ⚠️ Known issues (kept as originally written) — this script will not run correctly as-is
This looks like an early, broken draft — compare with `30-remove-user-home-passwd-v2` for a more complete attempt at the same task. Issues:
1. Missing `#!` at the very start of the shebang line (`!/bin/bash` instead of `#!/bin/bash`) — the file won't be recognized as an executable script header.
2. `FILE="etc/passwd"` — missing the leading `/`, should be `/etc/passwd`.
3. `echo $FILE | grep -e $username` greps the **literal string** `"etc/passwd"` for the username, instead of grepping the **contents** of the file (`cat "$FILE" | grep ...` or `grep "$username" "$FILE"`) — this can never find a match.
4. `tr -d ":" -f 6` — `tr` doesn't support a `-f` (field) option; extracting the 6th colon-separated field requires `cut -d ":" -f 6`, not `tr`.
5. `rm -rf home` deletes a literal directory named `home` in the current directory, not the path stored in the `$home` variable — missing the `$`.
6. `$file` (lowercase) is used later but was never defined — only `$FILE` (uppercase) was set; inconsistent variable naming.
7. No `exit 0` at the end and no validation that the username was actually found before proceeding to delete things.

**This script is destructive by design (deletes a directory and edits `/etc/passwd`) — never run it as-is.**
