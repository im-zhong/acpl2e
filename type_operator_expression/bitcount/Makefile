all: bitcount.out

debug: CFLAGS = -g -Wall
debug: all

bitcount.out: bitcount.c
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm *.out
