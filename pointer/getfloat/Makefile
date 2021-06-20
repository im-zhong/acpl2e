getfloat.out: getfloat.c
	$(CC) $(CFLAGS) -o $@ $^

debug: CFLAGS = -Wall -g
debug: getfloat.out

.PHONY: clean
clean:
	rm *.out
