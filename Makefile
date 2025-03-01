CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = mini_shell.c input.c main.c
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