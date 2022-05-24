CC=gcc
CFLAGS=-I.
DEPS=main.c header.h

OBJ := general.o
OBJ += minimax.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

minimax: $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o minimax