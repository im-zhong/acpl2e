all: main.out

debug: CFLAGS = -Wall -g
debug: all

main.out: main.o strncmp.o strncpy.o strncat.o
	$(CC) -o $@ $^

main.o:
strncmp.o:
strncpy.o:
strncat.o:

.PHONY: clean
clean:
	rm *.o *.out

