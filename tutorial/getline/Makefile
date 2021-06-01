all: simple_get_longest_line.out get_longest_line.out longer_than_80.out

debug: CFLAGS = -g
debug: all

simple_get_longest_line.out: simple_get_longest_line.o
	$(CC) $(CFLAGS) -o $@ $^
simple_get_longest_line.o:

get_longest_line.out: get_longest_line.o
	$(CC) $(CFLAGS) -o $@ $^
get_longest_line.o:

longer_than_80.out: longer_than_80.o vector.o
	$(CC) $(CFLAGS) -o $@ $^
longer_than_80.o vector.o: vector.h

.PHONY: clean
clean:
	rm *.o *.out

