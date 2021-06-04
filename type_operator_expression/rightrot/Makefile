all: rightrot.out 

debug: CFLAGS = -Wall -g
debug: all

rightrot.out: rightrot.c
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm *.out
