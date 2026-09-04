# Remove User Home & Passwd Entry (v2)

## What it does
Given a username as `$1`, looks up the matching line in `/etc/passwd`, extracts the home directory (6th `:`-separated field), removes that home directory, and removes the user's line from `/etc/passwd`.

## Usage
```bash
chmod +x remove_user_home_passwd_v2.sh
sudo ./remove_user_home_passwd_v2.sh someuser
```
⚠️ **Destructive**: deletes a home directory and rewrites `/etc/passwd`. Only run with a full understanding of what it does, and ideally on a test system / VM.

## ⚠️ Known issue (kept as originally written)
`[ ! -ne $1 ]` in the argument-validation line uses `-ne` (a **numeric** "not equal" comparator) on `$1`, which is a username string, not a number — this is a leftover/copy-paste mistake from a numeric check and will likely error out or behave unpredictably for non-numeric usernames. It should simply be removed, or replaced with a check like `[ -z "$1" ]`.

## Notes
- Uses `$?` right after `grep` to detect whether a match was found (`grep` exits `1` when no lines match) — correct pattern, but must run immediately after the `grep`/pipeline with no intervening commands (as it does here).
- `mv "tmp.txt" $FILE` should ideally quote `$FILE` too, for consistency/safety.
