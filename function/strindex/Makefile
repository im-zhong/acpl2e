strindex.out: strindex.c
	$(CC) $(CFLAGS) -o $@ $^

debug: CFLAGS = -Wall -g
debug: strindex.out

.PHONY: clean
clean:
	rm *.out
