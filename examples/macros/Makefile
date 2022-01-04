CC = gcc
CFLAGS = -Werror -Wall -Wextra -std=c99 -pedantic -fsanitize=address
LDFLAGS = -lasan

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))
BIN = macros

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

debug: CFLAGS += -g -DVERBOSE_DEBUG
debug: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

.PHONY: clean

clean:
	$(RM) *.o
	$(RM) $(BIN)
