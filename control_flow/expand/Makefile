expand.out: expand.c
	$(CC) $(CFLAGS) -o $@ $^

debug: CFLAGS = -Wall -g
debug: expand.out

.PHONY: clean
clean:
	rm *.out
