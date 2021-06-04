all: invert.out

debug: CFLAGS = -g
debug: all

invert.out: invert.c
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm *.out
