escape.out: escape.c
	$(CC) $(CFLAGS) -o $@ $^

debug: CFLAGS = -Wall -g
debug: escape.out

.PHONY: clean
clean:
	rm *.out
