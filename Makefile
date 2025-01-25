
CC = gcc
CFLAGS = -Wall -g


TARGET = program


SRC = custom_shell.c


OBJ = $(SRC:.c=.o)


all: $(TARGET)


$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ) $(TARGET)


run: $(TARGET)
	./$(TARGET)

