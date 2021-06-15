atoi.out: atoi.c
	$(CC) $(CFLAGS) -o $@ $^

debug: CFLAGS = -Wall -g
debug: atoi.out

.PHONY: clean
clean:
	rm *.out

