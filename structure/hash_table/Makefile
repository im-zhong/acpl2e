all: main.out

debug: CFLAGS = -Wall -g 
debug: all

main.out : hash.o hash_table.o main.o list.o
	$(CC) -o $@ $^

hash.o: hash.h
list.o: list.h
hash_table.o: hash_table.h hash.h list.h
main.o: hash.h hash_table.h list.h

.PHONY: clean
clean:
	rm *.o *.out

