CC=gcc
CFLAGS=-Wall -ggdb

SRC=$(wildcard *.c)
OBJS=$(SRC:.c=.o)
MAIN=dlinked-list

$(MAIN): $(OBJS)
	$(CC) $(CLFAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(MAIN)

.PHONY: clean
