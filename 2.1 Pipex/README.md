# Pipex

Pipex is a project that re-creates in C the way two commands are piped together via `|` in the shell

----

Description:

The program pipex should repeat the behaviour of the  shell command

$> < file1 cmd1 | cmd2 > file2

and be executed as follows:

$> ./pipex file1 cmd1 cmd2 file2

All errors like: wrong commands, permission to files and etc, need be handle.
