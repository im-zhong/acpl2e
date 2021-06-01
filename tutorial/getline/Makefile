all: simple_get_longest_line.out get_longest_line.out

debug: CFLAGS = -g
debug: all

simple_get_longest_line.out: simple_get_longest_line.o
	$(CC) $(CFLAGS) -o $@ $^
simple_get_longest_line.o:

get_longest_line.out: get_longest_line.o
	$(CC) $(CFLAGS) -o $@ $^
get_longest_line.o:

.PHONY: clean
clean:
	rm *.o *.out

