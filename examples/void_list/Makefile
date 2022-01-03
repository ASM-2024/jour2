CC = gcc
CFLAGS = -Werror -Wall -Wextra -std=c99 -pedantic -fsanitize=address

SRC = main.c list.c
OBJ = $(patsubst %.c,%.o,$(SRC))
BIN = list

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

debug: CFLAGS += -g
debug: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

.PHONY: clean

clean:
	$(RM) *.o
	$(RM) $(BIN)
