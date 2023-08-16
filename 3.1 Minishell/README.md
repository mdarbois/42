# Minishell

It is a group project to create a basic shell program in C. 
We have to recreate bash --posix comportement for `|` `<` `<<` `>` `>>` builtin `cd`  `pwd` `exit with arg` `env` `unset` `export` `echo with option -n` `$?` and `$`

------

## Supported

- Prompt display
- Command history (up and down arrows)
- System executables available from the environment (`ls``, `cat`, `grep`, etc.)
- Local executables (./minishell)
- Builtin commands :
- `echo` (and option -n)
- `cd` (with only a relative or absolute path)
- `pwd` (no options)
- `export` (no options)
- `unset` (no options)
- `env` (no options or arguments)
- `exit` (with exit number but no other options)
- Pipes `|` which redirect output from one command to input for the next
- Redirections:
  - `>` redirects output
  - `>>` redirects output in append mode
  - `<` redirects input
  - `<<` DELIMITER displays a new prompt, reads user input until reaching DELIMITER, redirects user input to command input (does not update history)
- Environment variables (i.e. `$USER` or `$VAR`) that expand to their values.
- `$?` expands to the exit status of the most recently executed foreground pipeline
- User keyboard signals:
  - ctrl-c displays a new prompt line
  - ctrl-d exits minishell
  - ctrl-\ does nothing
