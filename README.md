MiniShell - A Lightweight Unix-like Shell

Overview

MiniShell is a minimal Unix-like shell written in C, designed for learning and exploring system calls, process management, and shell internals. This project implements fundamental shell features, including command execution, I/O redirection, and piping.

Features

- Execute external commands using fork() and execvp()

- Built-in commands (cd, exit)

- Input and output redirection (>, <)

- Piping (|) for chaining commands

- Error handling and basic command parsing

Installation

Clone the repository and compile the source code:

git clone https://github.com/yourusername/minishell.git
cd minishell
make

Usage

Run the shell with:

./minishell

Then, enter commands as you would in a standard shell.