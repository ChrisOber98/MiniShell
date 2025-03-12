CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g
SRC = mini_shell.c input.c main.c builtins.c executor.c linked_list.c history.c
OBJ = $(SRC:.c=.o)
TARGET = mini_shell

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)