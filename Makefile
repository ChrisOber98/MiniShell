CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = main.o mini_shell.o

minishell: $(OBJ)
	$(CC) $(CFLAGS) -o minishell $(OBJ)

main.o: main.c mini_shell.h
	$(CC) $(CFLAGS) -c main.c

minishell.o: mini_shell.c mini_shell.h
	$(CC) $(CFLAGS) -c minishell.c

clean:
	rm -f minishell $(OBJ)

run:
	./minishell