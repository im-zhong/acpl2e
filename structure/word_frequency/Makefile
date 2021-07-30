all: word_frequency.out

debug: CFLAGS = -g -Wall
debug: all

word_frequency.out: list.o tree.o getword.o word_frequency.o
	$(CC) -o $@ $^

list.o: list.h
tree.o: list.h tree.h
getword.o: getword.h
word_frequency.o: list.h tree.h getword.h

.PHONY: clean
clean:
	rm *.o *.out

