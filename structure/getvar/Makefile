all: getvar.out

debug: CFLAGS = -Wall -g
debug: all

getvar.out: token.o list.o tree.o getvar.o
	$(CC) -o $@ $^

token.o: token.h
list.o: list.h
tree.o: tree.h list.h
getvar.o: token.h tree.h list.h

.PHONY: clean
clean:
	rm *.o *.out *.tmp

.PHONY: test
test:
	cat *.h *.c | ./getvar.out 1 > result.tmp; \
	diff golden result.tmp

