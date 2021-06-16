itoa.out: itoa.c
	$(CC) $(CFLAGS) -o $@ $^

debug: CFLAGS = -Wall -g
debug: itoa.out

.PHONY: clean
clean:
	rm *.out
