tail.out: tail.o
	$(CC) -o $@ $^

debug: CFLAGS = -Wall -g
debug: tail.out

tail.o:

.PHONY: clean
clean:
	rm *.o *.out
