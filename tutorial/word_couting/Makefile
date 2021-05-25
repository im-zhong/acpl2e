objects = word_counting.o

word_counting : $(objects)
	gcc -o word_counting.out $(objects)

$(objects) :

.PHONY : clean test

clean :
	rm word_counting.out $(objects) *.tmp

test :
	./test.sh word_counting.c Makefile
