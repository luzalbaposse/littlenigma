CC=c99
CFLAGS=-Wall -Wextra -pedantic -O0 -ggdb
LIBS=-lm
all: main.out enigma.out

main.out: utils.c main.c
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

enigma.out: utils.c enigma.c
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

.PHONY: clean
clean:
	rm -f *.o *.out