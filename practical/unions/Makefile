CC=gcc
CFLAGS=-Wall -Wextra  -std=c99 -pedantic

SRC=$(wildcard *.c)

main:
	$(CC) $(CFLAGS) $(SRC) -o main

CFLAGS += -g -fsanitize=address

debug:
	$(CC) $(CFLAGS) $(SRC) -o debug

clean:
	$(RM) main
	$(RM) debug
