getint.out: getint.c
	$(CC) $(CFLAGS) -o $@ $^

debug: CFLAGS = -Wall -g
debug: getint.out

.PHONY: clean
clean:
	rm *.out
