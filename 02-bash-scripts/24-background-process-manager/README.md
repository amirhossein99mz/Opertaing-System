# Background Process Manager

## What it does (intended)
Takes a mode (`start` or `stop`) as `$1` and a file of commands as `$2`. In `start` mode, launches every command listed in the file as a background job (`&`). In `stop` mode, finds the PID of each running command (via `ps`/`grep`) and kills it.

## Usage
```bash
chmod +x background_process_manager.sh
./background_process_manager.sh start commands.txt
./background_process_manager.sh stop commands.txt
```

## ⚠️ Known issue (kept as originally written)
`[ $1=="start" ]` and `[ $1=="stop" ]` are missing spaces around `==` and use `==` inside single `[ ]` (not portable/valid POSIX test syntax) — as written, `$1==start` is treated as one single (usually non-empty, always "true") string rather than an actual comparison, so the `start` branch would likely always execute regardless of the real value of `$1`. Should be `[ "$1" = "start" ]` and `[ "$1" = "stop" ]`.

## Notes
- `"$cmd" &` runs each line of the command file as a background job — if a line contains multiple words (e.g. `sleep 100`), quoting it as a single string will fail; using `$cmd &` (unquoted) or `eval "$cmd" &` would handle command-with-arguments cases better.
- The `stop` logic identifies processes to kill by grepping `ps aux` for the command text, which can accidentally match unrelated processes containing the same substring — use more specific matching (e.g. exact command + arguments) in production use.
