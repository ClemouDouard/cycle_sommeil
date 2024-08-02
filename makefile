CC=gcc
CFLAGS=-Wall -Wextra
SRC=src/
BIN=bin/

main: $(SRC)cycle_sommeil.c
	$(CC) $(CFLAGS) -o $(BIN)$@ $^

clean:
	rm -rf bin/*