all: simple_get_longest_line.out get_longest_line.out longer_than_80.out \
     trail.out reverse.out detab.out

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

trail.out: trail.o vector.o
	$(CC) $(CFLAGS) -o $@ $^
trail.o: vector.h

reverse.out: reverse.o vector.o
	$(CC) $(CFLAGS) -o $@ $^
reverse.o: vector.h

detab.out: detab.o vector.o
	$(CC) $(CFLAGS) -o $@ $^
detab.o: vector.h

.PHONY: clean
clean:
	rm *.o *.out

