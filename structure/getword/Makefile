getword.out: getword.o
	$(CC) -o $@ $^

debug: CFLAGS = -Wall -g
debug: getword.out

getword.o:

.PHONY: clean
clean:
	rm *.o *.out


