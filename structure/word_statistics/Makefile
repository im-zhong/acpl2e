all: word_statistics.out

debug: CFLAGS = -g -Wall
debug: all

word_statistics.out: word_statistics.o list.o tree.o getword.o
	$(CC) -o $@ $^

list.o: list.h
tree.o: list.h tree.h
getword.o: getword.h
word_statistics.o: list.h tree.h getword.h

.PHONY: clean
clean:
	rm *.o *.out

