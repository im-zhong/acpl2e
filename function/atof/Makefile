atof.out: atof.c
	gcc $(CFLAGS) -o $@ $^ -lm

debug: CFLAGS = -Wall -g
debug: atof.out

.PHONY: clean
clean:
	rm *.out
