all: calculator.out

CFLAGS = -Wall -g
debug: CC = gcc $(CFLAGS)
debug: all

calculator.out: calculator.o stack.o getop.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

calculator.o: getop.h stack.h 

stack.o: stack.h

getop.o: getop.h

.PHONY: clean
clean:
	rm *.o *.out
	
