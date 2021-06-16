itob.out: itob.c
	$(CC) $(CFLAGS) -o $@ $^

debug: CFLAGS = -Wall -g
debug: itob.out

.PHONY: clean
clean:
	rm *.out
